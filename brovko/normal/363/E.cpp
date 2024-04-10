#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;
const ld eps = 1e-5;

int n, m, r, a[505][505], ps[505][505], c[505][505], Max[505][505], kMax[505][505], ans, k, R[505];

void update(int l, int r, int s)
{
    int x = Max[l][r] + s, y = kMax[l][r];

    if(y <= 0)
        return;

    if(ans == x)
        k += y;

    if(x > ans)
    {
        ans = x;
        k = y;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> r;

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            ps[i][j + 1] = ps[i][j] + a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            c[i][j] = -1e18;

    for(int i = r; i < n - r; i++)
        for(int j = r; j < m - r; j++)
        {
            c[i][j] = 0;

            for(int d = -r; d <= r; d++)
            {
                int x = sqrt(r * r - d * d + eps);
                c[i][j] += ps[i - d][j + x + 1] - ps[i - d][j - x];
            }
        }

    for(int d = 0; d < n; d++)
    {
        for(int i = 0; i <= min(r, d); i++)
            for(int j = 0; i * i + j * j <= r * r; j++)
            {
                int d2 = d - i;

                if(d2 > r)
                    continue;

                R[d] = max(R[d], (int)sqrt(r * r - d2 * d2 + eps) + j);
            }
    }

//    for(int i = 0; i < n; i++)
//        cout << R[i] << ' ';
//
//    cout << endl;

//    for(int i = 0; i < n; i++)
//    {
//        for(int j = 0; j < m; j++)
//            cout << c[i][j] << ' ';
//
//        cout << endl;
//    }
//
//    for(int i = 0; i < n; i++)
//        cout << R[i] << ' ';
//
//    cout << endl;

    for(int i = 0; i < n; i++)
    {
        for(int l = 0; l < m; l++)
        {
            int x = 0, y = 0;

            for(int r = l; r < m; r++)
            {
                if(c[i][r] == x)
                    y++;

                if(c[i][r] > x)
                {
                    x = c[i][r];
                    y = 1;
                }

                Max[l][r] = x;
                kMax[l][r] = y;
            }
        }

        for(int x = r; x < n - r; x++)
            for(int y = r; y < m - r; y++)
            {
                int z = R[abs(x - i)];

                int lf = y - z, rg = y + z;

                if(abs(x - i) > 2 * r)
                    update(0, m - 1, c[x][y]);
                else
                {
                    if(lf - 1 >= 0)
                        update(0, lf - 1, c[x][y]);

                    if(rg + 1 < m)
                        update(rg + 1, m - 1, c[x][y]);
                }
            }
    }

    cout << ans << ' ' << (ans == 0 ? 0 : k / 2);
}