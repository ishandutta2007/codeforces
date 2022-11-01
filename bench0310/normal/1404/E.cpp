#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename flow_t=int>
struct dinic
{
    int n,m;
    vector<vector<array<int,2>>> v;
    struct edge_t
    {
        flow_t flow,cap;
        edge_t(flow_t c):flow(0),cap(c){}
        flow_t res(){return cap-flow;}
    };
    vector<edge_t> edges;
    vector<int> lvl,nxt;
    queue<int> q;
    const flow_t flow_inf=numeric_limits<flow_t>::max()/4;
    dinic(int _n):n(_n),m(0),v(_n),lvl(_n),nxt(_n){}
    void add_edge(int a,int b,flow_t cap)
    {
        v[a].push_back({b,m++});
        edges.push_back(edge_t(cap));
        v[b].push_back({a,m++});
        edges.push_back(edge_t(0));
    }
    bool find_lvl(int s,int t)
    {
        lvl.assign(n,-1);
        lvl[s]=0;
        q.push(s);
        while(!q.empty())
        {
            int a=q.front();
            q.pop();
            for(auto [to,id]:v[a])
            {
                if(lvl[to]==-1&&edges[id].res()>0)
                {
                    lvl[to]=lvl[a]+1;
                    q.push(to);
                }
            }
        }
        return (lvl[t]!=-1);
    }
    flow_t blocking_flow(int a,flow_t mn,int t)
    {
        if(a==t) return mn;
        for(;nxt[a]<(int)v[a].size();nxt[a]++)
        {
            auto [to,id]=v[a][nxt[a]];
            if(lvl[a]+1!=lvl[to]||edges[id].res()==0) continue;
            flow_t tmp=blocking_flow(to,min(mn,edges[id].res()),t);
            if(tmp>0)
            {
                edges[id].flow+=tmp;
                edges[id^1].flow-=tmp;
                return tmp;
            }
        }
        return 0;
    }
    flow_t max_flow(int s,int t)
    {
        flow_t flow=0;
        while(find_lvl(s,t))
        {
            nxt.assign(n,0);
            while(flow_t f=blocking_flow(s,flow_inf,t)) flow+=f;
        }
        return flow;
    }
};

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m;
    cin >> n >> m;
    vector<string> c(n);
    for(int i=0;i<n;i++) cin >> c[i];
    vector l(n,vector(m,int(0)));
    vector r(n,vector(m,int(0)));
    vector u(n,vector(m,int(0)));
    vector d(n,vector(m,int(0)));
    int cnt=0;
    for(int i=0;i<n;i++) for(int j=0;j+1<m;j++) if(c[i][j]=='#'&&c[i][j+1]=='#') r[i][j]=l[i][j+1]=(++cnt);
    int one=cnt;
    for(int j=0;j<m;j++) for(int i=0;i+1<n;i++) if(c[i][j]=='#'&&c[i+1][j]=='#') d[i][j]=u[i+1][j]=(++cnt);
    dinic g(cnt+2);
    int s=0,t=cnt+1;
    for(int i=1;i<=cnt;i++)
    {
        if(i<=one) g.add_edge(s,i,1);
        else g.add_edge(i,t,1);
    }
    int all=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            all+=(c[i][j]=='#');
            for(int a:{l[i][j],r[i][j]}) for(int b:{u[i][j],d[i][j]}) if(a!=0&&b!=0) g.add_edge(a,b,1);
        }
    }
    cout << all-(cnt-g.max_flow(s,t)) << "\n";
    return 0;
}