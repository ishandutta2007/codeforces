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
const int N = 1e5 + 5;
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
int x[N] , y[N];

ll triangle_area_2 (int x1, int y1, int x2, int y2, int x3, int y3) {
    return (ll)((x2 - x1) * (y3 - y1) - (y2 - y1) * (x3 - x1));
}

int ask(int pos)
{
    cout << "? " << pos + 1 << endl;
    int ans;
    cin >> ans;
    return ans;
}

int q, n;

int quest(int pos)
{
    int a = ask(pos);
    int b = ask(pos + n / 2);
    if(a == b)
    {
        cout << "! " << pos + 1 << endl;
        exit(0);
    }
    if(a > b) return 1;
    else return -1;
}


void rec(int l, int r)
{
    if(r - l < 2)
    {
        quest(l);
        quest(r);
    }
    int m = (l + r) / 2;
    int ans = quest(m);
    if(q > 0)
    {
        if(ans > 0)
        {
            rec(m, r);
        }
        else
        {
            rec(l, m);
        }
    }
    if(ans > 0)
    {
        rec(l, m);
    }
    else
    {
        rec(m, r);
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cout.tie(0);
    cin.tie(0);
    cin >> n;
    if(n % 4)
    {
        cout << "! -1" << endl;
        return 0;
    }
    q = quest(0);
    rec(0 , n / 2);
    return 0;
}