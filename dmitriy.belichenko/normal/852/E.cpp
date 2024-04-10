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
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

const int N = 1e5;
const int INF = 1e9;
ll MOD =  1000000007;
int n, l;
vector < vector<int> > g;
vector<int> tin, tout;
int timer;
vector < vector<int> > up;
int dp[100005];
void dfs (int v, int p  , int dst )
{
    dp[v] = dst;
    tin[v] = ++timer;
    up[v][0] = p;
    for (int i=1; i<=l; ++i)
        up[v][i] = up[up[v][i-1]][i-1];
    for (size_t i=0; i<g[v].size(); ++i)
    {
        int to = g[v][i];
        if (to != p)
            dfs (to, v ,dst + 1);
    }
    tout[v] = ++timer;
}
ll binpow (ll a, ll n)
{
    if (n == 0)
        return 1 % MOD;
    if (n % 2 == 1) {
        ll tmp = binpow (a, n-1) * a;
        return tmp % MOD;
    }
    else {
        ll b = binpow (a, n/2);
        b %= MOD;
        return (b * b) % MOD;
    }
}
bool upper (int a, int b)
{
    return tin[a] <= tin[b] && tout[a] >= tout[b];
}

int lca (int a, int b)
{
    if (upper (a, b))  return a;
    if (upper (b, a))  return b;
    for (int i=l; i>=0; --i)
        if (! upper (up[a][i], b))
            a = up[a][i];
    return up[a][0];
}

int calcdist (int a, int b)
{
    int x=lca(a, b);
    return dp[a]+dp[b]-2*dp[x];
}
int dp2[N];
int calc(int x)
{
   
    int i=1;
    for (int j = 0; x; x--)
        i = ( i << 1)% MOD;
    return i;
}
int main()
{
    ::ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    g.resize(n);
    for(int i = 0; i < n - 1; i ++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    tin.resize (n),  tout.resize (n),  up.resize (n);
    l = 1;
    while ((1<<l) <= n)  ++l;
    for (int i = 0; i < n; ++i)  up[i].resize (l+1);
    dfs (0 , 0 , 1);
    dp[0] = 1;
    vector<int> term;
    for(int i = 0; i < n; i++)
    {
        if(g[i].size() == 1)
        {
            term.pb(i);
        }
    }
    ll ans = 0;
    int termcnt = 0;
    for (int i = 0 ; i < n; i++)
        if (g[i].size() == 1) termcnt++;
    
    ans = ((ll)termcnt*calc(n-(termcnt-1))+(ll)(n-termcnt)*calc(n-termcnt))% MOD;
     cout << ans << "\n";
    return 0;
}