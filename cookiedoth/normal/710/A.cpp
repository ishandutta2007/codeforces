#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int flag = 0;
    cin >> s;
    if (s[0] == 'a'||s[0] == 'h') flag++;
    if (s[1] == '1'||s[1] == '8') flag++;
    if (flag == 0) cout << 8;
    if (flag == 1) cout << 5;
    if (flag == 2) cout << 3;
    return 0;
}