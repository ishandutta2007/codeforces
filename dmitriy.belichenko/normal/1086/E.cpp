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
#include <queue>
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
#define ld long double
#define mt make_tuple
#define fst first
const double PI = acos(-1);
// = 5e5 + 17;
ll MOD = 998244353;
const int INF = 1e9;
const int MaXN = 105;
const int N = 2e3 + 15;
const int maxlog = 18;
ld ecr = 1e-8;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
inline void sum(A &a, B b)
{
    a += b;
    if (a < 0LL) a += MOD;
    if (a >= MOD) a -= MOD;
}
inline ll add(ll a, ll b)
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
#define int ll
int n, now;
int b[N];
int c[2][N];
int a[N][N] , dp[N][N];
int st[N];

void inst(int *c,int x)
{
    for (; x < n + 1; x += x & -x)
    {
        c[x]++;
    }
}
int getsum(int *c,int x)
{
    int ans = 0;
    for (; x; x ^= x & -x)
    {
        ans += c[x];
    }
    return ans;
}
void add(int x)
{
    if (!x) return;
    b[x]++;
    if (b[x]==2)
    {
        now++;
        inst(c[0],x);
    }
}
int get_val(int x,int y)
{
    if (y<0 || y>x) return 0;
    else
    return dp[x][y];
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 1; j < n + 1; j++)
        {
            cin >> a[i][j];
        }
    }
    dp[0][0] = 1;
    st[0] = 1;
    for (int i = 1; i < n + 1; i++)
    {
        for (int j = 0; j < i + 1; j++)
        {
            if (j < 2)
            {
                int p = max(j - 1 , 0LL);
                dp[i][j] = mult(i - j , dp[i - 1][p]);
            }
            else
            {
                dp[i][j] = add(mult(dp[i - 1][j - 2] ,(j - 1)) , mult(dp[i - 1][j - 1] ,(-j + i)));
                //cout << dp[i][j] << " ";
            }
        }
        cout << "\n";
    }
    for (int i = 1; i < n + 1; i++)
    {
        st[i] = mult(st[i-1] , dp[n][n]);
    }
    int ans = 0;
    for (int i = 1; i < n + 1; i++)
    {
        for(int i = 0; i < N; i++)
        {
            b[i] = 0;
            c[0][i] = 0;
            c[1][i] = 0;
        }
        now = 0;
        for (int j = n; j > 0; j--)
        {
            add(a[i-1][j]);
            add(a[i][j]);
            inst(c[1],a[i][j]);
            int x = getsum(c[0] , a[i][j] - 1);
            int y = getsum(c[1] , a[i][j] - 1);
            y -= x;
            bool flag = (b[a[i-1][j]] == 2);
            int vx = n - j;
            ll val = mult(st[n - i], get_val(vx , now - flag - 1));
            ll valy = mult(st[n - i], get_val(vx , now - flag));
            ll val2 = -mult(st[n - i], get_val(vx, now - 2));
            sum(ans , mult(val, x));
            sum(ans , mult(valy, y));
            if (flag && a[i-1][j] && a[i - 1][j] < a[i][j])
            {
                sum(ans,val2);
            }
        }
    }
    cout << ans << "\n";
    return 0;
}