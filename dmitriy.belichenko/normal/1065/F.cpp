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
ll MOD = 998244353;
const int INF = 1e9;
const int MaXN = 105;
const int N = 1e6 + 1000;
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
int numsize[N];
int dp[N];
int dist[N];
vector<int> g[N];
int n , k;
// very strange problem: all you need is to calculate dist to closest leaf and num of different lists then ans
// is dp[huy] = max(dp[batya] , dp[batya] - size[batya] (significantly GIANT)) + size[huy] (xD???)
//
void relax(int u)
{
    dp[u] = dist[u] == 228228228228 ? 1 : dp[u];
    numsize[u] = dist[u] == 228228228228 ? 1 :
            (dist[u] > k - 1 ? 0 :numsize[u]);
    if(dist[u] == 228228228228)
    {
        dist[u] = 0;
    }
    
}
void dfs(int u)
{
    dist[u] = 228228228228;
    for(auto v: g[u])
    {
        dfs(v);
        dist[u] = min(dist[u], dist[v] + 1);
        numsize[u] += numsize[v];
    }
    dp[u] = numsize[u];
    for(auto v: g[u])
    {
        dp[u] = max(dp[u], dp[v] + numsize[u] - numsize[v]);
    }
    relax(u);
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 1; i < n; i++)
    {
        int u ;
        cin >> u;
        g[u - 1].pb(i);
    }
    dfs(0);
    cout << dp[0] << "\n";
    return 0;
}