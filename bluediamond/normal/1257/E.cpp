#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = (int) 2e5 + 7;
int n, k1, k2, k3, a[N], b[N], c[N];
int f[3][N];

int get(int x, int l, int r)
{
        return f[x][r] - f[x][l - 1];
}

int x[N], y[N];

int main()
{
        ios::sync_with_stdio(0);
        cin.tie(0);

        cin >> k1 >> k2 >> k3;
        n = k1 + k2 + k3;
        for (int i = 1; i <= k1; i++)
        {
                cin >> a[i];
                f[0][a[i]]++;
        }
        for (int i = 1; i <= k2; i++)
        {
                cin >> b[i];
                f[1][b[i]]++;
        }
        for (int i = 1; i <= k3; i++)
        {
                cin >> c[i];
                f[2][c[i]]++;
        }

        for (int x = 0; x < 3; x++)
        {
                for (int i = 1; i <= n; i++)
                {
                        f[x][i] += f[x][i - 1];
                }
        }

        int ans = 0;

        for (int i = 0; i <= n + 1; i++)
        {
                x[i] = k2 + get(0, 1, i) - get(1, 1, i);
                if (i >= 1)
                {
                        x[i] = max(x[i - 1], x[i]);
                }
        }
        for (int i = 0; i <= n + 1; i++)
        {
                y[i] = get(2, i, n) - get(1, i, n);
                if (i >= 1)
                {
                        ans = max(ans, x[i - 1] + y[i]);
                }
        }


        cout << n - ans << "\n";
}