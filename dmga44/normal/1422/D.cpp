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
typedef unsigned long long ull;
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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

int d[MAXN];
map<int,vector<int> > mx;
map<int,vector<int> > my;
vector<pii> g[MAXN];
int xy[MAXN][2];
ll dis[MAXN];
bool mk[MAXN];

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

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    ll sx,sy,fx,fy;
    cin >> sx >> sy >> fx >> fy;
    ll res=abs(fx-sx)+abs(sy-fy);
    if(m==0)
    {
        db(res)
        return 0;
    }
    for(int i=0;i<m;i++)
        d[i]=-1;
    set<int> xs;
    set<int> ys;
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin >> x >> y;
        xy[i][0]=x;
        xy[i][1]=y;
        mx[x].push_back(i);
        my[y].push_back(i);
        xs.insert(x);
        ys.insert(y);
    }

    for(auto y : mx)
    {
        vector<int> ts=y.s;
        for(int i=1;i<ts.size();i++)
            join(ts[i-1],ts[i]);
    }

    for(auto y : my)
    {
        vector<int> ts=y.s;
        for(int i=1;i<ts.size();i++)
            join(ts[i-1],ts[i]);
    }

    for(int i=0;i<m;i++)
    {
        int u=find(i);
        ll ds=min(abs(sx-xy[i][0]),abs(sy-xy[i][1]));
        ll df=abs(fx-xy[i][0])+abs(fy-xy[i][1]);
        g[u].push_back(pii(m,ds));
        g[m].push_back(pii(u,ds));
        g[u].push_back(pii(m+1,df));
        g[m+1].push_back(pii(u,df));
    }

    vector<int> xx;
    for(auto y : xs)
        xx.push_back(y);
    vector<int> yy;
    for(auto y : ys)
        yy.push_back(y);

    for(int i=1;i<xx.size();i++)
    {
        int u=find(mx[xx[i-1]][0]);
        int v=find(mx[xx[i]][0]);
        if(u==v)
            continue;
        g[u].push_back(pii(v,xx[i]-xx[i-1]));
        g[v].push_back(pii(u,xx[i]-xx[i-1]));
    }

    for(int i=1;i<yy.size();i++)
    {
        int u=find(my[yy[i-1]][0]);
        int v=find(my[yy[i]][0]);
        if(u==v)
            continue;
        g[u].push_back(pii(v,yy[i]-yy[i-1]));
        g[v].push_back(pii(u,yy[i]-yy[i-1]));
    }

    priority_queue<pii,vector<pii>,greater<pii> > pq;
    pq.push(pii(0,m));
    while(!pq.empty())
    {
        pii tt=pq.top();
        pq.pop();
        int u=tt.s;
        ll w=tt.f;
        if(mk[u])
            continue;

        mk[u]=1;
        dis[u]=w;
        for(auto y : g[u])
        {
//            cout << u << ' ' << y.f << ' ' << y.s << '\n';
            if(!mk[y.f])
                pq.push(pii(w+y.s,y.f));
        }
    }

    db(min(dis[m+1],res))

    return 0;
}