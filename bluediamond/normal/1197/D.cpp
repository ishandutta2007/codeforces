#include <bits/stdc++.h>

using namespace std;

const long double inf = 1e18;
int n;
long double m, k;
long double s;
long double cur[10];
int df[10][10];

int main()
{
        ios_base::sync_with_stdio(false);
        cin.tie(0), cout.tie(0);

        cin >> n >> m >> k;
        for (int i = 0; i < m; i++)
                cur[i] = -inf;
        for (int a = 0; a < m; a++)
                for (int b = 0; b < m; b++)
                {
                        df[a][b] = a - b;
                        while (df[a][b] % (int) m)
                                df[a][b]++;
                        df[a][b] -= (a - b);
                }
        long double s = 0, ans = 0;
        cur[0] = 0;
        for (int i = 1; i <= n; i++)
        {
                int x;
                cin >> x;
                s += x;
                int a = i % (int) m;
                for (int b = 0; b < m; b++)
                        ans = max(ans, cur[b] + s - (long double) (i + df[a][b]) / m * k);
                cur[a] = max(cur[a], -s + (long double) i / m * k);
        }
        cout << fixed << setprecision(0) << ans << "\n";
        return 0;
}