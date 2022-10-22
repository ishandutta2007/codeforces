#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int t, n, m, a[505][505], b[505][505];

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

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                cin >> b[i][j];

        int x = 0;

        for(int i = 0; i < m; i++)
            for(int j = 0; j < n; j++)
                if(a[0][i] == b[0][j])
                    x = i;

        vector <int> v;

        for(int j = 0; j < n; j++)
            for(int i = 0; i < n; i++)
                if(a[i][x] == b[0][j])
                    v.push_back(i);

        for(auto to:v)
        {
            for(int j = 0; j < m; j++)
                cout << a[to][j] << ' ';

            cout << "\n";
        }
    }
}