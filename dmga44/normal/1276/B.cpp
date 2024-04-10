#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX
#pragma GCC optimize("03")
#pragma GCC target ("sse4")

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

bool tt[MAXN][2];
int d[MAXN];

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
        return ;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m,a,b;
        cin >> n >> m >> a >> b;
        for(int i=0;i<n;i++)
        {
            d[i]=-1;
            tt[i][0]=tt[i][1]=0;
        }
        a--,b--;
        vector<pii> extra;
        for(int i=0;i<m;i++)
        {
            int u,v;
            cin >> u >> v;
            u--,v--;
            if(u==a || u==b || v==a || v==b)
                extra.push_back(pii(u,v));
            else
                join(u,v);
        }

        set<int> rs;
        for(int i=0;i<n;i++)
            if(i!=a && i!=b)
                rs.insert(find(i));

        for(auto y : extra)
        {
            int ty=y.f;
            int other=y.s;
            if(ty!=a && ty!=b)
                swap(ty,other);
            if(other==a || other==b)
                continue;
            tt[find(other)][ty==a]=1;
        }

        ll sa=0;
        ll sb=0;
        for(auto y : rs)
        {
            if(tt[y][0]==1 && tt[y][1]==0)
                sa+=-d[y];
            if(tt[y][0]==0 && tt[y][1]==1)
                sb+=-d[y];
        }
        db(sa*sb)


    }

    return 0;
}