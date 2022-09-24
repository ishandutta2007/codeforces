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
int n , a , b;
string s;
ll dp[5005][5005];
ll dp2[N];
void gen()
{
    srand(time(0));
    n = rand() % 5 + 1;
    a = rand() % n + 1;
    b = rand() % n + 1;
    for(int i = 0; i < n; i++)
    {
        s.pb((char)('a' + rand() % 3));
    }
}
void pre()
{
    ll c = poww(2 , 228);
    for(int i = 1; i < N; i++)
    {
        dp2[i] = INF;
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            dp[i][j] = 0;
        }
    }
    dp2[0] = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            int u = n - i - 1;
            int v = n - j - 1;
            if(s[u] == s[v])
            {
                dp[u][v] = max(dp[u + 1][v + 1] , 1 + dp[u + 1][v + 1]);
            }
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    gen();
    cin >> n >> a >> b >> s;
    pre();
    for (int i = 0; i < n; i++)
    {
        ll u = dp2[i] + a;
        ll v = dp2[i] + b;
        ll cur = 0;
        for (int j = 0; j < i + 1; j++)
        {
            cur = max(cur, min(1LL * (i - j), dp[i][j]));
        }
        dp2[i + 1] = min(dp2[i + 1], u);
        for (int j = 0; j < cur; j++)
        {
            int nxt = i + j + 1;
            dp2[nxt] = min(dp2[nxt], v);
        }
    }
    cout << dp2[n] << "\n";
    return 0;
}