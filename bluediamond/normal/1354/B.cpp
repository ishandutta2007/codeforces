#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

int f[4];

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
        int n = (int) s.size();
        int sol = 0, j = 0;
        for (int i = 0; i < n; i++)
        {
            int x = s[i] - '0';
            f[x]++;
            while (1)
            {
                int y = s[j] - '0';
                f[y]--;
                if (f[1] > 0 && f[2] > 0 && f[3] > 0)
                {
                    j++;
                    continue;
                }
                else
                {
                    f[y]++;
                    break;
                }
            }
            if (f[1] > 0 && f[2] > 0 && f[3] > 0)
            {
                int len = i - j + 1;
                if (sol == 0)
                {
                    sol = len;
                }
                else
                {
                    sol = min(sol, len);
                }
            }
        }
        f[1] = f[2] = f[3] = 0;
        cout << sol << "\n";
    }
}