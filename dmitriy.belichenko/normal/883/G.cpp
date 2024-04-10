
#include<iostream>
#include<math.h>
#include<cstring>
#include<set>
#include<algorithm>
#include<vector>
#include<map>
#include<iomanip>
#include<queue>
#include<string>
#include<ctime>
//#include "optimization.h"
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N =  3e5 +100;
ll INF = (1LL << 62) - 1;
ll MOD = 1e9 + 7;
vector<pair<int , int> > g[N];
vector<int> p[N];
bool used[N];
int n , m , s;
string ans;
void dfs(int v )
{
    used[v] = 1;
    for(auto u : g[v])
    {
        if(!used[u.first]) dfs(u.first);
    }
}
void dfsrev(int v )
{
    used[v] = 1;
    for(auto u : p[v])
    {
        if(!used[u])
        {
           dfsrev(u);
        }
    }
}
void dfsmx(int v)
{
    used[v] = 1;
    for (auto p : g[v])
    {
        int u = p.first;
        int e = p.second;
        if(!used[u])
        {
          if (e > 0) ans[e - 1] = '+';
          else if (e < 0) ans[-e - 1] = '-';
          dfsmx(u);
        }
    }
}
void dfsmn(int v)
{
    used[v] = 1;
    for (auto p : g[v])
    {
        int u = p.first;
        int e = p.second;
        if(!used[u])
        {
            if (e > 0) ans[e - 1] = '-';
            else if (e < 0) ans[-e - 1] = '+';
            else if(e == 0)dfsmn(u);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int n , m , s;
    cin >> n >> m >> s;
    s--;
    int num = 0;
    for(int i = 0; i < m; i++)
    {
        int t , u , v;
        cin >> t >> u >> v;
        u--; v--;
        if (t == 1)
        {
            g[u].pb(mp(v, 0));
            p[u].pb(v);
        }
        else
        {
            num++;
            g[u].pb(mp(v , num));
            g[v].pb(mp(u , -num));
        }
    }
    int mx = 0 , mn = 0;
    dfs(s);
    for(int i = 0; i < n; i++)
    {
        if(used[i]) mx++;
        used[i] = 0;
    }
    dfsrev(s);
    for(int i = 0; i < n; i++)
    {
        if(used[i]) mn++;
        used[i] = 0;
    }
    ans.resize(num , '+');
    dfsmx(s);
    for(int i = 0; i < n; i++)
    {
        //if(used[i]) mn++;
        used[i] = 0;
    }
    cout << mx << "\n";
  
    cout << ans << "\n";
    cout << mn << "\n";
    dfsmn(s);
    cout << ans << "\n";
    return 0;
}