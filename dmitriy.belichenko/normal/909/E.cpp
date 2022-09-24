#include <iostream>
#include <map>
#include <vector>
#include <deque>
#include <algorithm>
#include <bitset>
#include <math.h>
#include <string>
#include <set>
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
const double PI = acos(-1);
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;
int sum(int a , int b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

long long mult( long long a , long long b)
{
    long long c = 1LL * a * b;
    return c % MOD;
}
int poww(long long a , long long b)
{
    long long res = 1;
    a %= MOD;
    while(b > 0)
    {
        if(b % 2) res = (res * a) % MOD;
        a = (a * a) % MOD;
        b >>= 1;
    }
    return res % MOD;
}
set<pair<char , char>> t;
vector<int> a;
vector<int>g[N];
bool used[N];
vector<int> topsort;
void dfs(int v)
{
    used[v] = 1;
    for(auto u : g[v])
    {
        if(!used[u])
        {
            dfs(u);
        }
    }
    topsort.pb(v);
}

int dp1[N] , dp2[N];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n , m;
    cin >> n >> m;
    a.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
        a[i] = 1 - a[i];
    }
    for(int i = 0; i < m; i++)
    {
        int u , v;
        cin >> u >> v;
        g[u].pb(v);
    }
    for(int i = 0; i < n; i++) if(!used[i]) dfs(i);
   // for(int i = 0; i < n; i++) cout << topsort[i] << " ";
 //   cout << "\n";
    for(int i = 0; i < n; i++)
    {
        int v = topsort[i];
        if(a[v] == 0) dp1[v] = 1;
        for(auto p : g[v])
        {
        //    cout << v << " " << p << " " << dp1[p] << "\n";
            if(a[v] == 0 && a[p] == 0)
                dp1[v] = max(dp1[v] , dp1[p]);
            if(a[v] == 0 && a[p] == 1)
                 dp1[v] = max(dp1[v] , dp1[p] + 1);
            if(a[v] == 1 && a[p] == 0)
                dp1[v] = max(dp1[v] , dp1[p]);
            if(a[v] == 1 && a[p] == 1)
                dp1[v] = max(dp1[v] , dp1[p]);
            
        }
    }
    int ans = 0;
    for(int i = 0; i < n; i++)
    {
        ans = max(dp1[i] , ans);
    }
    cout << ans << "\n";
    return 0;
}