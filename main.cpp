/*
   Finds the numbers of even odd negative and pos integers
 */

#include <iostream>
#include <iostream>
#include <cmath>
#include <iomanip>
#include <stdlib.h>
#include <fstream>
#include <cstdlib>
using namespace std;

// function prototype
void program6_2();

int main()
{
    program6_2(); // call program 6_2
    return 0;
}
// program 2 sums a sequence of integers

void program6_2()
{
    // create variables
    int first_num, number_stored,
            neg = 0,
            pos = 0,
            even_pos = 0,
            odd_pos = 0,
            zero = 0,
            pos_sum = 0;
    double average = 0, sum_of_positive_ints = 0 , total = 0;


    //creates or opens read and write files
    ifstream infile;
    ofstream outputfile;
    infile.open("program2read.txt");
    outputfile.open("program2write.txt");

    //check to make sure there is an open file, if no file is open program terminates
    if (!infile.is_open())
    {
        exit(EXIT_FAILURE);
    }

    //gets the first num in the file
    infile >> first_num;

    //Check to to see if first num is positive
    if (first_num >= 0)
    {
        // goes through all the values in the read file
        for (int count = 0; count <= first_num - 1; count++)
        {
            // store all integers in variable called store_nums
            infile >> number_stored;

            if (infile.fail()) // used to validate data in the file
            {
              infile.clear(); // used to avoid reading the same line over and over again
              continue; // then go to the next line
            }

            if (number_stored < 0) // check for negative ints
                neg++;

            else if(number_stored > 0) // check for positive ints
            {
              pos_sum += number_stored; // starts adding up positive ints
                pos++;

                if(number_stored % 2 == 0) // determine is number is even
                    even_pos++;

                else
                    odd_pos++;
            }
            else
                zero++; // if number is neither negative or positive then its 0

        }
        //Calculates average which is sum / numbers read
        //average = sum_of_positive_ints / (first_num);
        if (pos == 0)
            average = 0.0;

        else
            average = (double)pos_sum / pos;

        //check if dividing by 0
        //if(sum_of_positive_ints / (first_num) == 0)
       //     average = 0.00;


        // output
        outputfile << setprecision(2) << fixed << showpoint;
        outputfile << "[The Average is " << average << "]" << endl;
        outputfile << "\n";
        outputfile << "[" << even_pos << " Positive even numbers]" << endl;
        outputfile << "[" << odd_pos << " Positive odd numbers]" << endl;
        outputfile << "[" << neg << " integers less than zero]" << endl;
        outputfile << "[ZERO occurs " << zero << " times in the list of integers]" << endl;
    }
    else
        outputfile << "Program terminated First number on file is negative " << first_num;


    //close files and restart program
    outputfile.close();
    infile.close();

}

