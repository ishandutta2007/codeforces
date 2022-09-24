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
const int N = 3e3 + 10;
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
int n, k, dp1[2005][2005];
string s[2005];
set<int> dp[2];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> k;
    for(int i = 0; i < n; i++)
    {
        cin >> s[i];
        for(int j = 0; j < n; j++)
        {
            if(j > 0)
            {
                dp1[i][j] = max(dp1[i][j-1], dp1[i][j]);
            }
            if(i > 0)
            {
                dp1[i][j] = max(dp1[i-1][j], dp1[i][j]);
            }
            dp1[i][j] += (s[i][j] == 'a');
        }
    }
    dp[0] = {0};
    for(int i = 0; i < 2 * n - 1; i++)
    {
        dp[(i % 2) ^ 1].clear();
        bool ca = 0;
        for(int j = max(i - n + 1 , 0); j < min(i + 1, n); j++)
        {
            if(dp1[j][i - j] + k < i + 1)
            {
                continue;
            }
            ca = 1;
            if(j + 1 < n)
            {
                dp[(i % 2)^1].insert(j+1);
            }
            if(i - j + 1 <n)
            {
                dp[(i % 2)^1].insert(j);
            }
        }
        if(ca)
        {
            cout << 'a';
            continue;
        }
        char st = 'z';
        for(int a : dp[(i % 2)])
        {
            st = min(s[a][i - a], st);
        }
        cout << st;
        for(int a : dp[(i % 2)])
        {
            if(s[a][i - a] != st)
            {
                continue;
            }
            if(a + 1 < n)
            {
                dp[(i % 2)^1].insert(a + 1);
            }
            if(i - a + 1 < n)
            {
                dp[(i % 2)^1].insert(a);
            }
        }
    }
}