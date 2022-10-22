#include <bits/stdc++.h>
//#define int long long
#define ld long double
#define pb push_back
#define x first
#define y second

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

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int Min[n][m], Max[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                if(i == 0 && j == 0)
                {
                    Min[i][j] = a[i][j];
                    Max[i][j] = a[i][j];
                }
                else if(i == 0)
                {
                    Min[i][j] = Min[i][j - 1] + a[i][j];
                    Max[i][j] = Max[i][j - 1] + a[i][j];
                }
                else if(j == 0)
                {
                    Min[i][j] = Min[i - 1][j] + a[i][j];
                    Max[i][j] = Max[i - 1][j] + a[i][j];
                }
                else
                {
                    Min[i][j] = min(Min[i - 1][j], Min[i][j - 1]) + a[i][j];
                    Max[i][j] = max(Max[i - 1][j], Max[i][j - 1]) + a[i][j];
                }
            }

//        cout << Min[n - 1][m - 1] << ' ' << Max[n - 1][m - 1] << "\n";

        if(Min[n - 1][m - 1] <= 0 && Max[n - 1][m - 1] >= 0 && (n + m) % 2)
            cout << "YES\n";
        else cout << "NO\n";
    }
}