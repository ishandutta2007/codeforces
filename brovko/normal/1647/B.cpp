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
            {
                cin >> a[i][j];
                a[i][j] -= '0';
            }

        int F = 1;

        for(int i = 1; i < n; i++)
            for(int j = 1; j < m; j++)
                if(a[i][j] + a[i][j - 1] + a[i - 1][j] + a[i - 1][j - 1] == 3)
                    F = 0;

        cout << (F ? "YES\n" : "NO\n");
    }
}