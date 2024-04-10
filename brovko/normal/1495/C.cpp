#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define mp make_pair
#define pb push_back

using namespace std;

int t, n, m;
char a[505][505];

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
                
        for(int j = 0; j < m; j++)
        {
            a[n][j] = 0;
            a[n + 1][j] = 0;
        }

        for(int i = (n % 3 == 0) + 1; i < n; i += 3)
        {
            if(m > 1 && (a[i][1] == 'X' || a[i + 1][1] == 'X'))
            {
                a[i][1] = 'X';
                a[i + 1][1] = 'X';
            }
            else
            {
                a[i][0] = 'X';
                a[i + 1][0] = 'X';
            }
        }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(n % 3 == 0 && i % 3 == 1 || n % 3 != 0 && i % 3 == 0)
                    a[i][j] = 'X';

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
                cout << a[i][j];

            cout << "\n";
        }
    }
}