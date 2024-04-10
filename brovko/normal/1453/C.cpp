#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n;
char a[2005][2005];
int l[2005][10], r[2005][10], u[2005][10], d[2005][10], L[10], R[10], U[10], D[10];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 10; j++)
        {
            l[i][j] = 1e9;
            r[i][j] = -1e9;

            u[i][j] = 1e9;
            d[i][j] = -1e9;
        }

        for(int j = 0; j < 10; j++)
        {
            L[j] = 1e9;
            R[j] = -1e9;

            U[j] = 1e9;
            D[j] = -1e9;
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
        {
            int x = a[i][j] - '0';

            l[i][x] = min(l[i][x], j);
            r[i][x] = max(r[i][x], j);

            u[j][x] = min(u[j][x], i);
            d[j][x] = max(d[j][x], i);
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < 10; j++)
        {
            L[j] = min(L[j], l[i][j]);
            R[j] = max(R[j], r[i][j]);

            U[j] = min(U[j], u[i][j]);
            D[j] = max(D[j], d[i][j]);
        }

        for(int j = 0; j < 10; j++)
        {
            int ans = 0;

            for(int i = 0; i < n; i++)
            {
                int x = max({0ll, r[i][j], n - 1 - l[i][j]});
                int y = max({0ll, D[j] - i, i - U[j]});

                ans = max(ans, x * y);
            }

            for(int i = 0; i < n; i++)
            {
                int x = max({0ll, d[i][j], n - 1 - u[i][j]});
                int y = max({0ll, R[j] - i, i - L[j]});

                ans = max(ans, x * y);
            }

            cout << ans << ' ';
        }

        cout << "\n";
    }
}