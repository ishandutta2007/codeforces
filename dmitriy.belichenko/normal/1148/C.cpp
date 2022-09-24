#pragma GCC optimize("Ofast")
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
ll MOD = 1e9 + 7;
const int INF = 1e9;
const int MaXN = 105;
const int N = 3e5 + 1000;
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
int b[N];
int n;
vector<int> x , y;
void query(int p , int q) // p < q !!!
{
    swap(b[a[p]] , b[a[q]]);
    swap(a[p] , a[q]);
    x.pb(p);
    y.pb(q);
}
void ask(int p , int q)
{
    int c = min(p , q);
    q = max(p , q);
    p = c;
    //2 (p - q) >= n -> (p , q)
    if(2 * abs(p - q) >= n )
    {
        query(p, q);
        return;
    }
    // 2 max(p , q) <= n  -> (p , n) (q , n) (p ,  n)
    if(2 * q <= n)
    {
        //cout << "2max <= n : " << "p = " << p << " " << "q = " << q << "\n";
        query(p, n);
        query(q, n);
        query(p, n);
        return;
    }
    // last -> (p , n) (1 , n) (1 , q) (1 , n) (p , n)
    if(2 * p <= n)
    {
        //cout << "last : " << "p = " << p << " " << "q = " << q << "\n";
        query(p, n);
        query(1, n);
        //query(p, n);
        query(1, q);
        //query(p, n);
        query(1, n);
        query(p, n);
        return;
    }
    query(1, p);
    query(1, q);
    query(1, p);
    return;
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    // p - q >= n / 2 -> (p , q)
    // max(p , q) <= n / 2 -> (p , n) (q , n) (p ,  n)
    // min(p , q) > n / 2 -> (1 , p) (1 , q) (1 , p)
    // last -> (p , n) (1 , n) (1 , q) (1 , n) (p , n)
    for(int i = 1; i < n + 1; i++)
    {
        cin >> a[i];
        b[a[i]] = i;
    }
    for(int i = 1; i < n + 1; i++)
    {
        if(b[i] != i)
        {
            ask(b[i] , i);
            // b[i] < i ?
        }
    }
    assert(x.size() == y.size());
    cout << x.size() << "\n";
    for(int i = 0; i < x.size(); i++)
    {
        cout << x[i] << " " << y[i] << "\n";
    }
    return 0;
}