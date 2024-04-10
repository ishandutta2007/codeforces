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
const int N = 4e5 + 17;
ll MOD = 998244353;
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
ll ans = 0;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    ll n , CNK = 1;
    cin >> n;
    ll cur = poww(3 , n * n);
    ll ml = poww(3 , n);
    ml = add(ml, -3);
    ml = poww(ml , n);
    sum(cur , -ml);
    cur = mult(cur, 2LL);
    sum(ans , cur);
  //  cout << ans << "\n";
    for(int i = 1; i <= n; i++)
    {
        cur = -3;
        int mlt = i % 2;
        if(mlt == 1) mlt-= 2;
        else mlt++;
        cur = mult(cur , mlt);
        CNK = mult(mult(CNK, n - i + 1) , inv(i));
       // cout << CNK << "\n";
        cur = mult(cur, CNK);
   //     cout << cur << "\n";
        ll ptr = poww(3 , n - i);
        sum(ptr , -1);
        ptr = poww(ptr , n);
        ll mns = poww(3 , (n - i) * n);
        sum(ptr , -mns);
        cur = mult(cur , ptr);
        sum(ans , cur);
    }
    cout << ans << "\n";
}