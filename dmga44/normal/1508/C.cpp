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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(2e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pii> g[MAXN];
int d[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

bool join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return 0;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    return 1;
}

bool hay(int i,int j)
{
    int pos=lower_bound(all(g[i]),pii(j,0))-g[i].begin();
    if(pos<g[i].size() && g[i][pos].f==j)
        return 1;
    return 0;
}

ll solve1(int n)
{
    for(int i=0;i<n;i++)
        d[i]=-1;

    int mi=0;
    for(int i=0;i<n;i++)
        if(g[i].size()<g[mi].size())
            mi=i;
    for(int i=0;i<n;i++)
        if(!hay(mi,i))
            join(mi,i);
    vector<int> difs;
    vector<int> eqs;
    for(int i=0;i<n;i++)
    {
        if(find(i)!=find(mi))
            difs.push_back(i);
        else
            eqs.push_back(i);
    }
    for(auto u : difs)
        for(int i=0;i<n;i++)
            if(!hay(u,i))
                join(u,i);
    vector<pip> edges;
    for(int i=0;i<n;i++)
        for(auto p : g[i])
            if(i<p.f)
                edges.push_back(pip(p.s,pii(i,p.f)));

    sort(all(edges));

    ll ans=0;
    for(auto p : edges)
    {
        int u=p.s.f;
        int v=p.s.s;
        if(join(u,v))
            ans+=p.f;
    }
    return ans;
}

ll solve(vector<pip> edges,int n)
{
    for(int i=0;i<n;i++)
        d[i]=-1;

    sort(all(edges));

    ll ans=0;
    for(auto p : edges)
    {
        int u=p.s.f;
        int v=p.s.s;
        if(join(u,v))
            ans+=p.f;
    }
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m;
    cin >> n >> m;
    vector<pip> edges;
    ll x=0;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        x^=w;
        u--,v--;
        g[u].push_back(pii(v,w));
        g[v].push_back(pii(u,w));
        edges.push_back(pip(w,pii(u,v)));
    }
    for(int i=0;i<n;i++)
        sort(all(g[i]));
    if(((n*(n-1))/2)-m>=n)
    {
//        db("xxx")
        db(solve1(n))
        return 0;
    }

    sort(all(edges));

    for(int i=0;i<n;i++)
        d[i]=-1;

    vector<pip> useful;
    for(auto p : edges)
    {
        int u=p.s.f;
        int v=p.s.s;
        if(join(u,v))
            useful.push_back(p);
    }

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            if(!hay(i,j))
            {
//                cout << i << ' ' << j << '\n';
                useful.push_back(pip(0,pii(i,j)));
            }

    ll ans=oo;
//    db(x)
    for(int i=0;i+m<(n*(n-1))/2;i++)
    {
        useful[useful.size()-i-1].f=x;
        if(i)
            useful[useful.size()-i].f=0;
//        db("")
//        db(i)
//        for(auto p : useful)
//            cout << p.f << ' ' << p.s.f << ' ' << p.s.s << '\n';
        ans=min(solve(useful,n),ans);
    }
    db(ans)

    return 0;
}
/**
5 6
2 3 11
5 3 7
1 4 10
2 4 14
4 3 8
2 5 6

**/