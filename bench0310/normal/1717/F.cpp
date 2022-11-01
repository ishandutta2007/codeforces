#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

template<typename flow_t>
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
            if(lvl[a]+1!=lvl[to]||edges[id].res()<=0) continue;
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
            while(flow_t f=blocking_flow(s,numeric_limits<flow_t>::max(),t)) flow+=f;
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
    vector<int> s(n+1,0);
    for(int i=1;i<=n;i++) cin >> s[i];
    vector<int> a(n+1,0);
    for(int i=1;i<=n;i++) cin >> a[i];
    vector<int> d(n+1,0);
    dinic<int> flow(n+m+3);
    vector<array<int,2>> e(m);
    const int source=0,tmp=n+m+1,sink=n+m+2;
    for(int i=1;i<=m;i++)
    {
        auto &[x,y]=e[i-1];
        cin >> x >> y;
        d[x]++; d[y]++;
        flow.add_edge(0,i,1);
        flow.add_edge(i,m+x,1);
        flow.add_edge(i,m+y,1);
    }
    int iflow=m;
    bool ok=1;
    for(int i=1;i<=n;i++)
    {
        if(s[i]==0) flow.add_edge(m+i,tmp,d[i]);
        else
        {
            ok&=(a[i]+d[i]>=0&&((a[i]+d[i])%2)==0);
            flow.add_edge(m+i,sink,(a[i]+d[i])/2);
            iflow-=((a[i]+d[i])/2);
        }
    }
    ok&=(iflow>=0);
    flow.add_edge(tmp,sink,iflow);
    ok&=(flow.max_flow(source,sink)==m);
    if(ok)
    {
        cout << "YES\n";
        for(int i=0;i<m;i++)
        {
            auto [x,y]=e[i];
            if(flow.edges[6*i+2].flow==1) swap(x,y);
            cout << x << " " << y << "\n";
        }
    }
    else cout << "NO\n";
    return 0;
}