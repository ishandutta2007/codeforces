#include <bits/stdc++.h>
#define int long long
#define ld long double

using namespace std;

int n, a[200005], p[200005], k[200005], s[200005], Max[200005];
vector <int> g[200005];

void dfs(int v)
{
    if(g[v].size() == 0)
    {
        k[v] = 1;
        s[v] = a[v];
        Max[v] = a[v];
    }

    s[v] = a[v];

    for(auto to:g[v])
    {
        dfs(to);
        s[v] += s[to];
        k[v] += k[to];
        Max[v] = max(Max[v], Max[to]);
    }

    if(Max[v] * k[v] < s[v])
        Max[v] = (s[v] + k[v] - 1) / k[v];
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;

        g[p[i]].push_back(i);
    }

    for(int i = 0; i < n; i++)
        cin >> a[i];

    dfs(0);

    cout << Max[0];
}