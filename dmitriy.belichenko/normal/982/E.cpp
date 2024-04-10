
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
#define int ll
const double PI = acos(-1);
const int N = 5e5 + 17;
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

int if_zero(int n, int m, int x, int y, int speedx, int speddy)
{
    if (speedx == 0)
    {
        if (x % n)
        {
            cout << -1 << "\n";
        }
        else
        {
            int valy = m;
            if(speddy <= 0)
            {
                valy = 0;
            }
            cout << x << " " << valy << "\n";
        }
        return 0;
    }
    if (speddy == 0)
    {
        if (y % m)
        {
            cout << -1 << "\n";
        }
        else
        {
            int valx = n;
            if(speedx <= 0)
            {
                valx = 0;
            }
            cout << (valx) << " " << y;
        }
        return 0;
    }
    return 0;
}
int n, m, x, y, speedx, speddy;
pair<int, int> ans(ll speedx , ll speddy , ll n , ll m , ll cord , ll coed)
{
    int x1 , y1;
    if (speedx > 0)
    {
        x1 = n * (cord % 2);
    }
    else
    {
        x1 = n * ((cord + 1) % 2);
    }
    
    if (speddy > 0)
    {
        y1 = m * (coed % 2);
    }
    else
    {
        y1 = m * ((coed + 1) % 2);
    }
    return mp(x1 , y1);
}

bool debug = 0;
ll invar = -1;
int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> m >> x >> y >> speedx >> speddy;
    /*
           
     */
    if(speedx == 0 || speddy == 0)
    {
        if_zero(n , m , x , y , speedx , speddy);
        return 0;
    }
    ll cord, coed , valx , valy , calc;
    ll g = gcd(n, m, cord, coed);
    coed = -1 * coed;
    valx = x , valy = y;
    if(speedx <= 0) valx = n - valx;
    if(speddy <= 0) valy = m - y;
    ll c = valx - valy;
    calc = c / g;
    if (c % g != 0)
    {
        cout << -1 << "\n";
        return 0;
    }
    cord *= calc;
    coed *= calc;
    
    if (cord > 0)
    {
        ll rec = 1 - (-cord / (1LL * m / g));
        cord -= rec * (1LL * m / g);
        coed -= n / g * rec;
        if(debug)
        {
            cout << coed << " " << cord << "\n";
        }
    }
    //cout << cord << "\n";
    invar = inv(cord);
    ll invark = inv(coed);
    if (cord < 1)
    {
        ll rec = 1LL  -cord / (1LL * m / g);
        cord = cord +  rec * (1LL * m / g);
        coed = coed +  n / g * rec;
        if(debug)
        {
            cout << coed << " " << cord << "\n";
        }
    }
    if (coed < 1)
    {
        ll rec = -coed / (1LL * n / g) + 1;
        coed += rec * (1LL * n / g);
        cord = cord +  m / g * rec;
        if(debug)
        {
            cout << coed << " " << cord << "\n";
        }
    }
    if(debug == 1)
    {
        cout << invar << " " << invark;
    }
    pair<int, int> res = ans(speedx , speddy , n , m , cord , coed);
    cout << res.first << " " << res.second << "\n";
    return 0;
}