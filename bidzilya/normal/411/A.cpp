#include <string>
#include <iostream>
using namespace std;

int main() 
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string s;
    cin >> s;
        
    if (s.length() < 5) {
        cout << "Too weak" << endl;
        return 0;
    }
    bool is_big = false;
    bool is_digit = false;
    bool is_small = false;
    for (int i = 0; i < s.length(); ++i)    
        if (s[i] >= 'a' && s[i] <= 'z')
            is_small = true;
        else if (s[i] >= 'A' && s[i] <= 'Z')
            is_big = true;
        else if (s[i] >= '0' && s[i] <= '9')
            is_digit = true;
    if (is_small && is_big && is_digit) {
        cout << "Correct" << endl;
    } else {
        cout << "Too weak" << endl;
    }
    return 0;
}