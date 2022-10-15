#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    string s, t;
    cin >> s;
    int suf = 0, n = (int) s.size();
    while (suf < n)
    {
        char mx = 'a';
        for (int i = suf; i < n; i++)
        {
            mx = max(mx, s[i]);
        }
        int last_mx;
        for (int i = suf; i < n; i++)
        {
            if (s[i] == mx)
            {
                last_mx = i;
                t += mx;
            }
        }
        suf = last_mx + 1;
    }
    cout << t << "\n";
    return 0;
}