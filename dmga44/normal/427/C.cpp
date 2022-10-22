#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
#define MAXN 200005
#define mod 1000000007

vector<int> g[MAXN];
stack<int> s;
ll dfs_num[MAXN],dfs_low[MAXN],a[MAXN],dfs_cont,res,ways=1;
bool mk[MAXN];

void SCC(int u)
{
    mk[u]=1;
    dfs_cont++;
    dfs_num[u]=dfs_low[u]=dfs_cont;
    s.push(u);
    for(auto v : g[u])
    {
        if(!dfs_num[v])
            SCC(v);
        if(mk[v])
            dfs_low[u]=min(dfs_low[u],dfs_low[v]);
    }

    if(dfs_num[u]==dfs_low[u])
    {
        ll r1=1e9+1,r2=1;
        while(1)
        {
            int v=s.top();
            s.pop();
            mk[v]=0;
            if(a[v]<=r1)
            {
                if(a[v]<r1)
                    r2=0;
                r1=a[v];
                r2++;
            }
            if(v==u)
                break;
        }
        res+=r1;
        ways=(ways*r2)%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

//    freopen(".in","r",stdin);

    int n,m,u,v;
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> a[i];

    cin >> m;
    for(int i=0;i<m;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
    }

    for(int i=0;i<n;i++)
        if(!dfs_num[i])
            SCC(i);

    cout << res << ' ' << ways << '\n';

    return 0;
}