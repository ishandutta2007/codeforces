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
const int N = 3e5 + 10;
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
#define vi vector<int>
struct dsu
{
    vi p;
    vi rank;
    dsu(int n)
    {
        p.resize(n);
        rank.resize(n);
        for (int i = 0; i < n; i++)
        {
            p[i] = -1;
            rank[i] = 1;
        }
    }
    inline int par(int v)
    {
        return p[v] < 0 ? v : (p[v] = par(p[v]));
    }
    inline int size(int v)
    {
        return rank[par(v)];
    }
    inline bool merge(int u, int v)
    {
        u = par(u);
        v = par(v);
        if (u == v)
            return 0;
        if (rank[u] < rank[v])
        {
            swap(u, v);
        }
        p[v] = u;
        rank[u] += rank[v];
        return 1;
    }
};
int n;
ll sm = 0;
vi g[N] , ans;
pair<int, int> a[N];
int tin[N] , tout[N] , timer = 0;
vector<pair<int, int> > bottom;
vector<pair<int, int> > tinum;
pair<pair<int, int>, pair<int, int>> d[N];
bool used[N];
void dfs(int u)
{
    used[u] = 1;
    tin[u] = timer;
    timer++;
    auto cur = mp(u , tin[u]);
    int cnt = 0;
    for(auto v : g[u])
    {
        if(!used[v])
        {
            cnt++;
            dfs(v);
        }
    }
    tout[u] = timer;
    if(cnt) return;
    tinum.pb(cur);
    swap(cur.fst , cur.snd);
    bottom.pb(cur);
    // cout << u << " " << tin[u] << " " << tout[u] << "\n";
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    dsu ds(n + 100);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i].fst;
        a[i].snd = i;
        d[i].fst = a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0);
    for(int i = 0; i < n; i++)
    {
        pair<int, int> cur;
        auto in = mp(tin[i] , -1);
        auto out = mp(tout[i] , -1);
        auto itl = lower_bound(bottom.begin(), bottom.end(), in);
        auto itr = lower_bound(bottom.begin(), bottom.end(), out);
        // cout << i << " " << (int)(itl - bottom.begin()) << " " << (int)(itr - bottom.begin()) << "\n";
        cur.fst = (int)(itl - bottom.begin());
        cur.snd = (int)(itr - bottom.begin());
        d[i].snd = cur;
    }
    //    for(int i = 0; i < n; i++)
    //    {
    //        auto x = d[i];
    //        cout << x.fst.fst << " " << x.fst.snd << " " << x.snd.fst << " " << x.snd.snd << "\n";
    //    }
    sort(d, d + n);
    int l = 0;
    for(l = 0; l < n;)
    {
        int next = l + 1;
        int cp = l;
        int a , nxa;
        if(next < n)
        while (d[l].fst.fst == d[next].fst.fst)
        {
            a = d[l].fst.fst;
            nxa = d[next].fst.fst;
            next++;
            if(next >= n) break;
        }
        int r = next;
        //       cout << l << " " << r << "\n";
        for(int i = l; i <= r - 1; i++)
        {
            int cur = d[i].fst.snd;
            int u = ds.par(d[i].snd.fst);
            int v = ds.par(d[i].snd.snd);
            if(u != v)
            {
                ans.pb(cur + 1);
            }
        }
        
        for(int i = cp; i <= r - 1; i++ , l++)
        {
            int cur = d[i].fst.snd;
            int u = ds.par(d[i].snd.fst);
            int v = ds.par(d[i].snd.snd);
            if(u == v) continue;
            ds.merge(u, v);
            sm += d[i].fst.fst;
        }
    }
    int m = ans.size();
    cout << sm << " " << m << "\n";
    sort(ans.begin(), ans.end());
    for(int i = 0; i < m; i++)
    {
        cout << ans[i] << " ";
    }
    cout << "\n";
    return 0;
}