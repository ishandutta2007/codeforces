#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
#define MAXN 100005

vector<ll> g[MAXN],nodes,dist;
ll arr[MAXN],sons[MAXN][2],fi[2][20],ffi[2][20];
bool mk[MAXN],nk[MAXN];
ll res=0;

bool f(int x)
{
    if(!x)
        return 0;
    return 1;
}

void dfs(int u)
{
    nk[u]=1;
    nodes.push_back(u);
    sons[u][0]=1;
    for(auto v : g[u])
        if(!mk[v] && !nk[v])
        {
            dfs(v);
            sons[u][0]+=sons[v][0];
            sons[u][1]=max(sons[u][1],sons[v][0]);
        }
}

void dfsd(int u,int d)
{
    d^=arr[u];
    nk[u]=1;
    dist.push_back(d);
    nodes.push_back(u);
    for(auto v : g[u])
        if(!mk[v] && !nk[v])
            dfsd(v,d);
}

void solve(int v)
{
    dfs(v);
    int cent=-1,cant=(nodes.size()>>1);
    for(auto u : nodes)
    {
        if(cent==-1 && sons[u][0]>=cant && sons[u][1]<=cant)
            cent=u;
        sons[u][0]=sons[u][1]=nk[u]=0;
    }
    nodes.clear();

    mk[cent]=1;
    for(int i=0;i<20;i++)
        fi[f(arr[cent]&(1<<i))][i]=1,fi[!(f(arr[cent]&(1<<i)))][i]=0;
    for(auto u : g[cent])
        if(!mk[u] && !nk[u])
        {
            dfsd(u,0);
            for(auto y : dist)
                for(int i=0;i<20;i++)
                {
                    ffi[f((y^arr[cent])&(1<<i))][i]++;
                    res+=(fi[f(!(y&(1<<i)))][i]*(1<<i));
                }

            for(int j=0;j<2;j++)
                for(int i=0;i<20;i++)
                    fi[j][i]+=ffi[j][i],ffi[j][i]=0;
            dist.clear();
        }

    for(auto u : nodes)
        nk[u]=0;
    nodes.clear();
    for(auto u : g[cent])
        if(!mk[u])
            solve(u);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
        res+=arr[i];
    }

    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(0);

    db(res)

    return 0;
}