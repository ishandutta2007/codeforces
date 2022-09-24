#pragma ("fastmath")
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
const int N = 6e5 + 15;
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
long long solve_by_PULYA(int n , vector<ll> &a , int m , vector<ll> &b)
{
    //ll n, m; cin >> n;
    //vector<ll>a(n);
    ll sum1 = 0;
    ll sum2 = 0;
    for (ll i = 0; i < n; i++) {
        //cin >> a[i];
        sum1 += a[i];
    }
    //  cin >> m;
    //vector<ll>b(m);
    for (ll i = 0; i < m; i++) {
        // cin >> b[i];
        sum2 += b[i];
    }
    if (sum1 != sum2) {
        return  -1;
        return 0;
    }
    ll i = 0;
    ll j = 0;
    ll sm1 = a[0];
    ll sm2 = b[0];
    ll ans = 0;
    while (i < n && j < m) {
        while (sm1 != sm2) {
            if (sm1 < sm2) {
                i++;
                sm1 += a[i];
            }
            else {
                j++;
                sm2 += b[j];
            }
        }
        ans++;
        i++;
        j++;
        if(i<n) sm1 = a[i];
        if(j<m) sm2 = b[j];
    }
    
    //cout << ans;
    return ans;
}
long long solve(int n , vector<ll> &a , int m , vector<ll> &b)
{
    
    long long int suma=0,sumb=0;
    for (int i=0;i<n;i++){suma+=a[i];}
    for (int i=0;i<m;i++){sumb+=b[i];}
    if (suma==sumb)
    {
        suma=0;
        sumb=0;
        int res=0;
        int i=0,j=0;
        while(i<n||j<m)
        {
            if (suma<sumb)
                suma+=a[i++];
            else if (sumb<suma)
                sumb+=b[j++];
            else if (suma==sumb)
            {
                res++;
                suma+=a[i++];
                sumb+=b[j++];
            }
        }
        return  res;
    }
    else
    {
        return  -1;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n , m;
    cin >> n;
    vector<ll> a(n)  , b;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    cin >> m;
    b.resize(m);
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    cout << solve(n, a, m, b) << "\n";
}