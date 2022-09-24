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
#define snd second
#define ins insert
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 105;
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
#define int ll
int n, k , pq , qq , p;
int a[N];
struct Matrix
{
    int n, m;
    int a[500][500];
    void clear()
    {
        n = m = 0;
        for(int i = 0; i < 104; i++)
        {
            for(int j = 0; j < 104; j++)
            {
                a[i][j] = 0;
            }
        }
    }
    Matrix operator *(const Matrix &b) const
    {
        Matrix ce;
        ce.clear();
        ce.n = n;
        ce.m = b.m;
        for (int i = 0; i < n + 1; i++)
            for (int j = 0; j < b.m + 1; j++)
                for (int k = 0; k < m + 1; k++)
                    ce.a[i][j] = (ce.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        return ce;
    }
} s, ans;
void calc()
{
    while (k > 0)
    {
        if (k & 1)
            ans = ans * s;
        s = s * s;
        k >>= 1;
    }
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i + 1];
    }
    for (int i = 1; i <= n; i++)
    {
        if (a[i] == 1)
        {
            qq++;
        }
        else
        {
            pq++;
        }
    }
    for (int i = 1; i < pq + 1; i++)
    {
        if (a[i] == 1)
        {
            p++;
        }
    }
    for (int i = 0; i <= min(pq, qq); i++)
    {
        s.a[i][i] = (pq * (pq - 1) / 2 + (qq) *
                     (qq - 1) / 2 + (qq - i) * i + i *
                     (pq - i)) * inv(n * (n - 1) / 2);
        sum(s.a[i][i] , 0);
        s.a[i][i] %= MOD;
    }
    for (int i = 0; i < min(pq, qq); i++)
    {
        s.a[i][i + 1] = mult((qq - i) * (pq - i) , inv(n * (n - 1) / 2));
        s.a[i][i] %= MOD;
    }
    for (int i = 1; i <= min(pq, qq); i++)
    {
        s.a[i][i - 1] = mult(i * i  , inv(n * (n - 1) / 2));
    }
    ans.a[0][p] = 1;
    
    s.n = s.m = 100;
    ans.n = ans.m = 100;
    calc();
    
    cout << add(ans.a[0][0] , 0) % MOD << "\n";
    return 0;
}