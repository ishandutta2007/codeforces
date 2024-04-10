/**************
*             *
*    HELLO    *
*             *
**************/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int f;
    cin >> f;
    cin >> s;
    if (s[3] > '5') {
        s[3] = '5';
    }
    if (f == 12) {
        if (s[1] == '0') {
            if (s[0] == '0') {
                s[1] = '1';
            }
            else {
                if (s[0] > '1') {
                    s[0] = '1';
                }
            }
        }
        else {
            if ((s[0] == '1')&&(s[1] > '2')) {
                s[1] = '1';
            }
            else {
                if (s[0] > '1') {
                    s[0] = '0';
                }
            }
        }
    }
    if ((s[0] > '2')&&(f == 24)) {
        s[0] = '0';
    }
    if ((s[0] == '2')&&(s[1] > '3')&&(f == 24)) {
        s[0] = '0';
    }
    cout << s;
    return 0;
}