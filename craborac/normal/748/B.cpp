#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    set<pair<char, char> > se;
    set<char> mas[26];
    for (int i = 0; i < s.size(); i++)
    {
        mas[s[i] - 'a'].insert(t[i]);
        mas[t[i] - 'a'].insert(s[i]);
        if (s[i] != t[i])
            se.insert({min(s[i], t[i]), max(s[i], t[i])});
    }
    for (int i = 0; i < 26; i++)
        if (mas[i].size() > 1)
        {
            cout << -1 << endl;
            return 0;
        }
    cout << se.size() << endl;
    for (auto p : se)
        cout << p.first << " " << p.second << endl;
    return 0;
}