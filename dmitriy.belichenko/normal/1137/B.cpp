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
const int N = 100;
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
int a[N][N];
int mx1[N][N];
int mx2[N][N];
int mp1[N][N];
int mp2[N][N];
int ans[N][N];
vector<int> pf (string s) {
    int n = (int) s.length();
    vector<int> pi (n);
    for (int i=1; i<n; ++i) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])  ++j;
        pi[i] = j;
    }
    return pi;
}
ll get_ans(const int &i ,const int &j)
{
    ll sum = 1;
    sum += max(mx1[i][j] , mx2[i][j]);
    sum += max(mp1[i][j] , mp2[i][j]);
    return sum;
}
void construct(const int &n , const int &m)
{
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            ans[i][j] = get_ans(i, j);
        }
    }
}
int n , m;
int cx[4];
int pp = 0 , qq = 0;
string rs;
void add()
{
    for(int i = 0; i < 2; i++)
    {
        for(int j = 0; j < cx[i]; j++)
        {
            char c = i + '0';
            rs.pb(c);
        }
    }
    
}
signed main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string a , b;
    cin >> a >> b;
    n = a.size();
    m = b.size();
    vector<int> p = pf(b);
    construct(N, N);
    for(int i = 0; i + p[m - 1] < m; i++)
    {
        if(b[i] == '0')
        {
            pp++;
        }
        else
        {
            qq++;
        }
    }
    for(auto c : a)
    {
        if(c == '0')
            cx[0]++;
        else
            cx[1]++;
    }
    for(auto c : b)
    {
        if(c == '0')
            cx[2]++;
        else
            cx[3]++;
    }
    rs = b;
    if (cx[0] >= cx[2] && cx[1] >= cx[3])
    {
        cx[0] -= cx[2];
        cx[1] -= cx[3];
        while (cx[0] >= pp && cx[1] >= qq)
        {
            cx[0] -= pp;
            cx[1] -= qq;
            for (int i = p[m - 1]; i < m; i++)
            {
                rs.pb(b[i]);
            }
        }
    }
    else
    {
        rs.clear();
        for(int i = 0; i < 4; i++)
        {
            //    cout <<cx[i] << " ";
        }
    //    cout << "\n";
    }
    add();
    cout << rs << "\n";
    return 0;
}