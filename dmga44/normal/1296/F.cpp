#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 5005

vector<pii> g[MAXN];
int res[MAXN],mk[MAXN];

bool dfs(int u,int v,int x)
{
    mk[u]=1;
    if(u==v)
        return 1;
    bool ret=0;
    for(auto y : g[u])
        if(!mk[y.first])
        {
            bool ok=dfs(y.first,v,x);
            if(ok)
            {
                res[y.second]=max(res[y.second],x);
                ret=1;
            }
        }
    return ret;
}

ll dfs2(int u,int v)
{
    mk[u]=1;
    ll ret=1e17;
    for(auto y : g[u])
        if(!mk[y.first])
        {
            if(y.first==v)
                return res[y.second];
            ll r1=dfs2(y.first,v);
            if(r1!=1e17)
                ret=min((ll)res[y.second],r1);
        }
    return ret;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,u,v;
    cin >> n;
    for(int i=0;i<n;i++)
        res[i]=1;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        g[u].push_back(pii(v,i));
        g[v].push_back(pii(u,i));
    }

    vector<pip> qs;
    int m;
    cin >> m;
    for(int i=0;i<m;i++)
    {
        int x;
        cin >> u >> v >> x;
        qs.push_back(pip(x,pii(u,v)));
        bool tt=dfs(u,v,x);
        for(int j=0;j<=n;j++)
            mk[j]=0;
    }

    bool f=1;
    for(int i=0;i<m;i++)
    {
        if(dfs2(qs[i].second.first,qs[i].second.second)>qs[i].first)
            f=0;
        for(int j=0;j<=n;j++)
            mk[j]=0;
    }

    if(f)
    {
        for(int i=0;i<n-1;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    else
        db(-1)

    return 0;
}