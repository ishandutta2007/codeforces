#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
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
const double PI = acos(-1);
const int N = 2e5 + 7;
ll MOD = 1e9 + 9;
const int INF = 1e9 + 9;
const int MAXN = 26;
const int maxlog = 18;
const int maxn = 1 << maxlog;
random_device rd;
mt19937 rnd(rd());
uniform_int_distribution<ll> nextRand(0,(ll)1e9);
template<class A, class B>
void sum(A &a, B b)
{
    a += b;
    if (a < 0) a += MOD;
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
vector<int> g[N];
int deg[N];
//vector<pair<int, int>> deg;
int can[N][10];
// make it orient
void dfs(int u , int p)
{
    for(int i = 0; i < g[u].size(); i++)
    {
        int to = g[u][i];
        if(to == p)
        {
            swap(g[u][i] , g[u].back());
            g[u].pop_back();
            i--;
            continue;
        }
        else
            dfs(to , u);
    }
}
int dfs2(int u , int v)
{
    int cur = g[u].size();
    if(can[u][v] != INF)
    {
        return can[u][v];
    }
    int t1 , t2 , t3;
    t1 = 0 , t2  = 0 , t3 = 0;
    bool s1  = 0, s2 = 0, s3 = 0;
    for(auto p : g[u])
    {
      //  s1 = dfs2(p , 1) & dfs2(p , 0);
        if(dfs2(p , 1) & dfs2(p , 0))
        {
            t1 += 1 , t2 += s2 , t3 += s3;
            continue;
        }
        //s2 = !dfs2(p , 1) & dfs2(p , 0);
        if(!dfs2(p , 1) & dfs2(p , 0))
        {
            t1 += s1 , t2 += 1 , t3 += s3;
            continue;
        }
        if(!dfs2(p , 0) & dfs2(p , 1))
        {
            t1 += s1 , t2 += s2 , t3 += 1;
            continue;
        }
        if(!s1 && !s2 && !s3)
        {
            can[u][v] = 0;
            return can[u][v];
        }
    }
    if( (deg[u] - t2 - v) % 2 == 1)
    {
        if(!s2)
        {
            can[u][v] = 0;
            return can[u][v];
        }
        
    }
    can[u][v] = 1;
    return can[u][v];
}
void dfs3(int u , int v)
{
    vector<int> t1 , t2 , t3;
    
    bool s1  = 0, s2 = 0, s3 = 0;
    for(auto p : g[u])
    {
      //  s1 = dfs2(p , 1) & dfs2(p , 0);
        if(dfs2(p , 1) && dfs2(p , 0))
        {
            t1.pb(p);
            continue;
        }
        if(!dfs2(p , 1) && dfs2(p , 0))
        {
            t2.pb(p);
            continue;
        }
        if(!dfs2(p , 0) && dfs2(p , 1))
        {
            t3.pb(p);
            continue;
        }
        
    }
    for(int i : t2)
    {
        dfs3(i, min(v , 0));
    }
    if((deg[u] - t2.size() - v) & 1)
    {
        dfs3(t1.back(), 0);
        t1.pop_back();
    }
    cout << u << "\n";
    for(int i = 0; i < t1.size(); i++)
    {
        dfs3(t1[i], 1);
    }
    for(int i = 0; i < t3.size(); i++)
    {
        dfs3(t3[i], 1);
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n ;
    
    cin >> n;

    poww(n , MOD - 2);
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < 10; j++)
            can[i][j] = INF;
    }
    for(int i = 0; i < n; i++)
    {
        int u ;
        cin >> u;
        // u--;
        if(u == 0) continue;
        g[u].pb(i + 1);
        g[i + 1].pb(u);
        deg[i + 1]++;
        deg[u]++;
        
    }
    dfs(1 , -1);
    //    for(int i = 0; i < n; i++)
    //    {
    //        cout << i << ": ";
    //        for(auto v : g[i])
    //        {
    //            cout << v << " ";
    //        }
    //        cout << "\n";
    //    }
    
    if(!dfs2(1 , 0))
    {
        if(n % 2 == 0)
        {
            cout << "NO";
            return 0;
        }
        cout << "NO";
        return 0;
    }
    cout << "YES" << "\n";
    dfs3(1 , 0);
    
    return 0;
}