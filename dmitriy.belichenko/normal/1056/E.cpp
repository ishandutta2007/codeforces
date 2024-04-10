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

signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    string s , t;
    cin >> s >> t;
    int n = s.size();
    int m = t.size();
    long long ans = 0;
    vector<int> gf;
    poww(2 , n);
    for(int i = 0; i < 100; i++)
    {
        gf.pb(inv(i + rand() % 10));
    }
    for(int i = 0; i < 100; i++)
    {
        if(gf[0] == 0)
        {
            assert(0);
        }
    }
    int cnt0 = 0, cnt1 = 0;
    for (int i = 0; i < n; i++)
    {
        if (s[i] == '0')
        {
            cnt0++;
        }
        else
        {
            cnt1++;
        }
    }
    swap(n , m);
    hp(t);
    if(cnt1 > cnt0)
    {
        for(int i = 0; i < m; i++)
        {
            if(s[i] == '1')
            {
                s[i] = '0';
            }
            else
            {
                s[i] = '1';
            }
        }
        swap(cnt1 , cnt0);
    }
    for (int p = 1; p * cnt0 < n; p++)
    {
        int px = p * cnt0;
        if ((n - px) % cnt1 == 0)
        {
        int si = (n - p * cnt0) / cnt1;
        int cur = -1, curs = -1;
        int l = 0;
        bool ok = true;
        for(int i = 0; i < m; i++)
        {
            if (s[i] == '0')
            {
                int val = get(l, l + p);
                if (cur == -1)
                {
                    cur = val;
                }
                else if (cur != val)
                {
                    ok = 0;
                }
                if(!ok)
                {
                    break;
                }
                l += p;
            }
            else
            {
                int val = get(l, l + si);
                if (curs == -1)
                {
                    curs = val;
                }
                else if (curs != val)
                {
                    ok = 0;
                }
                if(!ok)
                {
                    break;
                }
                l += si;
            }
        }
        if (cur == curs)
        {
            continue;
        }
        ans += ok;
        }
    }
    cout << ans << "\n";
    return 0;
}