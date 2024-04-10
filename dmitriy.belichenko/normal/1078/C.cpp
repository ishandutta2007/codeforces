#pragma GCC optimize("Ofast" , "no-stack-protector")
#pragma GCC target("sse4" , "avx")
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
const int N = 3e5 + 15;
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
//#define int ll

struct point
{
    ld x , y;
};
ld sqr(ld x)
{
    return x * x;
}
ld dist(point p, point q)
{
    return sqrt(sqr(p.x - q.x) + sqr(p.y - q.y));
}
#define int long long
int n;
vector <int> orient[N];
vector <int> g[N];
int dp[3][N];
bitset<N> used;
void dfs(int u)
{
    used[u] = 1;
    for(auto v : g[u])
    {
        if(!used[v])
        {
            orient[u].push_back(v);
            dfs(v);
        }
    }
}
int dp_v_u(int now , int v);
inline int rec(int u)
{
    int p = dp_v_u(0 , u);
    int q = dp_v_u(2 , u);
    return add(p , q);
}
inline int back(int sz , int i)
{
    return sz - i - 1;
}
int dp_v_u(int now, int v)
{
    
    if(dp[now][v] != -1)
    {
        return dp[now][v];
    }
    dp[now][v] = 0;
    int sz = orient[v].size();
    sz++;
    vector <int> dp_forward(sz);
    vector <int> dp_back(sz);
    dp_forward[0] = 1 , dp_back[0] = 1;
    sz--;
    for(int i = 0; i < sz; i++)
    {
        int u_frw = orient[v][i];
        int u_bck = orient[v][back(sz, i)];
        dp_forward[i + 1] = mult(dp_forward[i], rec(u_frw));
        dp_back[i + 1] = mult(dp_back[i], rec(u_bck));
    }
    if(now == 1)
    {
        dp[now][v] = dp_back[sz];
        return dp[now][v];
    }
    for(int i = 0; i < sz; i++)
    {
        int u = orient[v][i];
        int cur = mult(dp_v_u(1, u), mult(dp_forward[i] , dp_back[back(sz, i)]));
        sum(dp[now][v], cur);
    }
    
    if(now == 0)
    {
        int cur = 1;
        for(auto to : orient[v])
        {
            cur = mult(cur, dp_v_u(0, to));
        }
        sum(dp[now][v], cur);
        return dp[now][v];
    }
    else
    {
        return dp[now][v];
    }
    return dp[now][v];
}

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            dp[j][i] = -1;
        }
    }
    for(int i = 1; i < n; i++)
    {
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    vector<int> cmp;
    int res = 0;
    for(int i = 0; i < n; i++)
    {
        if(!used[i])
        {
            dfs(i);
            cmp.pb(i);
        }
    }
    for(auto j : cmp)
    {
        sum(res , dp_v_u(0, j));
    }
    cout << res << "\n";
    return 0;
}