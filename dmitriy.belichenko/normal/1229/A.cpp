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
const int MaXN = 150;
const int N = 2e5 + 1000;
const int LOG = 64;
const int FACT = 120;
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
#define int ll
//int n;
//ll a[20][20], dp[20][20];
//map<vector<int>, int> dp_nw, nxt, dp_prev;
//vector<int> vs;
//inline void update(int i, int mask , int p)
//{
//
//    sort(vs.begin(), vs.end());
//    vs.resize(unique(vs.begin(), vs.end()) - vs.begin());
//    ll sm = (vs.size() > 0) ? mult(dp[i][mask], p) : 0;
//    sum(nxt[vs], sm);
//}
//
//inline void calc(const vector<int> &P, int mask)
//{
//    vs.clear();
//    for (int x : P)
//    {
//        for (int v = 0; v < n; v++)
//        {
//            int cur = (1 << v);
//            if (mask & cur)
//            {
//                int RT = (cur | x);
//                if((x & cur) == 0) vs.pb(RT);
//            }
//        }
//    }
//}
vector<tuple<ll, int, ll>> mda;
bool used[7001];
ll ans = 0;

void dfs(int pos)
{
    if (used[pos]) return;
    ans += get<2>(mda[pos]);
    used[pos] = 1;
    for (int j = 0; j < mda.size(); j++)
    {
        if ((get<0>(mda[pos]) | get<0>(mda[j])) == get<0>(mda[pos]))
            dfs(j);
    }
}

ll a[7001];
ll b[7001];
map<ll, ll> cnt, sm;

int32_t main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }
    for (int i = 0; i < n; i++)
    {
        cin >> b[i];
        sm[a[i]] += b[i];
    }
    for (auto& [k, v] : cnt)
    {
        mda.pb(make_tuple(k, v, sm[k]));
    }
    
    for (int i = 0; i < mda.size(); i++) {
        if (get<1>(mda[i]) >= 2)
        {
            dfs(i);
        }
    }
    cout << ans;
    return 0;
}