#include <bits/stdc++.h>
#define int long long
#define ld long double
#define y1 sdopgh

using namespace std;

int n, m, k, a[200005], l[200005], r[200005], used[200005], b[200005], s, Max, c[200005], x;
vector <int> g[200005];

void dfs(int v)
{
    used[v] = 1;

    if(c[a[v]] < x)
    {
        b[a[v]] = 1;
        c[a[v]] = x;
    }
    else b[a[v]]++;

    s++;
    Max = max(Max, b[a[v]]);

    for(auto to:g[v])
        if(used[to] == 0)
            dfs(to);
}


int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m >> k;

    for(int i = 0; i < n; i++)
        cin >> a[i];

    for(int i = 0; i < m; i++)
        {
            cin >> l[i] >> r[i];
            l[i]--;
            r[i]--;

            g[l[i]].push_back(r[i]);
            g[r[i]].push_back(l[i]);
        }

    int ans = 0;

    for(int i = 0; i < n; i++)
    {
        if(used[i] == 0)
        {
            x++;
            s = 0;
            Max = 0;

            dfs(i);
            ans += s - Max;
        }
    }

    cout << ans;
}