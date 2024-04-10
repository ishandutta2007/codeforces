#include <bits/stdc++.h>

using namespace std;

typedef long long ll;


int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s;
        cin >> s;
        set<int> one;
        set<int> two;
        set<int> tg;
        set<int> all;
        for (int i = 0; i + 2 < (int) s.size(); i++)
        {
            if (s[i] == 'o' && s[i + 1] == 'n' && s[i + 2] == 'e')
            {
                one.insert(i);
            }
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o')
            {
                two.insert(i);
            }
        }
        for (int i = 0; i + 4 < (int) s.size(); i++)
        {
            if (s[i] == 't' && s[i + 1] == 'w' && s[i + 2] == 'o' && s[i + 3] == 'n' && s[i + 4] == 'e')
            {
                tg.insert(i);
            }
        }
        for (auto &x : tg)
        {
            two.erase(x);
            one.erase(x + 2);
        }
        for (auto &x : tg)
        {
            all.insert(x + 2);
        }
        for (auto &x : one)
        {
            all.insert(x + 1);
        }
        for (auto &x : two)
        {
            all.insert(x + 1);
        }
        cout << (int) all.size() << "\n";
        for (auto &x : all)
        {
            cout << x + 1 << " ";
        }
        cout << "\n";
    }
}