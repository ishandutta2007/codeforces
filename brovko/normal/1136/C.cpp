#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, a[505][505], b[505][505];
vector <int> v[1005], u[1005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    //freopen("name.in", "r", stdin);
    //freopen("name.out", "w", stdout);

    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> a[i][j];
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            cin >> b[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            v[i+j].push_back(a[i][j]);
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            u[i+j].push_back(b[i][j]);

    for(int i=0;i<n+m-1;i++)
    {
        sort(v[i].begin(), v[i].end());
        sort(u[i].begin(), u[i].end());
        for(int j=0;j<v[i].size();j++)
            if(v[i][j]!=u[i][j])
        {
            cout << "NO";
            return 0;
        }
    }

    cout << "YES";
}