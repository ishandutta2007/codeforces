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
const int MaXN = 105;
const int N = 1e6 + 1000;
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
 
vector<string> ch;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m;
    cin >> n >> m;
    bool used[n][m];
    bool up[n][m], L[n][m];
    int dp[n][m];
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
           dp[i][j] = up[i][j] = L[i][j] = used[i][j] = 0;
    used[0][0] = 1;
    ch.resize(n);
    for(int i = 0; i < n; i++)
        cin >> ch[i];
    
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if((i > 0 || j > 0) && ch[i][j] == '.')
            {
                if(j >= 1 && used[i][j - 1])
                {
                    used[i][j] = L[i][j] = 1;
                }
                if(i >= 1 && used[i - 1][j])
                {
                    used[i][j] = up[i][j] = 1;
                }
            }
        }
    }
    if(!used[n - 1][m - 1])
    {
        cout << 0 << "\n";
        return 0;
    }
    int x = n , y = m;
    x--, y--;
    while(x + y > 0)
    {
        dp[x][y]++;
        if(up[x][y]) x = x - 1;
        else y = y - 1;
    }
    
 //   int
    x = n , y = m;
    x--, y--;
    while(x + y > 0)
    {
        dp[x][y]++;
        if(!L[x][y]) x = x - 1;
        else y = y - 1;
    }
    
    if(!used[n - 1][m - 1])
    {
        cout << 0 << "\n";
        return 0;
    }
    dp[n - 1][m - 1] = -1;
    // dp[i][j] == 2 -> 1
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(dp[i][j] == 2)
            {
                cout << 1 << "\n";
                return 0;
            }
        }
    }
    // last case ans = 2
    cout << 2 << "\n";
    return 0;
}