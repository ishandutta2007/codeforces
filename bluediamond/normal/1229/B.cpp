#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int N = 100000 + 7;
const int MOD = (int) 1e9 + 7;
int n;
ll a[N];
bool u[N];
vector <int> g[N];
map <ll, int> gcds[N];

void dfs(int nod, int par)
{
    u[nod] = 1;
    for (auto &it : gcds[par])
    {
        gcds[nod][__gcd(it.first,a[nod])] += it.second;
    }

    gcds[nod][a[nod]]++;

    for (auto &nou : g[nod])
        if (u[nou] == 0)
        {
            dfs(nou, nod);
        }

}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        g[x].push_back(y);
        g[y].push_back(x);
    }

    dfs(1, 0);

    ll ans = 0;
    for (int i = 1; i <= n; i++)
        for (auto &it : gcds[i])
        {
            ans = (ans + it.first * it.second) % MOD;
        }
    cout << ans << "\n";

    return 0;
}