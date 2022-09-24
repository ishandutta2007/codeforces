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
const int N = 2e5 + 15;
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

bool used[N];
#define int long long
ll a[N];
vector<ll> b;
ll check(ll a , int p)
{
    if(p == 2)
    {
        double x = sqrt(a);
        ll u = x;
        for(ll t = max(0LL , u - 10); t <= u + 10; t++)
        {
            if(t * t == a) return t;
        }
        return 0;
    }
    if(p == 4)
    {
        double x = sqrt(sqrt(a));
        ll u = x;
        for(ll t = max(0LL , u - 10); t <= u + 10; t++)
        {
            if(t * t * t * t == a) return t;
        }
        return 0;
    }
    if(p == 3)
    {
        double x = pow(a , 1.0 / 3.0);
        ll u = x;
        for(ll t = max(0LL , u - 10); t <= u + 10; t++)
        {
            if(t * t * t == a) return t;
        }
        return 0;
    }
    return 0;
}
set<ll> divs;
ll ans = 1;
vector <pair <ll, int> > dp;

void calc_fir(int m , int n)
{
    for (int i = 0; i < m; i++)
    {
        int cnt = 0;
        for (int j = 0; j < n; j++)
        {
            while (a[j] % b[i] == 0)
            {
                a[j] = a[j] / b[i];
                used[j] = 1;
                cnt++;
            }
        }
        ans = mult(ans, cnt + 1);
    }
    b.clear();
    divs.clear();
}
void recalc_b(int n , int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            ll x = a[i];
            ll y = a[j];
            ll gc = gcd(x, y);
            if (gc != 1 && gc != x && gc != y)
            {
                divs.insert(gc);
            }
        }
    }
    for(auto i : divs)
    {
        b.pb(i);
    }
    calc_fir(divs.size(), n);
}
int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
//    ll t = 1e18;
//    cout << check(t, 2) << " " << check(t, 3) << " " << check(t, 4) << "\n";
    for(int i = 0; i < n; i++)
    {
        ll x , y , z;
        x = check(a[i], 2);
        y = check(a[i], 3);
        z = check(a[i], 4);
        if(x) divs.insert(x);
        if(y) divs.insert(y);
        if(z) divs.insert(z);
    }
    int m = divs.size();
    for(auto i : divs) b.pb(i);
    calc_fir(m , n);
  //  cout << ans << " ";
    recalc_b(n, m);
 //   cout << ans << "\n";
    for (int i = 0; i < n; i++)
    {
        if (a[i] != 1)
        {
            dp.pb(mp(a[i], i));
        }
    }
    sort(dp.begin(), dp.end());
    
    int i = 0;
    m = dp.size();
    while (i < m)
    {
        int r = i;
        for(r = i; dp[i].fst == dp[r].fst; r++);
        ll val = r - i + 1;
        if (used[dp[i].snd])
            ans = mult(ans , val);
        else
            ans = mult(ans, mult(val, val));
        i = r;
    }
    
    cout << ans << endl;
}