#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back
#define y1 jgpjewgjepg

using namespace std;

int t, n, m, a[105][105];

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
                cin >> a[i][j];

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if((i + j) % 2 == 0)
                    cout << a[i][j] + a[i][j] % 2;
                else cout << a[i][j] + 1 - a[i][j] % 2;

                cout << ' ';
            }

            cout << "\n";
        }
    }
}