#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <map>
#include <unordered_map>
#include <bitset>
#include <complex>
#include <complex>
#include <cmath>
#include <iomanip>
#include <math.h>
#include <cstring>
#include <queue>
#include <set>
#define mp make_pair
#define pb push_back
using namespace std;
vector<int>g[100005];
bool used[100005];
vector<int> a;
vector<vector<int>> comp;
int cur = 0;
int mn = 1e9 + 1;
void dfs(int v)
{
  //  cout << v << "\n";
    mn = min(mn , a[v]);
    used[v] = 1;
    for(auto u : g[v])
    {
        if(!used[u]) dfs(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++) cin >> a[i];
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    long long ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            dfs(i);
            ans += mn;
            mn = 1e9;
        }
    }
    cout << ans << "\n";
}