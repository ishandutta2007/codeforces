#pragma("sse4")
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
const int N = 2e5 + 5;
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
const int p = 2200;
set<ll>  b;
void relax(int k)
{
    // a.clear();
    b.erase(k);
}
bool check_zero(ll k , const set<ll> &c)
{
    // auto last = (*b.rbegin());
    if (b.count(k) && ((*b.rbegin()) != k))
    {
        cout << 0 << "\n";
        exit(0);
        return 0;
    }
    if (c.count(k) && (*c.begin()) != k)
    {
        cout << 0 << "\n";
        exit(0);
        return 0;
    }
    return 1;
}
int a[N];
set<int> x;
vector<ll> res(N , 0);
inline void forward(int cur  , int n)
{
    for (int i = cur - 1; i >= 0; i--)
    {
        int val = i - 1;
        if (i == 0) val = n - 1;
        res[i] = a[i];
        
        while (res[i] <= a[val])
            res[i] += res[i + 1];
    }
}
inline void back(int cur  , int n)
{
    for (int i = n - 1; i > cur; i--)
    {
        int val = i + 1;
        if (val == n) val %= n;
        res[i] = a[i];
        while (res[i] <= a[i - 1])
            res[i] += res[val];
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int mx = 0;
    int m = n;
    mult(m , 2);
    MOD = n;
    int mxx = 0;
    for(int i = 0 ; i < n; i++)
    {
        cin >> a[i];
        mx = max(a[i] , mx);
        if(x.size() < 1)
            x.insert(a[i]);
    }
    if(mx == 0)
    {
        cout << "YES" << "\n";
        for(int i = 0; i < n; i++)
            cout << 1 << " ";
        return 0;
    }
    for(int i = 0; i < n; i++)
    {
        int val = i + 1;
        if(val > n - 1) val = 0;
        if(a[i] != a[val])
        {
            mxx = -1;
            break;
        }
    }
    if(mxx == 0)
    {
        cout << "NO" << "\n";
        return 0;
    }
    int cur = -1;
    for (int i = 0; i < n; i++)
    {
        int val = (i + 1);
        if(val > n - 1) val = 0;
        if (a[i] < a[(val)])
        {
            cur = val;
            break;
        }
    }
    if (n < 3)
    {
        res[1 - cur] = a[1 - cur] + a[(1 - cur) ^ 1];
        for (int i = 0; i < n; i++)
        {
            if(1 - cur != i)
            res[i] = a[i];
        }
        
    }
    else
    {
        res[cur] = a[cur];
        forward(cur , n);
        back(cur , n);
    }
    cout << "YES" << "\n";
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    
    return 0;
}