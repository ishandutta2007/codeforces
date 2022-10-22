#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
using namespace std;
typedef long long ll;
typedef pair<ll,ll> pii;
typedef pair<ll,pii> pip;
#define MAXN 2005

ll xy[MAXN][2];
ll c[MAXN],k[MAXN],d[MAXN];
bool mk[MAXN];
vector<int> g[MAXN],nodes;

ll dis(int i,int j)
{
    return (abs(xy[i][0]-xy[j][0])+abs(xy[i][1]-xy[j][1]))*(k[i]+k[j]);
}

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

void dfs(int u)
{
    mk[u]=1;
    nodes.push_back(u);
    for(auto y : g[u])
        if(!mk[y])
            dfs(y);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        d[i]=-1;
    for(int i=0;i<n;i++)
        cin >> xy[i][0] >> xy[i][1];
    for(int i=0;i<n;i++)
        cin >> c[i];
    for(int i=0;i<n;i++)
        cin >> k[i];

    ll cost=0;
    vector<int> a1;
    vector<pii> a2;
    priority_queue<pip,vector<pip>,greater<pip> > pq;
    for(int i=0;i<n;i++)
        pq.push(pip(c[i],pii(i,-1)));

    while(!pq.empty())
    {
        pip x=pq.top();
        pq.pop();
        ll u=x.second.first;

        if(mk[u])
            continue;
        mk[u]=1;
        ll w=x.first;
        int t=x.second.second;
        cost+=w;
        if(t==-1)
            a1.push_back(u+1);
        else
            a2.push_back(pii(u+1,t+1));
        for(int i=0;i<n;i++)
            if(!mk[i])
                pq.push(pip(dis(i,u),pii(i,u)));
    }

//    sort(edges.begin(),edges.end());
//
//    ll cost=0;
//    int r2=0;
//    for(auto y : edges)
//    {
//        int u=y.second.first;
//        int v=y.second.second;
//        if(find(u)!=find(v))
//        {
//            join(u,v);
//            g[u].push_back(v);
//            g[v].push_back(u);
//            cost+=dis(u,v);
//            r2++;
//        }
//    }
//
//    vector<ll> a1;
//    for(int i=0;i<n;i++)
//        if(!mk[i])
//        {
//            dfs(i);
//            ll c1=1e10,u=-1;
//            for(auto y : nodes)
//                if(c1>c[y])
//                {
//                    u=y;
//                    c1=c[y];
//                }
//            nodes.clear();
//            a1.push_back(u+1);
//            cost+=c1;
//        }
//
    db(cost)
    db(a1.size())
    for(auto y : a1)
        cout << y << ' ';
    cout << '\n';
    db(a2.size())
    for(auto y : a2)
        cout << y.first << ' ' << y.second << '\n';

    return 0;
}