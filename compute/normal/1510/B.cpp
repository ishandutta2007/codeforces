#include<bits/stdc++.h>
using namespace std;
const int maxn = 3e3 + 7;
const int INF = 0x3f3f3f3f;
struct Edge
{
    int from, to, cap, flow, cost;
};
struct MCMF
{
    int n, m, s, t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn]; //
    int p[maxn]; //
    int a[maxn]; //
    void init(int n)
    {
        this->n = n;
        for (int i = 0; i < n; i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from, int to, int cap, int cost)
    {
        edges.push_back(Edge{from, to, cap, 0, cost});
        edges.push_back(Edge{to, from, 0, 0, -cost});
        m = edges.size();
        G[from].push_back(m - 2);
        G[to].push_back(m - 1);
    }
    bool spfa(int s, int t, int &flow, int &cost)
    {
        for (int i = 0; i < n; i++)
            d[i] = INF;
        memset(inq, 0, sizeof(inq));
        d[s] = 0;
        inq[s] = 1;
        p[s] = 0;
        a[s] = INF;
        queue<int> q;
        q.push(s);
        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = 0;
            for (int i = 0; i < G[u].size(); i++)
            {
                Edge &e = edges[G[u][i]];
                if (e.cap > e.flow && d[e.to] > d[u] + e.cost) // d[e.to] = d[u]+e.cost+h[u]-h[e.to]
                {
                    d[e.to] = d[u] + e.cost;             //
                    p[e.to] = G[u][i];                   //
                    a[e.to] = min(a[u], e.cap - e.flow); //
                    if (!inq[e.to])
                    {
                        q.push(e.to);
                        inq[e.to] = 1;
                    }
                }
            }
        }
        if (d[t] == INF)
            return false; //
        // for(int i=0;i<n;i++) h[i]+=d[i];
        flow += a[t];
        cost += d[t] * a[t];
        // cost += h[t] * a[t];
        int u = t;
        while (u != s)
        {
            edges[p[u]].flow += a[t];
            edges[p[u] ^ 1].flow -= a[t];
            u = edges[p[u]].from;
        }
        return true;
    }
    int Mincost(int s, int t)
    {
        int flow = 0, cost = 0;
        while (spfa(s, t, flow, cost))
            ;
        return cost;
    }
}F;
const int inf=1e9;
int nxt[1<<11];
int d,n;
vector<int> ans;
void dfs(int u)
{
    u+=(1<<d);
    for(auto ev:F.G[u])
    {
        auto &e=F.edges[ev];
        if(e.flow>0&&e.to<(1<<d)*2)
        {
            int cur=u-(1<<d);
            if(e.to<cur) continue;
            e.flow--;
            if(e.to&&e.to<(1<<d))
            {
                for(int j=0;j<d;j++)
                {
                    if((e.to>>j&1)&&!(cur>>j&1))
                        ans.push_back(j);
                }
                dfs(e.to);
                return;
            }
        }
    }
}
int main()
{
    cin>>d>>n;
    auto getid=[&](int x,int tp){
        return x+tp*(1<<d);
    };
    int S=(1<<d)*2+1,T=S+1;
    F.init(T+1);
    for(int i=0;i<(1<<d);i++)
    {
        F.addedge(getid(i,0),getid(i,1),inf,0);
        F.addedge(getid(i,1),getid(0,0),inf,1);
        for(int j=0;j<d;j++)
        {
            if(i&(1<<j));
            else F.addedge(getid(i,1),getid(i|(1<<j),0),inf,1);
        }
    }
    for(int i=0;i<n;i++)
    {
        string s;
        cin>>s;
        int cur=0;
        for(int j=0;j<d;j++)
        {
            if(s[j]=='1')
                cur+=(1<<j);
        }
        F.addedge(S,getid(cur,1),1,0);
        F.addedge(getid(cur,0),T,1,0);
    }
    cout<<F.Mincost(S,T)-1<<endl;
    for(auto ev:F.G[1<<d])
    {
        auto &e=F.edges[ev];
        while(e.flow>0)
        {
            //cout<<":"<<e.to<<endl;
            for(int j=0;j<d;j++)
            {
                if(e.to==(1<<j)) ans.push_back(j);
            }
            dfs(e.to);
            e.flow--;
            ans.push_back(-1);
        }
    }
    for(int i=0;i+1<ans.size();i++)
    {
        if(ans[i]==-1) cout<<"R ";
        else cout<<ans[i]<<" \n"[i+2==ans.size()];
    }

}