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
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(1e3+5)

int d[MAXN];
int t[MAXN];
vector<int> acs[MAXN];

bool join(int u,int v)
{
    int u1=d[u];
    int u2=t[u];
    int v1=d[v];
    int v2=t[v];
    if(u1==v1)
        return u2==v2;
    if(acs[u1].size()<acs[v1].size())
    {
        swap(u1,v1);
        swap(u2,v2);
    }
    int base=1^v2^u2;
    for(auto x : acs[v1])
    {
        acs[u1].push_back(x);
        t[x]^=base;
        d[x]=u1;
    }
    acs[v1].clear();
    return 0;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,q;
    cin >> n >> m >> q;
    vector<pip> edges;
    map<int,int> mt;
    set<int> sw;
    vector<int> t2(m);
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        edges.push_back(pip(w,pii(u,v)));
        sw.insert(w);
    }

    int cont=0;
    for(auto y : sw)
    {
        mt[y]=cont;
        t2[cont]=y;
        cont++;
    }
    for(int i=0;i<m;i++)
        edges[i].f=mt[edges[i].f];

    vector<pii> ord;
    for(int i=0;i<m;i++)
        ord.push_back(pii(edges[i].f,i));
    sort(allr(ord));
    for(int i=0;i<q;i++)
    {
        int l,r;
        cin >> l >> r;
        l--,r--;
        for(int j=0;j<n;j++)
        {
            d[j]=j;
            t[j]=0;
            acs[j].clear();
            acs[j].push_back(j);
        }
        int res=-1;
        pip edge;
        for(auto e : ord)
        {
            if(e.s>r || e.s<l)
                continue;
            edge=edges[e.s];
            if(join(edge.s.f,edge.s.s))
            {
                res=edge.f;
                break;
            }
        }
        if(res!=-1)
            db(t2[res])
        else
            db(-1)
    }

    return 0;
}