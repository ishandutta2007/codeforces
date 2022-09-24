#include<iostream>
#include<math.h>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
vector<vector<int>> g;
vector<int>a;
int n;
bool used[200005];
int mx = -1;
vector<int> ans(200005);
set<int , greater<int> > cur[200005];
int c = 0;
void dfs(int u, int e, int c)
{
    if (u == 0)
    {
        ans[u] = a[u];
        cur[u].insert(0);
        cur[u].insert(ans[u]);
    }
    else
    {
        for (auto v : cur[e])
        {
            cur[u].insert(__gcd(v, a[u]));
        }
        
        cur[u].insert(c);
        
        ans[u] = *cur[u].begin();
    }
    c = __gcd(c, a[u]);
    
    for (auto v : g[u])
        if (v != e)
            dfs(v, u, c);
     
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin >> n;
    a.resize(n);
    g.resize(n);
    for( int i = 0 ; i < n ; i++ )
    {
        cin >> a[i];
    }
    for(int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    for(int i = 0; i < n; i++)
    {
       if(!ans[i])
       dfs(i , -1 , 0);
    }
    for(int i = 0; i < n; i++)
    {
        cout << ans[i] << " ";
    }
    return 0;
}