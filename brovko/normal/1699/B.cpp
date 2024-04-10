#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define f first
#define s second

using li = long long;

using namespace std;


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {
        int n, m;
        cin >> n >> m;

        int a[n][m];

        for(int i = 0; i < n / 2; i++)
            for(int j = 0; j < m / 2; j++)
            {
                int F = (i + j) % 2;
                a[2 * i][2 * j] = F;
                a[2 * i + 1][2 * j + 1] = F;
                a[2 * i + 1][2 * j] = (F ^ 1);
                a[2 * i][2 * j + 1] = (F ^ 1);
            }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout << a[i][j] << ' ';

            cout << "\n";
        }
    }
}