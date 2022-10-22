#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 100005

vector<int> g[MAXN],g1[MAXN],s;
stack<int> si;
int dfs_num[MAXN],dfs_low[MAXN],dfs_cont;
bool mk[MAXN];

int dfs(int u)
{
    mk[u]=1;
    s.push_back(u);
    for(auto v : g1[u])
        if(!mk[v])
            dfs(v);
}

bool SCC(int u)
{
    mk[u]=1;
    dfs_cont++;
    dfs_num[u]=dfs_low[u]=dfs_cont;
    si.push(u);
    bool b=0;
    for(auto v : g[u])
    {
        if(!dfs_num[v])
            b|=SCC(v);
        if(mk[v])
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }

    if(dfs_low[u]==dfs_num[u])
    {
        int cant=0;
        while(1)
        {
            int v=si.top();
            si.pop();
            mk[v]=0;
            cant++;
            if(u==v)
                break;
        }
        if(cant>1)
            b=1;
    }

    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g1[u].push_back(v);
        g1[v].push_back(u);
    }

    int res=n;
    for(int i=0;i<n;i++)
        if(!dfs_num[i])
        {
            res--;
            bool b=0;
            dfs(i);
            for(auto v : s)
                mk[v]=0;
            for(auto v : s)
                if(!dfs_num[v])
                    b|=SCC(v);
            res+=b;
            s.clear();
        }

    db(res)

    return 0;
}