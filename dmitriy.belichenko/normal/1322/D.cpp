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
const int MaXN = 150;
const int N = 1e5 + 1000;
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
int n , m, sz;
int l[N], s[N], c[N];
int x[N];
vector<vector<int>> ans;
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        cin >> l[i];
        x[--l[i]]++;
    }
    for(int i = 0; i < n; i++) cin >> s[i];
    for(int i = 0; i < n + m; i++) cin >> c[i];
    for(int i = 0; i < n + m - 1; i++)
    {
        int pref = (x[i] >> 1);
        x[i + 1] += pref;
    }
    sz = n + m;
    for(int i = 0; i < n + m; i++)
    {
        if(!x[i])
        {
            sz = i;
            break;
        }
    }
    sz++;
    sz = n +  m;
    
    //   0
    while (!x[sz - 1] ) sz--;
    sz++;
    
    ans.resize(sz + 100);
    //cout << sz << " ";
    for(int i = 0; i < sz; i++)
    {
        ans[i].pb(0);
        for(int j = 0; j < x[i]; j++) ans[i].pb(-INF);
    }
    
    for (int i = 0; i < n ; i++)
    {
        int index = l[n - i - 1];
        int UP = x[index];
        UP--;
        for (int j = UP; j >= 0; j--) ans[index][j + 1] = max(ans[index][j] - s[n - i - 1], ans[index][j + 1]);
        
        for (int j = 0; j < sz - 1; j++)
        {
            for (int cnt = 0; cnt < x[j] + 1; cnt++)
            {
                int forward_ind = (cnt >> 1);
                int impact_knapsack = c[j] * cnt;
                int new_frv = ans[j][cnt] + impact_knapsack;
                ans[j + 1][forward_ind] = max(new_frv, ans[j + 1][forward_ind]);
            }
        }
    }
    cout << ans[sz - 1][0] << "\n";
    return 0;
}