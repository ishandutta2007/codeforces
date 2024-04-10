#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int t, n, m;
char a[205][205];

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

        if(a[0][0] == '1')
        {
            cout << "-1\n";
            continue;
        }

        cout << n * m << "\n";

        for(int i = n - 1; i >= 0; i--)
            for(int j = m - 1; j >= 0; j--)
            {
                if(a[i][j] == '0')
                    cout << i + 1 << ' ' << j + 1 << ' ' << i + 1 << ' ' << j + 1 << "\n";

                else if(i > 0)
                    cout << i << ' ' << j + 1 << ' ' << i + 1 << ' ' << j + 1 << "\n";

                else if(j > 0)
                    cout << i + 1 << ' ' << j << ' ' << i + 1 << ' ' << j + 1 << "\n";
            }
    }
}