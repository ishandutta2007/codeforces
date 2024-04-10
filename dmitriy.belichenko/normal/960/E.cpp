#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <iostream>
#include <set>
#include <iomanip>
#include <bitset>
#include <functional>
#include <random>
#include <unordered_map>
#include <unordered_set>
#include <queue>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
#define mt make_tuple
#define int long long
const double PI = acos(-1);
const int N = 2e5 + 7;
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 30;
template<class A, class B>
ll sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
    if (a >= MOD) a -= MOD;
    return a;
}
int to_i(char c)
{
    return c - 'a';
}
ll mult(ll a, ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
    return c % MOD;
}
ll poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
vector<int> g[N];
int a[N], dp[N], dp2[N];
int n , ans;
void dfs1(int u , int p)
{
    dp2[u] = 1;
    dp[u] = a[u];
    for(int v : g[u])
    {
        if(v == p)  continue;
        dfs1(v , u);
        sum(dp2[u] , dp2[v]);
        sum(dp[u] , mult(a[u] , dp2[v]));
        sum(dp[u] , MOD - dp[v]);
    }
}
void dfs2(int u , int p , int up)
{
    int tot = dp[u] - up;
    sum(tot , MOD);
    sum(tot , mult(a[u] , (n-dp2[u])));
    sum(ans , tot);
    for(int v : g[u])
    {
        if(v == p) continue;
        int val = tot;
        sum(val , dp[v]);
        sum(val , MOD - 1LL * mult(a[u], dp2[v]));
        dfs2(v , u, val);
    }
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
        if(a[i] < MOD) a[i] += MOD;
    }
    for(int i = 1; i < n; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs1(1 , 1);
    dfs2(1 , 1 , 0);
    cout << ans % MOD<< "\n";
}