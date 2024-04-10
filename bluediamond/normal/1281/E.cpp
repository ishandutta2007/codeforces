#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = (int) 2e5 + 7;
int n;
vector<pair<int, int>> g[N];
int under[N];
ll ans1;
ll ans2;

void dfs(int a, int p)
{
    under[a] = 1;
    for (auto &it : g[a])
    {
        int b = it.first;
        int c = it.second;
        if (b != p)
        {
            dfs(b, a);
            under[a] += under[b];
            ans1 += under[b] % 2 * c;
            ans2 += min(under[b], n - under[b]) * (ll) c;
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while (t--)
    {
        ans1 = ans2 = 0;
        cin >> n;
        n *= 2;
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        for (int i = 1; i < n; i++)
        {
            int a, b, c;
            cin >> a >> b >> c;
            g[a].push_back({b, c});
            g[b].push_back({a, c});
        }
        dfs(1, -1);
        cout << ans1 << " " << ans2 << "\n";
    }

}