#include <bits/stdc++.h>
#define int long long
#define ld lond double
#define y1 eohfweoifhew

using namespace std;

int n, p[200005], d[200005], k[200005];
vector <int> g[200005];

void dfs(int v)
{
    k[v] = 1;

    for(auto to:g[v])
    {
        dfs(to);
        k[v] += k[to];
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;

    d[0] = 1;

    for(int i = 1; i < n; i++)
    {
        cin >> p[i];
        p[i]--;

        d[i] = d[p[i]] + 1;

        g[p[i]].push_back(i);
    }

    dfs(0);

    for(int i = 0; i < n; i++)
        cout << d[i] + double(n - d[i] - k[i] + 1) / 2 << ' ';
}