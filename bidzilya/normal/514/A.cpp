#include <iostream>
using namespace std;


void Change(char& c, bool need_check)
{
    if (need_check && c == '9') {
        return;
    }
    char ci = '9' - c + '0';
    if (ci < c) {
        c = ci;
    }
}

int main()
{
    ios_base::sync_with_stdio(false);

    string s;
    cin >> s;
    for (int i = 0; i < (int) s.length(); ++i) {
        Change(s[i], i == 0);
    }

    cout << s << endl;

    return 0;
}