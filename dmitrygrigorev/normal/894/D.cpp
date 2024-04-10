#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

typedef long long ll;

int n;
vector<vector<ll>> sons;
vector<vector<ll>> heights_v;
vector<vector<ll>> heights_pfx;

void add(int u, ll x)
{
    if (u == 1)
        return;

    heights_v[u / 2].push_back(x + sons[u / 2][u % 2]);
    add(u / 2, x + sons[u / 2][u % 2]);
}

void dfs(int u)
{
    if (u > n)
        return;

    heights_v[u].push_back(0ll);
    add(u, 0ll);
    dfs(2 * u);
    dfs(2 * u + 1);

    int size = heights_v[u].size();
    sort(heights_v[u].begin(), heights_v[u].end());
    heights_pfx[u].resize(size + 1, 0ll);
    for (int i = 0; i < size; i++)
        heights_pfx[u][i + 1] = heights_pfx[u][i] + heights_v[u][i];
}

ll sum_in_subtree(int u, int s, ll h, ll sub_from)
{
    if ((h < sons[u][s]) || (2 * u + s > n))
        return 0ll;

    int idx = lower_bound(heights_v[2 * u + s].begin(),
                          heights_v[2 * u + s].end(),
                          h - sons[u][s]) - heights_v[2 * u + s].begin();
    return sub_from * (ll)idx - heights_pfx[2 * u + s][idx] -
            sons[u][s] * (ll)idx;
}

ll answer(int u, ll h)
{
    ll ans = sum_in_subtree(u, 0, h, h) + sum_in_subtree(u, 1, h, h) + h;

    int cur = u;
    ll height = 0ll;
    while (cur > 1)
    {
        height += sons[cur / 2][cur % 2];
        if (height > h)
            break;
        ans += h - height;
        ans += sum_in_subtree(cur / 2, 1 - (cur % 2), h - height, h - height);
        cur /= 2;
    }

    return ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    int m, i;
    cin >> n >> m;

    sons.resize(n + 1, vector<ll>(2, 0ll));
    for (i = 0; i < n - 1; i++)
        cin >> sons[(i + 2) / 2][(i + 2) % 2];

    heights_v.resize(n + 1);
    heights_pfx.resize(n + 1);

    dfs(1);

    for (i = 0; i < m; i++)
    {
        int a;
        ll h;
        cin >> a >> h;

        cout << answer(a, h) << endl;
    }

    return 0;
}