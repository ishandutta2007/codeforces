#include <bits/stdc++.h>
//#define int long long
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

        char a[n][m];

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];

        int Minx = 1e9, Miny = 1e9;

        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                if(a[i][j] == 'R')
                {
                    Minx = min(Minx, i);
                    Miny = min(Miny, j);
                }

        if(a[Minx][Miny] == 'R')
            cout << "YES\n";
        else cout << "NO\n";
    }
}