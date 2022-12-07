#include <bits/stdc++.h>
using namespace std;

template <typename T>
class Edge
{
public:
    int to, rev, num;
    T flow, cap, cost;
};

template <typename T>
class Network
{
public:

    vector < Edge<T> > *sv;

    Network(int n, int s, int t)
    {
        this->n=n, this->s=s, this->t=t;
        sv=new vector < Edge<T> >[n];
    }

    add_edge(int fr, int to, T cap, T cost, int num=-1)
    {
        if(cost<0) negative=true;
        sv[fr].push_back({to, sv[to].size(), num, 0, cap, cost});
        sv[to].push_back({fr, sv[fr].size()-1, -1, 0, 0, -cost});
    }

    pair <T, T> mincost()
    {
        T pot[n];
        for(int a=0; a<n; a++) pot[a]=0;
        if(negative)
        {
            bool stop=1;
            for(int a=0; a<n; a++)
            {
                bool stop=1;
                for(int b=0; b<n; b++)
                {
                    for(int c=0; c<sv[b].size(); c++)
                    {
                        if(sv[b][c].cap)
                        {
                            int to=sv[b][c].to;
                            T w=pot[b]+sv[b][c].cost;
                            if(pot[to]>w)
                            {
                                if(a==n-1)
                                {
                                    cout<<"Negative cycle!";
                                    exit(0);
                                }
                                pot[to]=w, stop=0;
                            }
                        }
                    }
                }
                if(stop) break;
            }
        }
        T flow=0, cost=0;
        while(1)
        {
            T di[n];
            int pr[n];
            for(int a=0; a<n; a++) di[a]=inf;
            di[s]=0;
            set <pair <T, int> > se;
            se.insert({0, s});
            while(se.size())
            {
                int v=(*se.begin()).second;
                se.erase(se.begin());
                for(int a=0; a<sv[v].size(); a++)
                {
                    if(sv[v][a].flow<sv[v][a].cap)
                    {
                        int to=sv[v][a].to;
                        T w=di[v]+pot[v]+sv[v][a].cost-pot[to];
                        if(di[to]>w)
                        {
                            se.erase({di[to], to});
                            di[to]=w, pr[to]=sv[v][a].rev;
                            se.insert({di[to], to});
                        }
                    }
                }
            }
            if(di[t]==inf) break;
            for(int a=0; a<n; a++)
            {
                if(di[a]==inf) pot[a]=inf;
                else pot[a]+=di[a];
            }
            T f=inf;
            for(int v=t; v!=s; v=sv[v][pr[v]].to)
            {
                int to=sv[v][pr[v]].to, i=sv[v][pr[v]].rev;
                f=min(f, sv[to][i].cap-sv[to][i].flow);
            }
            flow+=f;
            for(int v=t; v!=s; v=sv[v][pr[v]].to)
            {
                int to=sv[v][pr[v]].to, i=sv[v][pr[v]].rev;
                sv[v][pr[v]].flow-=f;
                sv[to][i].flow+=f;
                cost+=f*sv[to][i].cost;
            }
        }
        return {flow, cost};
    }

    ~Network()
    {
        delete [] sv;
    }

private:

    int n, s, t;
    bool negative=false;
    static const T inf=sizeof(T)==4 ? INT_MAX : LLONG_MAX;
};

main()
{
    //freopen("input.txt", "r", stdin);
    int n1, n2, m, R, B, inf=1e9;
    cin>>n1>>n2>>m>>R>>B;
    int s=n1+n2, t=s+1, s2=t+1, t2=s2+1, sq=0, tq=0;
    Network <int> graph(n1+n2+4, s2, t2);
    for(int a=0; a<n1; a++)
    {
        char sy;
        cin>>sy;
        if(sy=='R')
        {
            graph.add_edge(s, a, inf, 0);
            graph.add_edge(s2, a, 1, 0);
            sq++;
        }
        if(sy=='B')
        {
            graph.add_edge(a, t, inf, 0);
            graph.add_edge(a, t2, 1, 0);
            tq++;
        }
        if(sy=='U')
        {
            graph.add_edge(s, a, inf, 0);
            graph.add_edge(a, t, inf, 0);
        }
    }
    for(int a=0; a<n2; a++)
    {
        char sy;
        cin>>sy;
        if(sy=='B')
        {
            graph.add_edge(s, a+n1, inf, 0);
            graph.add_edge(s2, a+n1, 1, 0);
            sq++;
        }
        if(sy=='R')
        {
            graph.add_edge(a+n1, t, inf, 0);
            graph.add_edge(a+n1, t2, 1, 0);
            tq++;
        }
        if(sy=='U')
        {
            graph.add_edge(s, a+n1, inf, 0);
            graph.add_edge(a+n1, t, inf, 0);
        }
    }
    graph.add_edge(s, t2, sq, 0);
    graph.add_edge(s2, t, tq, 0);
    graph.add_edge(t, s, inf, 0);
    for(int a=0; a<m; a++)
    {
        int u, v;
        cin>>u>>v;
        u--, v--, v+=n1;
        graph.add_edge(u, v, 1, R, a);
        graph.add_edge(v, u, 1, B, a);
    }
    pair <int, int> flow=graph.mincost();
    if(flow.first==sq+tq)
    {
        cout<<flow.second<<"\n";
        char an[m];
        for(int a=0; a<m; a++) an[a]='U';
        for(int a=0; a<n1; a++)
        {
            for(int b=0; b<graph.sv[a].size(); b++)
            {
                int flow=graph.sv[a][b].flow, num=graph.sv[a][b].num;
                if(flow>0 and num!=-1) an[num]='R';
            }
        }
        for(int a=n1; a<n1+n2; a++)
        {
            for(int b=0; b<graph.sv[a].size(); b++)
            {
                int flow=graph.sv[a][b].flow, num=graph.sv[a][b].num;
                if(flow>0 and num!=-1) an[num]='B';
            }
        }
        for(int a=0; a<m; a++) cout<<an[a];
    }
    else cout<<-1;
}