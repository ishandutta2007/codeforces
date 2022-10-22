#include <bits/stdc++.h>
#define endl '\n'
#define db(x) cout << x << endl;
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<int,pii> pip;
#define MAXN 100005

vector<int> g[MAXN],nodes;
vector<pii> centMax[MAXN],dist_node;
vector<pip> cent_dist[MAXN];
int sons[MAXN][2];
bool mk[MAXN],nk[MAXN];

void dfs(int u)
{
    sons[u][0]=nk[u]=1;
    nodes.push_back(u);
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
    d++;
    nk[u]=1;
    nodes.push_back(u);
    dist_node.push_back(pii(u,d));
    for(auto v : g[u])
        if(!mk[v] && !nk[v])
            dfsd(v,d);
}

void solve(int u)
{
    dfs(u);

    int cent=-1,cant=(nodes.size()>>1);
    for(auto v : nodes)
    {
        if(cent==-1 && sons[v][0]>=cant && sons[v][1]<=cant)
            cent=v;
        sons[v][0]=sons[v][1]=nk[v]=0;
    }
    nodes.clear();

    mk[cent]=1;
    cent_dist[cent].push_back(pip(cent,pii(cent,0)));
    for(auto v : g[cent])
        if(!mk[v])
        {
            dfsd(v,0);
            for(auto y : dist_node)
                cent_dist[y.first].push_back(pip(cent,pii(v,y.second)));
            dist_node.clear();
        }
    for(auto v : nodes)
        nk[v]=0;
    nodes.clear();
    for(auto v : g[cent])
        if(!mk[v])
            solve(v);
}

void update(int u)
{
    for(auto pi : cent_dist[u])
    {
        int cent=pi.first;
        pii side=pi.second;

        vector<pii> vvv;
        vvv.push_back(pii(side.second,side.first));
        for(auto y : centMax[cent])
            vvv.push_back(y);

        sort(vvv.begin(),vvv.end());

        centMax[cent].clear();
        centMax[cent].push_back(vvv[0]);

        for(int i=1;i<vvv.size();i++)
            if(vvv[0].second!=vvv[i].second && centMax[cent].size()<2)
                centMax[cent].push_back(vvv[i]);
    }
}

int query(int u)
{
    int res=100000;
    for(auto pi : cent_dist[u])
    {
        int cent=pi.first;
        int side=pi.second.first;
        int dis=pi.second.second;

        for(auto y : centMax[cent])
            if(y.second!=side || cent==u)
                res=min(res,dis+y.first);
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n,m,u,v,t;
    cin >> n >> m;
    for(int i=0;i<n-1;i++)
    {
        cin >> u >> v;
        u--,v--;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    solve(0);

    update(0);
    for(int i=0;i<m;i++)
    {
        cin >> t >> v;
        v--;
        if(t==1)
            update(v);
        else
            db(query(v))
    }

    return 0;
}