#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 100005

vector<int> g[MAXN],nodes;
int res[MAXN],sons[MAXN][2];
bool mk[MAXN],nk[MAXN];

void dfs(int v)
{
    nk[v]=1;
    nodes.push_back(v);
    sons[v][0]=1;
    for(auto u : g[v])
        if(!mk[u] && !nk[u])
        {
            dfs(u);
            sons[v][0]+=sons[u][0];
            sons[v][1]=max(sons[v][1],sons[u][0]);
        }
}

void solve(int v,int l)
{
    dfs(v);

    int cent=-1,cant=nodes.size()>>1;
    for(auto u : nodes)
    {
        if(cent==-1 && sons[u][0]>=cant && sons[u][1]<=cant)
            cent=u;
        sons[u][0]=sons[u][1]=nk[u]=0;
    }
    nodes.clear();

    mk[cent]=1;
    res[cent]=l;
    for(auto u : g[cent])
        if(!mk[u])
            solve(u,l+1);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(0,0);

    for(int i=0;i<n;i++)
        cout << (char)('A'+res[i]) << ' ';

    return 0;
}