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
#define fst firs
const double PI = acos(-1);
const int N = 5e6 + 17;
ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MAXN = 26;
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
ll mult(ll a, ll b)
{
    ll res = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (res < 0)
    {
        res += MOD;
    }
    if (res >= MOD)
    {
        res -= MOD;
    }
    return res;
}
ll gcd (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
}
long long poww(long long a, long long b)
{
    long long res = 1;
    a %= MOD;
    while (b > 0)
    {
        if (b % 2) res = mult(a, res);
        a = mult(a, a);
        b >>= 1;
    }
    return res % MOD;
}
ll inv(ll a)
{
    return poww(a , MOD - 2);
}
int a[N];
bool used[N] , ans[N];
int xr;
int n , m;
void dfs(int u)
{
    used[u] = 1;
    for(int i = 0; i < n; i++)
    {
        int p = u >> i & 1; // ->
        int q = u ^ (1 << i); // <-
        if(p == 1 && !used[q])
        {
            dfs(q);
        }
    }
    // x -> inv(x)
    if(ans[u])
    {
        if(!used[u ^ xr])
        {
            dfs(u ^ xr);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m;
    xr = 1 << n;
    xr--;
    int cnt = 0;
    for(int i = 0; i < m; i++)
    {
        cin >> a[i];
        ans[a[i]] = 1;
    }
    for(int i = 0; i < (1 << n); i++)
    {
        if(ans[i] == 1 && !used[i])
        {
            dfs(i);
            cnt++;
        }
    }
    cout << cnt << "\n";
    return 0;
}