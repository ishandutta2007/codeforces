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
ll MOD = 998244353;
const int INF = 1e9;
const int MaXN = 105;
const int N = 1e6 + 15;
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
int lef[N] , rig[N];
int cnt = 0 , sm = 0;
bool flag;
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    int max = poww(10 , 6);
    vector<int> c(max , 0);
    while(n--)
    {
        sm = 0;
        flag = 1;
        string s;
        cin >> s;
        int x = s.size();
        for (int j = 0; j < x; j++)
        {
            if (s[j] == '(')
            {
                sm++;
            }
            if (s[j] == ')')
            {
                sm--;
            }
            if (sm < 0)
            {
                flag &= 0;
            }
        }
        if (flag)
        {
            if (sm != 0)
            {
                lef[sm]++;
            }
            if(sm == 0)
            {
                cnt++;
            }
        }
        else
        if (!flag)
        {
            reverse(s.begin(), s.end());
            flag = 1;
            sm = 0;
            for (int j = 0; j < x; j++)
            {
                if (s[j] == ')')
                {
                    sm++;
                }
                if (s[j] == '(')
                {
                    sm--;
                }
                if (sm < 0)
                {
                    flag &= 0;
                }
            }
            if (flag)
            {
                rig[sm]++;
            }
        }
    }
    c[0] = cnt;
    for (int i = 1; i < N; i++)
    {
        if(i == 1)
        {
            cnt /= 2;
        }
        cnt += min(lef[i], rig[i]);
    }
    cout << cnt << "\n";
    return 0;
}