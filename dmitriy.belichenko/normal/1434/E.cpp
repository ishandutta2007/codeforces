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
const int INF = 1e5;
const int MaXN = 150;
const int N = 1e5 + 11;
const int LOG = 25;
const int FACT = 120;
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
const int M = 1000 + 10;
const int M2 = M / 2;
// smalltolarge
int p[M2][N], rm[M2][N];

int par(int u, int v)
{
    if(p[u][v] == v)
    return v;
    return p[u][v] = par(u, p[u][v]);
}

void unite(int u, int x , int y)
{
    int xx = par(u, x);
    int yy = par(u, y);
    p[u][xx] = yy;
}

void addtolarge(int u, int l, int r, int v)
{
    while (true)
    {
        l = par(u, l);
        int next = l + 1;
        if(r < l) break;
        rm[u][l] = v;
        unite(u, l, next);
    }
}

int v[N], a[N];

void relax(int n)
{
    for(int i = 0; i < N; i++) a[i] = -1;
    
    for(int i = 0; i < M2; i++)
    {
        for(int j = 0; j < n; j++)
        {
            p[i][j] = j;
            rm[i][j] = -INF;
        }
    }
    
    for(int i = 0; i < n; i++)
    {
        a[v[i]] = i;
    }
    
}
int x[M], ans[N], cnt[N];
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n, m, xr = 0;
    cin >> n;
    while(n--)
    {
        cin >> m;
        for(int i = 0; i < m; i++) cin >> v[i];
        relax(m);
        for(int i = 0; i < N; i++)
        {
            if(i == 0) continue;
            if(a[i] < 0) a[i] = a[i - 1];
        }
        for(int i = 0; i < m; i++)
        {
            int val = INF; // will be recalculated during the process
            for(int j = 0; j < M2; j++) x[j] = 0;
            for(int j = 0; j < M2; )
            {
                int fromR = m - i - 1, y = j + 1;
                int mx = rm[j][fromR];
                int L = 0;
                if(mx > 0)
                {
                    while (rm[y][fromR] > mx - 1) {
                        y++;
                    }
                    // L = mx - v[i] // need to go from the right border
                    L = mx - v[fromR];
                    L++;
                }
                // [prv, fl..fr.. nxt]
                int prv = v[fromR] - 1;
                int nxt = v[fromR] + 1;
                int fl = max(0, nxt - val);
                int fr = min(prv, nxt - L);
                if(fl < fr + 1)
                {
                    if(fl > 0)
                    {
                        addtolarge(j, 1 + a[fl - 1], a[fr], v[fromR]);
                    }
                    else addtolarge(j, 0, a[fr], v[fromR]);
                }
                if(!L)
                {
                    ans[fromR] = j;
                    break;
                }
                
                val = L - 1;
                j = y;
            }
        }
        for(int i = 0; i < M; i++)
        {
            cnt[i] = 0;
        }
        for(int i = 0; i < m; i++)
        {
            cnt[ans[i]]++;
        }
        int j = 0;
        while (cnt[j]) j++;
        xr ^= j;
    }
    if(xr)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
    return 0;
}