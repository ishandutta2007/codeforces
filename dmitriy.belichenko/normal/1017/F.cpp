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
unsigned int calc(unsigned int i,unsigned  int n)
{
    ll j = i;
    int t = 0;
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
const int N = 20000; //     N
const int S = 20000;
int n , a , b , c , d;
vector<int> pr;
int cnt;
bitset<N> p;
int main()
{
    unsigned int ans = 0;
    int n;
    cin >> n >> a >> b >> c >> d;
    int nsqrt = (int) sqrt (n + .0);
    for (int i=2; i<= N; ++i)
        if (!p[i]) {
            pr.pb(i);
            if (i * 1ll * i <= N)
                for (int j=i*i; j<=N; j+=i)
                    p[j] = true;
        }
    int result = 0;
    for (int p : pr)
        ans += calc(p, n) * (d + p * (c + p * (b + p * a)));
    for (int l=N,r =2*N;l<=n;l+=N,r+=N)
    {
        r = min(r, n + 1);
        p = 0;
        for (int pt : pr)
        {
            int prc = l / pt * pt;
            if (prc < l) prc += pt;
            for (int i = prc; i < r; i += pt)
                p[i - l] = 1;
        }
        for(int i = 0; i<(N+S)/2; i++)
        if (!p[i])
        {
            ans += (unsigned int) (calc(i+l,n)*(d+(i+l)*(c+(i+l)*(b+(i+l)*a))));
        }
    }
    cout << ans;
    return 0;
}