/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int t;

bool palind (string &s)
{
    for(int i = 0; i < (int)s.size(); i++)
        if(s[i] != s[(int)s.size() - 1 - i])
            return false;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        s += 'a';
        if(palind(s) == false)
        {
            cout << "YES\n" << s << "\n";
            continue;
        }
        s.pop_back();
        s = 'a' + s;
        if(palind(s) == false)
        {
            cout << "YES\n" << s << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}