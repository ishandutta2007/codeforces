
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
using namespace std;
#define pb push_back
#define ll long long
#define mp make_pair
#define fst first
#define snd second
#define ld long double
const double PI = acos(-1);
const int N = 2e5 + 5;
int MOD = 1e9 + 7;
ll sum(ll a , ll b)
{
    a += b;
    if(a < 0)
        return  a + MOD;
    if(a >= MOD)
        return a - MOD;
    else return a;
}

ll mult( ll a , ll  b)
{
    long long c = 1LL * (a % MOD) * (b % MOD);
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
int ans = 1;
map<int,int> xx , yy;
vector<int> g[N];
bool used[N];
int a = 0 , b = 0;
void dfs(int u )
{
    used[u] = 1;
    a += g[u].size();
    b++;
    for(auto v : g[u])
    {
        if(!used[v])
        {
            dfs(v);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    int cnt = 0;
    for(int i = 0; i < n; i++)
    {
        int x , y;
        cin >> x >> y;
        if(xx[x] == 0) xx[x] = ++cnt;
        if(yy[y] == 0) yy[y] = ++cnt;
        g[xx[x]].pb(yy[y]);
        g[yy[y]].pb(xx[x]);
    }
    for(int i = 1; i <= cnt; i++)
    {
        a = 0 , b = 0;
        if(!used[i])  dfs(i);
        if(2 * b - 1 >= a)
        {
            ans = mult( ans, (poww(2 , b) - 1));
        }
        else
        {
            ans = mult( ans, (poww(2 , b)));
        }
        
    }
    cout << ans << "\n";
     return 0;
}