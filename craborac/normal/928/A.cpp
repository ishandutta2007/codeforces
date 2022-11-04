#include <bits/stdc++.h>

using namespace std;

string mem(string s)
{
    for (int i = 0; i < (int)s.size(); i++)
    {
        if ('A' <= s[i] && s[i] <= 'Z')
        {
            s[i] += 'a' - 'A';
        }
        if (s[i] == 'i' || s[i] == '1')
            s[i] = 'l';
        if (s[i] == '0')
            s[i] = 'o';
    }
    return s;
}

int main()
{
    srand(3228);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    string s;
    cin >> s;
    s = mem(s);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string t;
        cin >> t;
        t = mem(t);
        if (s == t)
        {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}