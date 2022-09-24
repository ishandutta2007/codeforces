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
int c = 0;
int a[N];
int dp1[N], dp2[N] , res[N];
set <int> cr;
bool flag = 0;
int cur = -1;
void relax(int i)
{
    if (dp2[i] == -1)
    {
        if (cur == -1 && (!flag|| flag))
        {
            cout << "NO\n";
            exit(0);
        }
        else
        {
            dp1[i] = dp2[i] = cur;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n , q;
    cin >> n >> q;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    //    memset(dp2 + 1, -1 , q);
    //    memset(dp1 + 1, n + 1 , q);
    dp2[0] = 0;
    for(int i = 0; i < q; i++)
    {
        dp2[i + 1] = -1;
    }
    for(int i =0 ; i < q; i++)
    {
        dp1[i + 1] = n + 1;
    }
    for(int i = 0; i < n; i++)
    {
        dp1[a[i]] = min(dp1[a[i]], i);
        dp2[a[i]] = max(dp2[a[i]], i);
    }
    for(int i = 0; i < n; i++)
    {
        cr.insert(i);
    }
    for(int i = 0; i < n; i++)
    {
        if (a[i] != 0)
        {
            res[i] = a[i];
        }
        else
        {
            cur = i;
            flag++;
        }
        if(a[i] < 0)
        {
            cur = 0;
            cout << "debug\n";
            return 0;
        }
    }
    for (int i = q; i >= 1; i--)
    {
        if (dp2[i] == -1 && cur == -1)
        {
            cout << "NO\n";
            return 0;
        }
        relax(i);
        auto ind = cr.lower_bound(dp1[i]);
        while (ind != cr.begin())
        {
            auto cpy = ind;
            cpy--;
            if (!a[*cpy])
                ind--;
            if(a[*cpy])
                break;
        }
        
        while (ind != cr.end() && (*ind) <= dp2[i] && ind != cr.end())
        {
            auto cpy = ind;
            cur = (*ind);
            if (a[*ind] == 0)
            {
                res[*ind] = i;
                ind++;
            }
            else
                if (a[*ind] != i)
                {
                    cout << "NO" << "\n";
                    return 0;
                }
                else
                {
                    ind++;
                }
            cr.erase(cpy);
        }
        while (!a[*ind] && ind != cr.end())
        {
            auto cpy = ind;
            res[*ind] = i;
            ind++;
            cr.erase(cpy);
            auto x = ind;
            if(x != ind )
            {
                cpy++;
                if(cpy != ind)
                {
                    cout << "agshdhas" << "\n";
                    exit(0);
                }
            }
        }
    }
    
    cout << "YES\n";
    for (int i = 0; i < n; i++)
    {
        cout << res[i] << " ";
    }
    
}