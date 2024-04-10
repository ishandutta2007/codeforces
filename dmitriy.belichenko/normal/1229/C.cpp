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
const int MaXN = 150;
const int N = 1e5 + 1000;
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
ll cntL[N], cntR[N];
vector<int> g[N];
vector<int> nw;
ll ans = 0;
int n , m, q;
int prv[N], nxt[N];
const int P = 350;

inline void dfs(int u)
{
    for(auto v : g[u])
        if(prv[u] < prv[v]) nw.pb(v);
}

inline void update()
{
    for(int i = 1; i < n + 1; i++)
    {
        nw.clear();
        dfs(i);
        g[i] = nw;
    }
}

inline void relax(int x)
{
    ans -= cntL[x] * cntR[x];
    //cout << ans << " ";
    for(auto v : g[x])
    {
        if(prv[x] < prv[v])
        {
            ans = ans - cntL[v] * cntR[v];
            cntR[x]--, cntR[v]++;
            cntL[x]++, cntL[v]--;
            ans += cntL[v] * cntR[v];
            g[v].pb(x);
        }
    }
    g[x].clear();
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int cnt = 0;
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int a , b , u , v;
        cin >> a >> b;
        v = max(a , b);
        u = min(a , b);
        cntR[u]++, cntL[v]++;
        g[u].pb(v);
    }
    cin >> q;
    for(int i = 1; i < n + 1; i++)
    {
        ans += cntL[i] * cntR[i];
        prv[i] = nxt[i] = i;
    }
    cout << ans << "\n";
    while(q--)
    {
        cnt++;
        int x;
        cin >> x;
        if(cnt % P == 0) update();
        relax(x);
        prv[x] = n + cnt;
        cout << ans << "\n";
    }
    return 0;
}