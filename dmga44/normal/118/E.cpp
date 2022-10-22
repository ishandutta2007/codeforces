#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 100005

vector<int> g[MAXN];
int dfs_num[MAXN],dfs_low[MAXN],dfs_cont,parent[MAXN];
bool mk[MAXN],f,mk2[MAXN];

void SCC(int u)
{
    dfs_cont++;
    dfs_num[u]=dfs_low[u]=dfs_cont;
    for(auto v : g[u])
    {
        if(!dfs_num[v])
        {
            parent[v]=u;
            SCC(v);
            if(dfs_low[v]>dfs_num[u])
                f=1;
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
        }
        else if(v!=parent[u])
            dfs_low[u]=min(dfs_low[u],dfs_num[v]);
    }
}

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g[u])
    {
        if(!mk[v])
        {
            cout << u+1 << ' ' << v+1 << '\n';
            parent[v]=u;
            dfs(v);
        }
        else if(v!=parent[u] && !mk2[v])
            cout << u+1 << ' ' << v+1 << '\n';
    }
    mk2[u]=1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    SCC(0);

    if(f)
    {
        db(0)
        return 0;
    }
    parent[0]=-1;
    dfs(0);

    return 0;
}