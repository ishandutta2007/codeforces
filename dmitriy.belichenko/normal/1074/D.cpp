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
#include <valarray>
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
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 26;
const int N = 6e5 + 15;
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
ll calc( ll i,  ll n)
{
    ll j = i;
    ll t = 0;
    while (j <= n)
    {
        t += n / j;
        j *= i;
    }
    return t;
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
int n;
bitset<N> used;
vector<ll> g[N];
//int dfs(int u)
//{
//    used[u] = 1;
//    for(auto v : g[u])
//    {
//        if(!used[v])
//        {
//            int x = dfs(v);
//            if(x != INF)
//            {
//                return x;
//            }
//        }
//    }
//    return INF;
//}

int dfs(int u, int p)
{
    for (int v : g[u])
    {
        if(used[u])
        {
            break;
        }
        if (v != p)
        {
            int vert;
            if(used[v])
            {
                vert = v;
            }
            if(!used[v])
            {
                vert = dfs(v , u);
            }
            if (vert > 0)
            {
                return vert;
            }
        }
    }
    if(!used[u]) return 0;
    if(used[u]) return u;
    return 0;
}
#define int ll
int dp_Sz[N];
int dp1[N];
ll num_val[N];
void clear()
{
    for (int i = 0; i < N; i++)
    {
        dp_Sz[i] = i;
        g[i].pb(dp_Sz[i]);
        dp1[i] = 1;
    }
}

ll x[N] , y[N];
bool cmp_ord1(int a, int b)
{
    return x[a] < x[b];
}

bool cmp_ord2(int a, int b)
{
    return y[a] < y[b];
}

bool cmp_ord3(int a, int b)
{
    return x[a] + y[a] < x[b] + y[b];
}

bool cmp_ord4(int a, int b)
{
    return x[a] - x[b] < y[a] - y[b];
}

ll dist(int i, int j)
{
    return (abs(x[i] - x[j]) + abs(y[i] - y[j]));
}
set<int> ord12 , ord34;
inline ll solve_3()
{
    ll ans = 0;
    vector<int> st;
    for (auto i : ord12)
    {
        st.pb(i);
    }
    int uv = ord12.size();
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < uv; j++)
        {
            for (int k = j + 1; k < uv; k++)
            {
                ans = max(ans, dist(i, st[j]) + dist(st[j], st[k]) + dist(st[k], i));
            }
        }
    }
    int nv = ord34.size();
    for (int i = 0; i < nv; i++)
    {
        for (int j = i + 1; j < nv; j++)
        {
            for (int k = j + 1; k < nv; k++)
            {
                ans = max(ans, dist(i, j) + dist(i, k) + dist(j, k));
            }
        }
    }
    return ans;
}
inline int rev(int i )
{
    return n - i - 1;
}
int next_val = 0;
unordered_map<ll, ll> cont;
inline void nxt(ll x)
{
    if (!cont.count(x))
    {
        cont[x] = next_val;
        next_val++;
    }
}
void clear_hf(int u)
{
    dp1[u] = 0;
    g[u].clear();
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int q;
    cin >> q;
    ll xr = 0;
    clear();
    while (q--)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            if(q == 2)
            {
                ll p = poww(2 , 30);
                // cout << p << "\n";
            }
            ll l, r, x;
            cin >> l >> r >> x;
            l ^= xr , r ^= xr , x ^= xr;
            if (l > r)
            {
                swap(l, r);
            }
            l = min(l , r) - 1;
            nxt(l) , nxt(r);
            l = cont[l] , r = cont[r];
            int nx = dp_Sz[l] , ny = dp_Sz[r];
            ll del = dp_Sz[l] - dp_Sz[r];
            if (!del) continue;
            ll curxr = 0;
            if (dp1[nx] < dp1[ny])
            {
                swap(nx, ny);
            }
            curxr = num_val[r];
            curxr ^= (x ^ num_val[l]);
            for (auto i : g[ny])
            {
                num_val[i] ^= curxr;
                g[nx].pb(i);
                dp_Sz[i] = nx;
            }
            dp1[nx] += dp1[ny];
            clear_hf(ny);
        }
        if(t == 2)
        {
            ll l, r;
            cin >> l >> r;
            l ^= xr , r ^= xr;
            if (l > r)
            {
                swap(l, r);
            }
            l = min(l , r) - 1;
            nxt(l) , nxt(r);
            if (dp_Sz[cont[l]] == dp_Sz[cont[r]])
            {
                xr = (num_val[cont[l]] ^ num_val[cont[r]]);
                cout << xr << "\n";
            }
            else
            {
                xr = 1;
                cout << "-1" << "\n";
            }
        }
        
    }
    return 0;
}