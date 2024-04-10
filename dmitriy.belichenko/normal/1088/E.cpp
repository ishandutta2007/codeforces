#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <cstring>
#include <queue>
#include <vector>
#define ll long long
using namespace std;
const int N = 3e5 + 5;
vector<int> g[N];
int res = 0;
int a[N];
ll ans = -1e9 - 7;
bool used[N];
ll dfs(int u)
{
    used[u] = 1;
    ll cur = a[u];
    for(auto v : g[u])
    {
        if(!used[v])
        {
            cur += max((ll)0 , dfs(v));
        }
    }
    ans = max(ans , cur);
    return cur;
}
ll dfsr(int u)
{
    used[u] = 1;
    ll cur = a[u];
    for(auto v : g[u])
    {
        if(!used[v])
        {
            cur += max((ll)0 , dfsr(v));
        }
    }
    if(ans == cur)
    {
        cur = 0;
        res++;
    }
    return cur;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        u-- , v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs(0);
    for(int i = 0; i < n + 2; i++) used[i] = 0;
    dfsr(0);
 //   cout << ans << "\n";
    cout << ans * res << " " << res << "\n";
    return 0;
}