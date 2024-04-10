/**
 ____ ____ ____ ____ ____
||a |||t |||o |||d |||o ||
||__|||__|||__|||__|||__||
|/__\|/__\|/__\|/__\|/__\|

**/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N_MAX = 200002;
const int M_MAX = 200002;

int t;

int n, m, k;

struct Edge
{
    int u, v, s;
};

bool operator < (const Edge &a, const Edge &b)
{
    return max(0, a.s - k) < max(0, b.s - k);
}

Edge edges[M_MAX];

int root[N_MAX];

int findRoot (int u)
{
    if(root[u] == u)
        return u;
    return root[u] = findRoot(root[u]);
}

bool join (int u, int v)
{
    u = findRoot(u);
    v = findRoot(v);
    if(u == v)
        return false;
    root[u] = v;
    return true;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> k;
        for(int i = 1; i <= m; i++)
            cin >> edges[i].u >> edges[i].v >> edges[i].s;
        sort(edges + 1, edges + m + 1);
        for(int i = 1; i <= n; i++)
            root[i] = i;
        ll ans = 0;
        bool ok = false;
        for(int i = 1; i <= m; i++)
            if(join(edges[i].u, edges[i].v))
            {
                ok |= (edges[i].s >= k);
                ans += max(0, edges[i].s - k);
            }
        if(ok == true)
        {
            cout << ans << "\n";
            continue;
        }
        ans = LLONG_MAX;
        for(int i = 1; i <= m; i++)
            ans = min(ans, 1LL * abs(edges[i].s - k));
        cout << ans << "\n";
    }
    return 0;
}