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
const int MaXN = 150;
const int N = 5e5 + 1000;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0, (ll)1e9);
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
    ll val = a * b - (ll)((ld)a * b / MOD) * MOD;
    if (val < 0) {
        val += MOD;
    }
    if (val >= MOD) {
        val -= MOD;
    }
    return val;
}
ll gcd(ll a, ll b)
{
    if (b == 0)
    return a;
    else
    return gcd(b, a % b);
}
ll gcd_eu(ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd_eu(b%a, a, x1, y1);
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
    return poww(a, MOD - 2);
}
#define int ll
struct F
{
    int n;
    vector<int> t;
    F(int n) : n(n), t(n, 0) {}
    void upd(int v, int x)
    {
        for (int i = v; i < n; i |= i + 1)
        {
            t[i] += x;
        }
    }
    int get(int v)
    {
        int ret = 0;
        for (int i = v; i >= 0; i = (i & (i + 1)) - 1)
        {
            ret += t[i];
        }
        return ret;
    }
};
void solve(int n, vector<int> a)
{
    vector<int> where(n + 1, -1);
    for (int i = 0; i < 2 * n; i++)
    {
        if (a[i] != 0) {
            where[-a[i]] = i;
        }
    }
    F t(2 * n);
    set<int> f;
    for (int i = 0; i < 2 * n; i++)
    {
        if (a[i] == 0)
        {
            f.insert(i);
        }
    }
    for (int i = 1; i < n + 1; i++)
    {
        int pos = where[i];
        if (t.get(pos) > 0)
        {
            cout << "NO" << "\n";
            return;
        }
        auto it = f.lower_bound(pos);
        if (it == f.begin())
        {
            cout << "NO" << "\n";
            return;
        }
        it--;
        int pos1 = *it;
        f.erase(it);
        t.upd(pos1, +1);
        t.upd(pos, -1);
        a[pos1] = i;
    }
    if (true)
    {
        cout << "YES" << "\n";
        for (int i = 0; i < 2 * n; i++)
        {
            if (a[i] > 0) {
                cout << a[i] << ' ';
            }
        }
    }
    else {
        cout << "NO" << "\n";
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    vector<int> a;
    int t = 1;
    //cin >> t;
    while (t--)
    {
        cin >> n;
        a.resize(2 * n);
        for (int i = 0; i < 2 * n; i++)
        {
            char c;
            cin >> c;
            if (c == '-')
            {
                int x;
                cin >> x;
                a[i] = -x;
            }
        }
        solve(n, a);
    }
    return 0;
}