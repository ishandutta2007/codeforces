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
const int N = 3e5 + 15;
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

int main()
{
    int n;
    cin >> n;
    set<int> q;
    int g = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        if (t == 1)
        {
            cout << 1 << "\n";
            return 0;
        }
        g = gcd(g, t);
        int j = 1;
        for (int k = 2; k * k <= t; k++)
            if (t % k == 0)
            {
                while (t % k == 0)
                {
                    t /= k;
                }
                j *= k;
            }
        j *= t;
        q.insert(j);
    }
    if (g != 1)
    {
        cout << -1 << "\n";
        return 0;
    }
    vector<int> a;
    for (int i : q)
    {
        a.push_back(i);
    }
    n = q.size();
    vector<int> dp_div(N, 0);
    for (int i : a)
    {
        for (int j = 1; j * j < i; j++)
            if (i % j == 0)
            {
                dp_div[j]++;
                dp_div[i / j]++;
            }
        int quad = 1;
        while (quad * quad < i)
        {
            quad++;
        }
        if (quad * quad == i)
        {
            dp_div[quad]++;
        }
    }
    vector<vector<int> > b(n);
    for (int i = 0; i < n; i++)
    {
        int j = a[i];
        for (int k = 2; k * k <= j; k++)
        {
            if (j % k == 0)
            {
                j /= k;
                b[i].pb(k);
            }
        }
        if (j != 1)
        {
            b[i].pb(j);
        }
    }
    for (int ans = 2; ; ans++)
    {
        vector<vector<int> > vct;
        for (int i = 0; i < b.size(); i++)
        {
            int k = b[i].size();
            int B = (1 << k);
            vector<int> dp2(B, 0), dp = dp2;
            dp[0] = 1;
            for (int j = 1; j < B; j++)
            {
                int ind = 0;
                while (!((j >> ind) & 1))
                {
                    ind++;
                }
                dp[j] = dp[(j ^ (1 << ind))] * b[i][ind];
                
            }
            for (int j = 0; j < B; j++)
            {
                dp2[j] = dp_div[dp[j]];
            }
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < B; j++)
                {
                    if (((j >> i) & 1))
                    {
                        dp2[j - (1 << i)] -= dp2[j];
                    }
                }
            }
            if (dp2[0])
            {
                cout << ans << "\n";
                return 0;
            }
            for (int ind = 0; ind < B; ind++)
            {
                if (dp2[ind])
                {
                    vector<int> xc;
                    for (int j = 0; j < k; j++)
                    {
                        if (((ind >> j) & 1))
                        {
                            xc.pb(b[i][j]);
                        }
                    }
                    vct.pb(xc);
                }
            }
        }
        sort(vct.begin(), vct.end());
        b.clear();
        for (int i = 0; i < vct.size(); i++)
        {
            if (!i || vct[i - 1] != vct[i])
            {
                b.pb(vct[i]);
            }
        }
    }
    return 0;
}