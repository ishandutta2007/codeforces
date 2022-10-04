#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int i, flag = 0;
    cin >> s;
    for (i = 0; i<s.length(); i++) {
        if (s[i] == 'a'&&flag > 0) break;
        if (s[i] != 'a') {
            flag++;
            s[i]--;
        }
    }
    if (flag == 0) s[s.length()-1] = 'z';
    cout << s;
    return 0;
}