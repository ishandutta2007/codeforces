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
const int N = 6e3 + 17;
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
int dp[N][N] , dp2[N][N];
int dfs(int p , int q)
{
    if(dp[p][q] != -INF) return dp[p][q];
    if(q > 0)
    {
        int xr =  dfs(p, q - 1) ^ dfs(p + 1 , q - 1);
        return dp[p][q] = xr ;
    }
    else
    {
        dp[p][q] = a[p];
        return a[p];
    }
}
int calc(int p , int q)
{
    if(dp2[p][q] != -INF) return dp2[p][q];
    if(p - q)
    {
        dp2[p][q] = max(dp2[p][q] , dp[p][q - p]);
        int mx = max(calc(p, q - 1) , calc(p + 1 , q));
        dp2[p][q] = max(dp2[p][q] , mx);
    }
    else
    {
        dp2[p][q] = dp[p][q - p];
    }
    return dp2[p][q];
}
int n;
void precalc()
{
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            dp[i][j] = dp2[i][j] = -INF;
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n - i; j++)
        {
            dfs(j, i);
       //     cout << j << " " << i << "\n";
        }
    }
    if(n == 0)
    {
        for(int i = 0; i < N; i++)
        {
            for(int j = 0; j < N; j++)
            {
                cout << dp[i][j] << " ";
            }
            cout << "\n";
        }
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0 ; j < n - i; j++)
        {
            int sm = i + j;
          //  cout << j << " " << j + i << "\n";
          //  cout << j << " " << i << "\n";
            calc(j, sm);
            
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int q;
    cin >> q;
    precalc();
    for(int i = 0; i < q; i++)
    {
        int l , r;
        cin >> l >> r;
        cout << dp2[l - 1][r - 1] << "\n";
    }
    return 0;
}