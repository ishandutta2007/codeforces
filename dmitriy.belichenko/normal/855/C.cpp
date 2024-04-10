#include<cstring>
#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;

int l = 0, r = 0;
const int N = 1e5 + 10;
vector<int>g[N];
ll INF = 1LL << 62;
int n , m , k , x;
const int MOD = 1e9 + 7;
vector<ll>dp[N][3];
bool used[N + 5];
ll prod(ll a ,ll b)
{
    return (a * b) % MOD;
}
vector<ll> operator+(const vector<ll> &a ,const vector<ll> &b)
{
    vector<ll> ans(11);
    for(int i = 0; i < 11; i++)
    {
        ans[i] = (a[i] + b[i]);
        if(ans[i] >= MOD) ans[i] -= MOD;
    }
    return ans;
}
vector<ll> mrg(const vector<ll> &a , const vector<ll> &b)
{
    vector<ll> ans(11);
    for(int i = 0; i < 11; i++)
    {
        for(int j = 0; i + j < 11; j++)
        {
            ans[i + j] += prod(a[i], b[j]);
            if(ans[i + j] >= MOD)
                ans[i + j] -= MOD;
        }
    }
    return ans;
}
void dfs(int v, int par = -1)
{
    used[v] = 1;
    vector<ll> p(11);
    //cout << v << "\n";
    p[0] = k - 1;
    
    for(auto u : g[v])
    {
        if (u == par) continue;
        dfs(u, v);
        
    }
    for(auto u : g[v])
    {
        if (u == par) continue;
     {
         vector<ll> now = dp[u][0] + dp[u][1] + dp[u][2];
         p = mrg(p , now);

     }
    }
    dp[v][0] = p;
    p = vector<ll>(11);
    p[1] = 1;
    for(auto u : g[v])
    {
        if (u == par) continue;
        {
            vector<ll> now = dp[u][0];
            p = mrg(p , now);
        }
    }
    dp[v][1] = p;
    p = vector<ll>(11);
    p[0] = m - k;
    for(auto u : g[v])
    {
        if (u == par) continue;
        {
            vector<ll> now = dp[u][0] + dp[u][2];
            p = mrg(p , now);
            
        }
    }
    dp[v][2] = p;

}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    cin >> k >> x;
    dfs(0);
    ll ans = 0;
    for (int i = 0; i <= x; ++i) {
        ans += dp[0][0][i] + dp[0][1][i] + dp[0][2][i];
        ans %= MOD;
    }
    cout << ans << endl;
    return 0;
}