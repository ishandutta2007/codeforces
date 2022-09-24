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
#include<bitset>
#define pb push_back
#define mp make_pair
#define fst first
#define snd second
typedef long long ll;
using namespace std;
const int N = 1e5;
const int INF = 1e9;
ll MOD = 998244353;
vector<int> g[N];
vector<int> color(N , 0);
ll l = 0, r = 0;
void dfs(int v , int c)
{
    color[v] = c;
    for(auto u : g[v])
    {
        if(!color[u])
        {
            if(c == 1) dfs(u , 2 );
            else dfs(u , 1);
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    cin >> n;
    for(int i = 0; i < n - 1; i++)
    {
        int u , v;
        cin >> u >> v;
        u--; v--;
        g[u].pb(v);
        g[v].pb(u);
    }
    dfs(0 , 1);
    for(int i = 0; i < n; i++)
    {
        //   cout << i + 1 << " " << color[i] << "\n";
        if(color[i] == 1) l++;
        else r++;
    }
    cout << (1LL * l * r - 1LL * (n - 1)) << "\n";
}