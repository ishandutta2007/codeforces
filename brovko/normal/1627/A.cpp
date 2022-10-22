#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

int n, m, r, c;
char a[55][55];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;

    while(t--)
    {

        cin >> n >> m >> r >> c;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        r--;
        c--;

        int F = 1;

        if(F && a[r][c] == 'B')
        {
            cout << 0 << "\n";
            F = 0;
        }

        for(int i = 0; i < n; i++)
            if(F && a[i][c] == 'B')
            {
                cout << 1 << "\n";
                F = 0;
            }

        for(int i = 0; i < m; i++)
            if(F && a[r][i] == 'B')
            {
                cout << 1 << "\n";
                F = 0;
            }

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(F && a[i][j] == 'B')
                {
                    cout << 2 << "\n";
                    F = 0;
                }
            }

        if(F)
            cout << -1 << "\n";

    }
}