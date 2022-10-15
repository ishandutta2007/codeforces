#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        string s, t, sa;
        cin >> s >> t;
        sa = s;
        sort(sa.begin(), sa.end());
        for (int i = 0; i < (int) s.size(); i++)
        {
            if (s[i] != sa[i])
            {
                for (int j = (int) s.size() - 1; j > i; j--)
                {
                    if (sa[i] == s[j])
                    {
                        swap(s[i], s[j]);
                        break;
                    }
                }
                break;
            }
        }
        if (s < t)
        {
            cout << s << "\n";
        }
        else
        {
            cout << "---\n";
        }
    }
}