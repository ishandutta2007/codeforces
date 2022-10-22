#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second

using namespace std;

int t, n, m, a[25][25];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> t;

    while(t--)
    {
        cin >> n >> m;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                a[i][j] = 0;

        for(int i = 0; i < n; i += 2)
        {
            a[i][0] = 1;
            a[i][m - 1] = 1;
        }

        for(int i = 2; i < m - 2; i += 2)
        {
            a[0][i] = 1;
            a[n - 1][i] = 1;
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout << a[i][j];

            cout << "\n";
        }

        cout << "\n";
    }
}