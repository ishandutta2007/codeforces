#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

set<int> g1[MAXN];
int level[MAXN];
bool mk[MAXN];
int d[MAXN];

template<typename T>
struct dinic
{
    struct edge
    {
        int src, dst;
        T cap, flow;
        int rev;
    };

    int n;
    vector< vector<edge> > adj;

    dinic(int n) : n(n), adj(n) {}

    void add_edge(int src, int dst, T cap)
    {
        adj[src].push_back({ src, dst, cap, 0, (int) adj[dst].size() });
        if (src == dst)
            adj[src].back().rev++;
        adj[dst].push_back({ dst, src, 0, 0, (int) adj[src].size() - 1 });
    }

    vector<int> level, iter;

    T augment(int u, int t, T cur)
    {
        if (u == t)
            return cur;
        for (int &i = iter[u]; i < (int) adj[u].size(); ++i)
        {
            edge &e = adj[u][i];
            if (e.cap - e.flow > 0 && level[u] > level[e.dst])
            {
                T f = augment(e.dst, t, min(cur, e.cap - e.flow));
                if (f > 0)
                {
                    e.flow += f;
                    adj[e.dst][e.rev].flow -= f;
                    return f;
                }
            }
        }
        return 0;
    }

    int bfs(int s, int t)
    {
        level.assign(n, n);
        level[t] = 0;
        queue<int> Q;
        for (Q.push(t); !Q.empty(); Q.pop())
        {
            int u = Q.front();
            if (u == s)
                break;
            for (int i = 0; i < (int)adj[u].size(); ++i){
                edge &e = adj[u][i];
                edge &erev = adj[e.dst][e.rev];
                if (erev.cap - erev.flow > 0
                    && level[e.dst] > level[u] + 1)
                {
                    Q.push(e.dst);
                    level[e.dst] = level[u] + 1;
                }
            }
        }
        return level[s];
    }

    const T oo = numeric_limits<T>::max();

    T max_flow(int s, int t)
    {
        for (int u = 0; u < n; ++u) // initialize
            for (int i = 0; i < (int)adj[u].size(); ++i){
                edge &e = adj[u][i];
                e.flow = 0;
            }

        T flow = 0;
        while (bfs(s, t) < n)
        {
            iter.assign(n, 0);
            for (T f; (f = augment(s, t, oo)) > 0;)
                flow += f;
        } // level[u] == n ==> s-side
        return flow;
    }
};

void dfs(int u)
{
    mk[u]=1;
    for(auto v : g1[u])
    {
        if(mk[v])
            continue;
        level[v]=level[u]+1;
        dfs(v);
    }
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
    if(u==v)
        return;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

void solve()
{
    int n;
    cin >> n;
    vector<pii> edges;
    vector<int> deg(n);
    for(int i=0;i<n-1;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        deg[u]++;
        deg[v]++;

        g1[u].insert(v);
        g1[v].insert(u);
        edges.push_back(pii(u,v));
    }

    dfs(0);

    dinic<int> g(n+2);
    int s=n;
    int t=n+1;
    vector<int> m1,m2;
    for(int i=0;i<n;i++)
    {
        int cap=deg[i]-2;
        if(cap<=0)
            continue;
        if(level[i]&1)
            g.add_edge(i,t,cap);
        else
            g.add_edge(s,i,cap);
    }

    for(auto e : edges)
    {
        if(level[e.f]&1)
            g.add_edge(e.s,e.f,1);
        else
            g.add_edge(e.f,e.s,1);
    }

    int x=g.max_flow(s,t);

    vector<pii> to_erase, to_put;
    for(int i=0;i<n;i++)
    {
        if((level[i]&1)==0)
        {
            for(auto e : g.adj[i])
            {
                if(e.flow==1 && e.dst<n && e.dst>=0 && (level[e.dst]&1))
                {
//                    cout << i << ' ' << e.dst << '\n';
                    to_erase.push_back(pii(i,e.dst));
                    deg[i]--;
                    deg[e.dst]--;
                    g1[i].erase(e.dst);
                    g1[e.dst].erase(i);
                }
            }
        }
    }
//    db(to_erase.size())

    for(int i=0;i<n;i++)
    {
        vector<int> to_era;
        for(auto v : g1[i])
        {
            if(deg[i]>2)
            {
                to_erase.push_back(pii(i,v));
                deg[i]--;
                deg[v]--;
                to_era.push_back(v);
            }
        }
        for(auto v : to_era)
        {
            g1[i].erase(v);
            g1[v].erase(i);
        }
    }

    for(int i=0;i<n;i++)
        d[i]=-1;
    for(int i=0;i<n;i++)
        for(auto v : g1[i])
            join(v,i);

    int tot=0;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    for(int i=0;i<n;i++)
    {
        tot+=deg[i];
        pq.push(pii(deg[i],i));
    }

    tot/=2;

    while(tot<n-1)
    {
        tot++;

        pii x1=pq.top();
        pq.pop();
        pii x2=pq.top();
        pq.pop();

        int u=x1.s;
        int v=x2.s;

        if(find(u)==find(v))
        {
            pii temp=x2;
            x2=pq.top();
            pq.pop();
            v=x2.s;

            pq.push(temp);
        }

//        cout << u << ' ' << v << '\n';
        to_put.push_back(pii(u,v));
        deg[u]++;
        deg[v]++;
        pq.push(pii(deg[u],u));
        pq.push(pii(deg[v],v));
        join(u,v);
    }

    db(to_put.size())
    for(int i=0;i<to_erase.size();i++)
    {
        pii p1=to_erase[i];
        pii p2=to_put[i];
        cout << p1.f+1 << ' ' << p1.s+1 << ' ' << p2.f+1 << ' ' << p2.s+1 << '\n';
    }

    for(int i=0;i<n;i++)
    {
        mk[i]=0;
        level[i]=0;
        d[i]=0;
        g1[i].clear();
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        solve();
    }

    return 0;
}
/**
4
7
1 2
1 3
2 4
2 5
3 6
1 7
4
1 2
1 3
3 4
7
1 2
1 3
2 4
2 5
3 6
1 7
7
1 2
1 3
2 4
2 5
3 6
3 7
**/