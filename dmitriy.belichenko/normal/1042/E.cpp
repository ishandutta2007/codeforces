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
ll MOD = 998244353;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 2e6 + 15;
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

int a[N];
ll dp[N];
pair<int, int> b[N];
void YA_EBAL_PIKMIKE_VOVUH_NE0N25_MIKEMRAZIYANOV()
{
    
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , m , r , c;
    cin >> n >> m;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[cnt];
            b[cnt] = mp(a[cnt] , cnt);
            cnt++;
        }
    }
    sort(b, b + m * n);
    cin >> r >> c;
    ll sv = 0, sx = 0, sy = 0 , l = 0;
    for (ll r = 0; r < n * m; r++)
    {
        while (b[l].fst < b[r].fst)
        {
            sum(sv , add(add(dp[b[l].snd] ,  mult(b[l].snd / m , b[l].snd / m)) , mult(b[l].snd % m , b[l].snd % m)));
            sum(sx ,  b[l].snd / m);
            sum(sy ,  b[l].snd % m);
            l++;
        }
        if (l == 0) continue;
        ll v = sv;
        int x = b[r].snd / m;
        int y = b[r].snd % m;
        sum(v , l * (mult(x , x)));
        sum(v , l * (mult(y , y)));
        sum(v ,  - mult(x ,2 * sx));
        sum(v ,  - mult(y ,2 * sy));
        dp[b[r].snd] = mult(v, (inv(l)));
    }
    cout << dp[(r - 1)*m+(c - 1)] << '\n';
    
}