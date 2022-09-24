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
#define pf push_front
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 1e6;
const int N = 4e5 + 15;
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
ll n , l , r , k;
ll ans = -1;
ll diff;
ll cur  = 0 , now = 0;
ll val = MaXN , valn = N;
bool check()
{
    ll vx = k / max(1LL ,diff);
    ll vy = 2 * diff / k;
    if(vx >= 1 && vy >= 0)
    {
        if(k >= diff)
        {
            if(2 * diff >= k)
            {
                cur = k - diff;
                now = cur + n + 1 - diff;
                if(now >= 0)
                {
                    if(cur <= n)
                    {
                        if(now >= cur)
                        {
                            vx = min(now , n);
                            ans = max(ans , vx);
                            return 0;
                        }
                    }
                }
            }
        }
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n >> l >> r >> k;
    val = min(MaXN * 1LL, n) + 1;
    valn = min(N * 1LL , n) + 1;
    diff = r - l + 1 + n;
    MOD = n;
    diff %= MOD;
    ll x , y;
    gcd_eu(diff, n, x, y);
    
    for(ll i = 0; i < val; i++)
    {
        ll rp = diff + i;
        rp-= n;
        rp--;
        ll curdiff = diff + max(rp , 0LL);
        ll curdiffmin = min(diff * 2 , diff+ i);
        ll xdr = k % (i + n);
        if(xdr < curdiff) continue;
        if(xdr > curdiffmin) continue;
        ans = i;
    }
    //   cout << ans << endl;
    bool flag = check();
    //  cout << ans << endl;
    for(ll i = 1; i < valn; i++)
    {
        ll vx = k - i * n - diff;
        ll vy = vx + n + 1 - diff;
        vx /= i;
        vy /= (i + 1);
        now = min(vx , vy);
        ll lvx = k - i * n - diff + i;
        ll lvy = lvx - diff;
        lvy--;
        lvx /= (i + 1);
        lvy /= i;
        cur = max(lvy , lvx);
        if(now >= cur)
        {
            if(now >= 0)
            {
                if(cur <= n)
                {
                    //cout << now << "\n";
                    ll p = min(now , n);
                    ans = max(p , ans);
                }
            }
        }
    }
    if(l == r && r == 1 && n != l && k == 1)
    {
        cout << n;
        return 0;
    }
    if(l == r && r == 1 && n != l )
    {
        cout << 0;
        return 0;
    }
    if(!ans) ans++;
    cout << ans << "\n";
}