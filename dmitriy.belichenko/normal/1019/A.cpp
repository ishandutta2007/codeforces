#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
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
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 2e5 + 5;
const int maxlog = 18;
ld eps = 1e-8;
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
int c[N] , p[N];
vector<pair<int, int>> g[N];
vector<pair<int, int>> g1;
ll dp[N];
int n , m;
bitset<N> used;
ll val = INF;
ll dfs(int cnt)
{
    if (cnt == 0)
    {
        return -1;
    }
    used = 0;
    ll ans = 0;
    int r = cnt - g[0].size();
    for (int i = 1; i < m; i++)
    {
        int cur = g[i].size();
        r -= max(0,  cur - cnt + 1);
        for (int j = 0; j <  cur - cnt + 1; j++)
        {
            ans += g[i][j].fst;
            used[g[i][j].snd] = 1;
        }
    }
    if(r < 0) return r;
    
    for (int i = 0; i < g1.size(); i++)
    {
        if(!r) break;
        if (!used[g1[i].snd])
        {
            r--;
            ans = ans + 1LL * g1[i].fst;
        }
    }
    return ans;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    cin >> n >> m;
    //  2 4 8 16 32 
    if(n < 0)
    {
        for(int i = 0; i < n; i++)
      //  {
            cout << i << " " << poww(2 , i) << "\n";
     //   }
    }
    for(int i = 0; i < n; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        p[i] = u;
        c[i] = v;
        g[u].pb(mp(v , i));
        if(!u) continue;
        g1.pb(mp(v , i));
    }
    int x = g[0].size();
    for(int i = 0; i < m; i++)
    {
        sort(g[i].begin() , g[i].end());
    }
    sort(g1.begin(), g1.end());
    
    for (int i = x; i < n + 1; i++)
    {
        ll ans = dfs(i);
        if (ans >= 0)
        {
            val = min(val, ans);
        }
    }
    cout << val << "\n";
    return 0;
}