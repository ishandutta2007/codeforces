#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
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
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

struct DSU_WITH_ROLLBACKS
{
    struct dsu_save
    {
        int u, urank, v, vrank, comps;
        bool bipart;
    };

    stack<dsu_save> op;

    vector<int> rnk;
    vector<bool> col;
    bool bipartite;
    int comps;

    DSU_WITH_ROLLBACKS()
    {

    }

    DSU_WITH_ROLLBACKS(int N)
    {
        init(N);
    }

    void init(int N)
    {
        rnk.clear();
        col.clear();
        while(!op.empty())op.pop();
        rnk.resize(N);
        col.resize(N);
        for(int i = 0 ; i < N ; i++)
        {
            rnk[i] = 1;
            col[i] = false;
        }
        bipartite = true;
        comps = N;
    }

    pair<int,bool> find(int x)
    {
        if(rnk[x] > 0)return {x, col[x]};
        pair<int,bool> tp = find(-rnk[x]);
        tp.second ^= col[x];
        return tp;
    }

    void join(int a, int b)
    {
        pair<int,bool> ta = find(a), tb = find(b);
        a = ta.first;
        b = tb.first;
        op.push({a, rnk[a], b, rnk[b], comps, bipartite});
        if(a == b)
        {
            if(ta.second == tb.second)bipartite = false;
            return;
        }
        comps--;
        if(rnk[a] < rnk[b])swap(a,b);
        rnk[a] += rnk[b];
        rnk[b] = -a;
        col[b] = col[b]^(ta.second == tb.second);
    }

    void rollback()
    {
        if(op.empty())return;
        dsu_save x = op.top();
        op.pop();
        comps = x.comps;
        bipartite = x.bipart;
        rnk[x.u] = x.urank;
        col[x.u] = false;
        rnk[x.v] = x.vrank;
        col[x.v] = false;
    }
};

int f[MAXN];
int c[MAXN];
bool is_bip[MAXN];
vector<pip> g[MAXN];
vector<pii> in[MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<n;i++)
    {
        cin >> c[i];
        c[i]--;
        f[c[i]]++;
    }

    DSU_WITH_ROLLBACKS dsu(n);

    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        if(c[u]==c[v])
            in[c[u]].push_back(pii(u,v));
        else
        {
            if(c[u]<c[v])
                swap(u,v);
            g[c[u]].push_back(pip(c[v],pii(u,v)));
        }
    }

    ll ceroes=0;
    for(int i=0;i<k;i++)
    {
        if(!f[i])
            ceroes++;
        sort(all(g[i]));
    }
    ll bip=0;
    ll res=0;
    for(int i=0;i<k;i++)
    {
        if(!f[i])
            continue;
        bool ok=1;
        for(auto y : in[i])
        {
            int u=y.f;
            int v=y.s;
            dsu.join(u,v);
        }
        ok=dsu.bipartite;
        is_bip[i]=ok;
        if(ok)
            bip++;
        else
            for(auto y : in[i])
                dsu.rollback();
    }

    res+=(ceroes*(ceroes-1))/2;
    res+=bip*ceroes;
    res+=(bip*(bip-1))/2;
    for(int i=0;i<k;i++)
    {
        if(!is_bip[i])
            continue;
        int pos=0;
        while(pos<g[i].size())
        {
            vector<pii> edges;
            int l=pos;
            while(pos<g[i].size() && g[i][pos].f==g[i][l].f)
            {
                edges.push_back(g[i][pos].s);
                pos++;
            }

            if(!is_bip[g[i][l].f])
                continue;
            res--;
            for(auto y : edges)
            {
                int u=y.f;
                int v=y.s;
                dsu.join(u,v);
            }
            if(dsu.bipartite)
                res++;
            for(auto y : edges)
                dsu.rollback();
        }
    }
    db(res)

    return 0;
}
/**
6 6 2
1 1 1 2 2 2
1 2
1 3
2 3
4 5
4 6
5 6
**/