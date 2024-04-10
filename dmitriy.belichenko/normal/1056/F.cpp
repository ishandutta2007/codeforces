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
const int N = 5e5 + 15;
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
template<typename T1, typename T2> inline bool upmax(T1& a, T2 b)
{
    return (a < b ? (a = b, true) : false);
}
template<typename T1, typename T2> inline bool upmin(T1& a, T2 b)
{
    return (b < a ? (a = b, true) : false);
}

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
#define int ll
const int P = 239017 + (rand() % 7 * 239), mod = MOD;
vector<int> h, p;
void hp(string &s)
{
    int n = s.size();
    h.resize(n + 1), p.resize(n + 1);
    p[0] = 1;
    for(int i = 0; i < n; i++)
    {
        h[i + 1] = add(mult(h[i], P) , s[i]) % mod;
        p[i + 1] = mult(p[i] , P);
    }
}
int get(int l, int r)
{
    return (h[r] - (h[l] * 1LL * p[r - l]) % mod + mod) % mod;
}


ld pw[N];
ld f[101][101][101 * 10];

int n;
ld C, T;
ld eps = 1e-10;
bool us[100][100][100 * 10];

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int t;
    cin >> t;
    pw[0] = 0.9;
    for (int i = 1; i < 111; i ++)
    {
        pw[i] = pw[i - 1] * 0.9L;
    }

    while(t--)
    {
        cin >> n;
        cin >> C >> T;
        
        for (int i = 0; i <= n; i++)
        {
            for (int j = 0; j <= i; j++)
            {
                for (int k = 0; k <= j * 10; k++)
                {
                    us[i][j][k] = 0, f[i][j][k] = 1e80;
        
                }
            }
        }
        vector<pair<int, int>> a(n);
        for (int i = 1; i <= n; i ++)
        {
            int x, y; cin >>x >> y;
            a.pb({x, y});
        }
        sort(a.rbegin(), a.rend());
        f[0][0][0] = 0.;
        us[0][0][0] = 1;
        for (int i = 0; i < n; i ++)
        {
            for (int j= 0; j <= i; j ++)
            {
                for (int k = 0; k <= j * 10; k ++)
                {
                    if (!us[i][j][k]) continue;
                    upmin(f[i + 1][j][k], f[i][j][k]);
                    us[i + 1][j][k] = 1;
                    upmin(f[i + 1][j + 1][k + a[i].snd], f[i][j][k] + 1.L * a[i].fst / pw[j]);
                    us[i + 1][j + 1][k + a[i].snd] = 1;
                }
            }
        }
        auto getroot = [&](ld a, ld b, ld c) ->ld
        {
            ld D = sqr(b) - 4. * a * c;
            if (D < 0)
            {
                return -100.;
            }
            return (-b + sqrt(D)) / (2. * a);
        };
        
        int res = 0;
        for (int i = 0; i <= n; i ++)
        {
            for (int j = 0; j <= i * 10; j ++)
            {
                if (!us[n][i][j]) continue;
                if (f[n][i][j] + 10. * i < T + eps)
                {
                    upmax(res, j);
                }
                else
                {
                    ld tt = f[n][i][j];
                    ld r = getroot(C, 10. * i * C + 1. - C * T, 10. * i - T + tt);
                    if (r >= 0) upmax(res, j);
                }
            }
        }
        cout << res << "\n";
    }
    return 0;
}