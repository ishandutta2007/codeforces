#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 8;
int a[M];
int big[1 << M];
int e[1 << M];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n, m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[j];
        }
        for (int s = 1; s < (1 << m); s++)
        {
            int mn = (1 << 30);
            for (int j = 0; (1 << j) <= s; j++)
            {
                if (s & (1 << j))
                {
                    mn = min(mn, a[j]);
                }
            }
            big[s] = max(big[s], mn);
            if (big[s] == mn)
            {
                e[s] = i;
            }
        }
    }
    int sol = 0, es = 1;
    for (int s = 1; s + 1 < (1 << m); s++)
    {
        sol = max(sol, min(big[s], big[(1 << m) - 1 - s]));
        if (sol == min(big[s], big[(1 << m) - 1 - s]))
        {
            es = s;
        }
    }
    if (e[es] == 0 || e[(1 << m) - 1 - es] == 0)
    {
        int x = max(e[es], e[(1 << m) - 1 - es]);
        cout << x << " " << x << "\n";
        return 0;
    }
    cout << e[es] << " " << e[(1 << m) - 1 - es] << "\n";
}