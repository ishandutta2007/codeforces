#include <bits/stdc++.h>
#define int long long
#define ld long double
#define x first
#define y second
#define pb push_back

using namespace std;

vector <int> v[100005];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n, m;
    cin >> n >> m;

    int a[n][m];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin >> a[i][j];

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            v[a[i][j]].pb(i);

    int ans = 0;

    for(int i = 0; i < 100005; i++)
    {
        sort(v[i].begin(), v[i].end());

        int a = 0, b = v[i].size(), sa = 0, sb = 0;

        for(auto x:v[i])
            sb += x;

        for(auto x:v[i])
        {
            ans += x * (a - b) - sa + sb;

            sa += x;
            sb -= x;

            a++;
            b--;
        }

        v[i].clear();
    }

    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            v[a[i][j]].pb(j);

    for(int i = 0; i < 100005; i++)
    {
        sort(v[i].begin(), v[i].end());

        int a = 0, b = v[i].size(), sa = 0, sb = 0;

        for(auto x:v[i])
            sb += x;

        for(auto x:v[i])
        {
            ans += x * (a - b) - sa + sb;

            sa += x;
            sb -= x;

            a++;
            b--;
        }

        v[i].clear();
    }

    cout << ans / 2;
}