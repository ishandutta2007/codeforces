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
    const int N=50000;
    vector<int> id(N+1,-1);
    int tc;
    cin >> tc;
    while(tc--)
    {
        int n;
        cin >> n;
        vector<int> a(n);
        for(int i=0;i<n;i++)
        {
            cin >> a[i];
            id[a[i]]=i;
        }
        vector<array<int,2>> edges;
        auto add=[&](int x,int y)
        {
            if(x!=y)
            {
                edges.push_back({x,y});
                edges.push_back({x+n,y+n});
            }
            edges.push_back({x,y+n});
        };
        for(int x:a)
        {
            for(int i=1;i*i<=x;i++)
            {
                if(x%i) continue;
                if(id[i]!=-1) add(id[x],id[i]);
                if(i*i<x&&id[x/i]!=-1) add(id[x],id[x/i]);
            }
        }
        dinic<int> g(4*n+2);
        auto in=[&](int x){return (2*x+1);};
        auto out=[&](int x){return (2*x+2);};
        int s=0,t=4*n+1;
        for(auto [x,y]:edges) g.add_edge(out(x),in(y),1);
        for(int i=0;i<2*n;i++)
        {
            g.add_edge(s,out(i),1);
            g.add_edge(in(i),t,1);
        }
        cout << n-(2*n-g.max_flow(s,t)) << "\n";
        for(int x:a) id[x]=-1;
    }
    return 0;
}