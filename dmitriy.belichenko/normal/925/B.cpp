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
const int N = 3e5 + 7;
ll MOD = 1e9 + 7;
const int INF = 1e9 + 9;
const int MAXN = 26;
const int maxlog = 18;
const int maxn = 1 << maxlog;
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
    ll res = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (res < 0) {
        res += MOD;
    }
    if (res >= MOD) {
        res -= MOD;
    }
    return res;
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
int a[N];
pair<int, int> b[N];
int p , q , n , x1 , x2;
int srch(int i, int x)
{
    int l = 0;
    int r = n;
    while (r - l > 1)
    {
        int m = (l + r) / 2;
        if ((x + m - 1) / m < (b[i].fst + 1))
        {
            r = m;
        }
        else l = m ;
    }
    
    return r;
}
void calc_pq()
{
    for (int i = n - 1; i >= 0; i--)
    {
        if (i + srch(i, x1) <= n && p == INF) p = i;
        if (i + srch(i, x2) <= n && q == INF) q = i;
    }
}
void YES_x1(int i)
{
    cout << "Yes\n";
    cout <<  srch(i, x1) << " " << n - q << "\n";
    int r =  srch(i, x1);
    for (int j = i; j < i + r; j++)
        cout << b[j].snd << " ";
    cout << "\n";
    for (int j = q; j < n; j++)
        cout << b[j].snd << " ";
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n >> x1 >> x2;
    p = INF , q = INF;
    poww(n , MOD);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < n; i++)
    {
        b[i] = mp(a[i] , i + 1);
    }
    sort(b , b + n);
    calc_pq();
    for (int i = 0; i < n; i++)
    {
        if (q > i + srch(i, x1) - 1)
        {
            YES_x1(i);
            return 0;
        }
        if (p > i + srch(i, x2) - 1)
        {
            cout << "Yes\n";
            cout << n - p << " " << srch(i, x2) << "\n";
            int r =  srch(i, x2);
            for (int j = p; j < n; j++)
                cout << b[j].snd << " ";
            cout << "\n";
            for (int j = i; j < i + r; j++)
                cout << b[j].snd << " ";
            return 0;
        }
    }
    cout << "No" << "\n";
    return 0;
}