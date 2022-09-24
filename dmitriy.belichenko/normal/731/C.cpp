#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
#include<bitset>
#include <unordered_set>
#include <unordered_map>
#include <cassert>
#define fst first
#define snd second
#define pb push_back
#define mp(x, y) make_pair(x, y)
#define sq(a) (long double)a * a
using namespace std;
typedef long long ll;
const int N = 200005;
vector<int> g[N];
bool used[N];
vector<int> c;
vector<int> comp;
map<int , int> t;
int mx = 0;
void dfs(int v)
{
    comp.pb(v);
    t[c[v]]++;
    mx = max(t[c[v]] , mx);
    used[v] = 1;
    for(auto u : g[v])
    {
        if(!used[u]) dfs(u);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m , k;
    cin >> n >> m >> k;
    c.resize(n);
    for(int i = 0; i < n; i++) cin >> c[i];
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    ll ans = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            dfs(i);
            ans += comp.size() - mx;
            mx = 0;
            t.clear();
            comp.clear();
        }
    }
    cout << ans << "\n";
    return 0;
}