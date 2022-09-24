#pragma GCC optimize("Ofast")
#pragma comment(linker, "/STACK:1000000000")
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
const int MaXN = 322;
const int N = 2e5 + 11;
const int LOG = 25;
const int FACT = 120;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_real_distribution<ld> nextTand(0, 1);
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
int gcd(ll a, ll b, ll & x, ll & y) {
    if (a == 0) {
        x = 0; y = 1;
        return b;
    }
    ll x1 = 0, y1 = 0;
    ll d = gcd(b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}

const ld eps = 1e-9;
vector<int> g[N];
int P = (MOD + 1) / 2;
int T = 1;
int dp[MaXN][MaXN][2];
ll layer[MaXN][2];
void dfs(int u, int p) {
    
    for (int j = 0; j < T + 1; j++) {
        for (int i = 0; i < 2; i++) {
            if (i != (j == T || j == 0)) {
                dp[u][j][i] = 0;
            }
            else {
                if (j == T) {
                    dp[u][j][i] = MOD / 2;
                } else {
                    dp[u][j][i] = (j == 0) ? 1 : P;
                }
            }
        }
    }
    
    for (auto v : g[u]) {
        if (v == p) continue;
        dfs(v, u);
        for (int j = 0; j < T + 1; j++) {
            layer[j][0] = layer[j][1] = 0;
        }
        
        for (int j = 0; j < T + 1; j++) {
            for (int i = 0; i < 2; i++) {
                for (int k = j - 1; k <= j + 1; k++) {
                    if (k < 0 || k > T)  {
                        continue;
                    }
                    ll val = dp[v][k][1] + (j == k + 1 ? dp[v][k][0] : 0);
                    sum(layer[j][i | (k == j + 1)], mult(val, dp[u][j][i]));
                    //layer[j][i | (k == j + 1)] += val * dp[u][j][i];
                }
            }
        }
        
        for (int j = 0; j <= T; j++) {
            for (int i = 0; i < 2; i++) {
                dp[u][j][i] = layer[j][i];
            }
        }
    }
}

int32_t main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 1; i < n; i++) {
        int v, u;
        cin >> u >> v;
        g[u].pb(v);
        g[v].pb(u);
    }
    int ans = 0;
    for (T = 1; T < n + 1; T++) {
        dfs(1, 1);
        for (int j = 0; j < T + 1; j++) {
            sum(ans, -dp[1][j][1]);
        }
        sum(ans, 1);
    }
    sum(ans, poww(P, n));
    sum(ans, -1);
    cout << ans << "\n";
    
    return 0;
}