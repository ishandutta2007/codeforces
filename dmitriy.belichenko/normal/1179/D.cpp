#pragma GCC optimize("Ofast")
#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <cstring>
#include <math.h>
#include <string>
#include <set>
#include <iomanip>
#include <bitset>
#include <random>
#include <complex>
#include <random>
#include <cassert>
#include <unordered_map>
#include <unordered_set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fdeg firdeg
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 105;
const int N = 5e5 + 1000;
const int maxlog = 18;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
ll add(ll a, ll b)
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
ll mult(ll a, ll b) {
    ll val = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
 
ll gcd (ll a, ll b)
{
    if (b == 0)
        return a;
    else
        return gcd (b, a % b);
}
ll gcd_eu (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long val = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) val = mult(a, val);
        a = mult(a, a);
        b >>= 1;
    }
    return val % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
#define int ll
int n;
ll sqr(ll x)
{
    return x * x;
}
vector<int> g[N];
ll sz[N] , dp[N];
bool used[N];
ll ans = numeric_limits<ll>::max();
pair<ll, ll> pref[N] , suff[N];
void dfs(int u, int p = -1)
{
    sz[u] = 1;
    used[u] = 1;
    if(g[u].size() == 1)
    {
        dp[u] = 1;
        return;
    }
    for(auto v : g[u])
    {
        if(!used[v] || v != p)
        {
            dfs(v , u);
            sz[u] = sz[u] + sz[v];
        }
    }
    dp[u] =  numeric_limits<ll>::max();
    ll sm  = 0, sq = 0;
    for(auto v : g[u])
    {
        if(!used[v] || v != p)
        {
            dp[u] = min(dp[u] , dp[v] + sqr(sz[u] - sz[v]));
            pref[sm] = mp(-sz[v] , dp[v]);
            sm = sm + 1;
        }
    }
    sort(pref , pref + sm);
    for (int i = 0; i < sm; i++)
    {
        int back = sq - 1;
        if (!sq || pref[i].fst != suff[sq-1].fst)
        {
            for (int j = 0; j < sq; j++)
            {
                ans = min(ans, pref[i].snd + suff[j].snd + sqr(n + pref[i].fst + suff[j].fst));
            }
            if (!sq || pref[i].snd < suff[sq - 1].snd)
            {
                suff[sq] = pref[i];
                sq = sq + 1;
            }
            back = sq - 1;
        }
        else
        {
            ans = min(ans, pref[i].snd + suff[0].snd + sqr(n + pref[i].fst + suff[0].fst));
        }
    }
}
 
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    
    int st = 0;
    ll rz = n * (n - 1);
    for(int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        u-- , v--;
        g[u].pb(v);
        g[v].pb(u);
        if(g[u].size() > 1) st = u;
        if(g[v].size() > 1) st = v;
    }
    dfs(st);
    ans = n - ans;
    ans /= 2;
    if(n == 2)
    {
        cout << 2 << "\n";
        return 0;
    }
    cout << rz + ans << "\n";
}