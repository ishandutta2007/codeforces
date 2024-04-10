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
ll MOD = 1e9 + 7;
const ll INF = 1e18 + 9;
const int MaXN = 26;
const int N = 1e6 + 5;
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

ll ans = 1;
int cur = 0;
int xa , xb , xc , xd;
void relax()
{
    cur = 0;
    xa = -1e9 - 5;
    xb = 1e9 + 5;
    xc = -1e9 - 5;
    xd = 1e9 + 5;
}
vector<pair<pair<int, int>, pair<int, int>>> a;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    relax();
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        pair<int, int> a1 = mp(x , y);
        cin >> x >> y;
        pair<int, int> a2 = mp(x , y);
        a.pb(mp(a1 , a2));
    }
   // cout << a.size() << "\n";
    // ->
    for(int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        if (a[cur].fst.fst < a[i].fst.fst)
        {
            cur = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        
        xa = max(xa, a[i].fst.fst);
        xc = max(xc, a[i].fst.snd);
        xb = min(xb, a[i].snd.fst);
        xd = min(xd, a[i].snd.snd);
    }
    if (xa <= xb && xc <= xd)
    {
        cout << xa << ' ' << xc << '\n';
        return 0;
    }
    //-------------
    relax();
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        if (a[cur].snd.fst > a[i].snd.fst)
        {
            cur = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        
        xa = max(xa, a[i].fst.fst);
        xc = max(xc, a[i].fst.snd);
        xb = min(xb, a[i].snd.fst);
        xd = min(xd, a[i].snd.snd);
    }
    if (xa <= xb && xc <= xd)
    {
        cout << xa << ' ' << xc << '\n';
        return 0;
    }
    relax();
    
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        if (a[cur].fst.snd < a[i].fst.snd)
        {
            cur = i;
        }
    }
    
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        xa = max(xa, a[i].fst.fst);
        xc = max(xc, a[i].fst.snd);
        xb = min(xb, a[i].snd.fst);
        xd = min(xd, a[i].snd.snd);
    }
    if (xa <= xb && xc <= xd)
    {
        cout << xa << ' ' << xc << '\n';
        return 0;
    }
    relax();
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        if (a[cur].snd.snd > a[i].snd.snd)
        {
            cur = i;
        }
    }
    for (int i = 0; i < n; i++)
    {
        if(i == cur) continue;
        xa = max(xa, a[i].fst.fst);
        xc = max(xc, a[i].fst.snd);
        xb = min(xb, a[i].snd.fst);
        xd = min(xd, a[i].snd.snd);
    }
    if (xa <= xb && xc <= xd)
    {
        cout << xa << ' ' << xc << '\n';
        return 0;
    }
    cout << "BUG!\n";
    return 0;
}