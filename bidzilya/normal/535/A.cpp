#include <bits/stdc++.h>
using namespace std;

const string kLastDigit[] = {"zero", "one", "two", "three",
                              "four", "five", "six", "seven", "eight", "nine"};
                              
const string kTwoDigits[] = {"ten", "eleven", "twelve", "thirteen", "fourteen", 
                               "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"};

const string kFirstDigit[] = {"twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int x;
    cin >> x;
    if (x < 10) {
        cout << kLastDigit[x] << endl;
    } else if (x < 20) {
        cout << kTwoDigits[x - 10] << endl;
    } else if (x % 10 == 0) {
        cout << kFirstDigit[x / 10 - 2] << endl;
    } else {
        cout << kFirstDigit[x / 10 - 2] << "-" << kLastDigit[x % 10] << endl;
    }
    
    
    return 0;
}