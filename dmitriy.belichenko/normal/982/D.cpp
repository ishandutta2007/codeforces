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
#define fst firs
const double PI = acos(-1);
const int N = 5e5 + 17;
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
ll mult(ll a, ll b)
{
    ll res = a * b - (ll) ((ld) a * b / MOD) * MOD;
    if (res < 0)
    {
        res += MOD;
    }
    if (res >= MOD)
    {
        res -= MOD;
    }
    return res;
}
ll gcd (ll a, ll b, ll & x, ll & y)
{
    if (a == 0)
    {
        x = 0LL; y = 1LL;
        return b;
    }
    ll x1, y1;
    ll d = gcd (b%a, a, x1, y1);
    x = y1 - (b / a) * x1;
    y = x1;
    return d;
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
vector<int> g[N];
int ans = 0;
bool used[N];
int dfs(int u, int e)
{
    used[u] = 1;
    int xr = 1;
    for (auto v : g[u])
    {
        if(!used[v])
        {
            xr ^= dfs(v, u);
        }
    }
    ans += (xr == 0);
    return xr;
}
pair<int , int> a[N];
set<int> cur;
map<int , int> m;
bool debug = 0;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n;
    cin >> n;
    ll out = poww(INF , n);
    if(n == 0 || debug == true)
    {
        cout << out << " " << n << "\n";
    }
    for(int i = 0; i < n; i++)
    {
        cin >> a[i + 1].first;
        a[i + 1].snd = i + 1;
    }
    sort(a + 1, a + n + 1);
    int ans = INF;
    int diff = 1;
    m[n] = 1;
    for(int i = n ; i > 0; i--)
    {
        cur.insert(n + 1);
        cur.insert(0);
        int l , r;
        auto cr = cur.upper_bound(a[i].second);
        r = *cr;
        if(cur.size() > 1)
        {
            cr--;
        }
        l = *cr;
        int del = r - (a[i].second + 1);
        int rz = a[i].second - (l + 1);
        int sz = r - (l + 1);
        m[sz]--;
        if(!m[sz])
        {
            m.erase(sz);
        }
//        if(del + rz > 0)
//        {
//            if(del > 0)
//            {
//                m[del]++;
//            }
//            if(rz > 0)
//            {
//                m[rz]++;
//            }
//        }
        if(del)
        {
            m[del]++;
        }
        if(rz)
        {
            m[rz]++;
        }
        cur.insert(a[i].second);
        if(m.size() == 1)
        {
            int cnt = 0;
            for(auto ind : m)
            {
                if(ind.second >= diff)
                {
                    ans = a[i].first;
                    diff = ind.second;
                }
                break;
            }
        }
    }
    int mx = -1;
  //  cout << ans << "\n";
    for(int i = 1; i <= n; i++)
    {
        if(a[i].first < ans )
        {
            mx = max(mx , a[i].first);
        }
        if(i > n - 1) mx++;
    }
    cout << mx << "\n";
    return 0;
}