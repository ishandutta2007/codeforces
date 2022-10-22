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
typedef complex<ll> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

vector<pii> g[MAXN];
bool mk[MAXN];
bool res[MAXN];
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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,m,u,v;
    cin >> n >> m;
    for(int i=0;i<m;i++)
        d[i]=-1;
    priority_queue<pii,vector<pii>,greater<pii>> pq;
    vector<pip> edges;
    for(int i=0;i<n;i++)
    {
        int k;
        cin >> k;
        if(k==1)
        {
            cin >> u;
            u--;
            pq.push(pii(i,u));
        }
        else
        {
            cin >> u >> v;
            u--,v--;
            edges.push_back(pip(i,pii(u,v)));
            g[u].push_back(pii(i,v));
            g[v].push_back(pii(i,u));
        }
    }

//    db("xxx")
    while(!pq.empty())
    {
        pii x=pq.top();
        pq.pop();

        int u=x.s;
        if(mk[u])
            continue;
        int id=x.f;
        mk[u]=1;
        res[id]=1;
        for(auto p : g[u])
            pq.push(p);
    }
//    db("xxx")

    for(auto y : edges)
    {
        int id=y.f;
        int u=y.s.f;
        int v=y.s.s;
        if(mk[u])
            continue;
        res[id]=join(u,v);
    }

    ll r1=1;
    int r2=0;
    vector<int> ans;
    for(int i=0;i<n;i++)
    {
        if(res[i])
        {
            r2++;
            r1=(r1*2)%mod;
            ans.push_back(i+1);
        }
    }

    cout << r1 << ' ' << r2 << '\n';
    for(auto y : ans)
        cout << y << ' ';
    cout << '\n';

    return 0;
}