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
vector<int> g[N];
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
void clear()
{
    for(int i = 0; i <= 1000; i++)
    {
        g[i].clear();
    }
    used = 0;
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
set<int> ord12, ord34;
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
inline void fill(vector<int> &ord1)
{
    for (int i = 0; i < 3; i++)
    {
        ord34.ins(ord1[i]);
        ord34.ins(ord1[rev(i)]);
    }
}
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }
    vector<int> ord1(n), ord2(n), ord3(n), ord4(n);
    for (int i = 0; i < n; i++)
    {
        ord1[i] = i;
        ord2[i] = i;
        ord3[i] = i;
        ord4[i] = i;
    }
    sort(ord1.begin(), ord1.end(), cmp_ord1);
    sort(ord2.begin(), ord2.end(), cmp_ord2);
    sort(ord3.begin(), ord3.end(), cmp_ord3);
    sort(ord4.begin(), ord4.end(), cmp_ord4);
    fill(ord1);
    fill(ord2);
    ord12 = ord34;
    fill(ord3);
    fill(ord4);
    cout << solve_3() << " ";
    for (int i = 4; i < n + 1; i++)
    {
        ll delx = x[ord1.back()] - x[ord1[0]];
        ll dely = y[ord2.back()] - y[ord2[0]];
        cout << 2 * (delx + dely) << " ";
    }
    return 0;
}