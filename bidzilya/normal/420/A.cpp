#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <queue>
   
#include <cassert>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <bitset>
using namespace std;

bool good_char(char c)
{
    return c == 'A' || c == 'H' || c == 'I' ||
        c == 'M' || c == 'O' || c == 'T' ||
        c == 'U' || c == 'V' || c == 'W' ||
        c == 'X' || c == 'Y';
}

int main()
{
    string s;
    cin >> s;
 
    for (int i = 0; i < (int) s.length(); ++i)
        if (!good_char(s[i])) {
            cout << "NO" << endl;
            return 0;
        }
    
    string t(s);
    
    reverse(s.begin(), s.end());
    
    if (s == t) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
            
    
    return 0;
}