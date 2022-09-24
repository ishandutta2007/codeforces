#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <queue>
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
int a[N];
vector<int>g[N];
int d[N][107];
bool used[N];
int cur = 1;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    srand(time(0));
    int n , k , m , s;
    cin >> n >> m >> k >> s;
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i]--;
    }
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        u--;
        v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    set<int> hs;
    queue<int> q;
    for(int t = 0; t < k; t++)
    {
        for(int i = 0; i < n; i++) d[i][t] = INF;
        for(int i = 0; i < n; i++)
        {
            if(a[i] == t)
            {
                q.push(i);
                d[i][t] = 0;
            }
        }
        while(!q.empty())
        {
            int u = q.front();
            q.pop();
            for(auto v : g[u])
            {
                if(d[v][t] == INF)
                {
                    d[v][t] = d[u][t] + 1;
                    q.push(v);
                }
            }
        }
    }
    for(int i = 0; i < n; i++)
    {
        sort(d[i], d[i] + k);
        int sum = 0;
        int cnt = 0;
        for(int j = 0; cnt < s; j++)
        {
            cnt++;
        //    cout << d[i][j] << " ";
            sum += d[i][j];
        }
        cout << sum << " ";
      //  cout << "\n";
    }
    return 0;
}