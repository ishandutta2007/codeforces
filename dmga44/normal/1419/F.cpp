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
#define oo (ll)(2e9)
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int d[MAXN];
vector<pip> edges;
vector<pip> tree;
set<int> xs,ys;
int xy[MAXN][2];
int ds;

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

void join(int u,int v)
{
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    ds--;
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    int n,u,v;
    cin >> n;
    ds=n;
    for(int i=0;i<n;i++)
        d[i]=-1;
    vector<pip> xo,yo;
    map<pii,bool> mk;
    for(int i=0;i<n;i++)
    {
        int x,y;
        cin >> x >> y;
        mk[pii(x,y)]=1;
        xy[i][0]=x;
        xy[i][1]=y;
        xo.push_back(pip(x,pii(y,i)));
        yo.push_back(pip(y,pii(x,i)));
        xs.insert(x);
        ys.insert(y);
        for(int j=0;j<i;j++)
        {
            if(xy[i][0]==xy[j][0])
                edges.push_back(pip(abs(xy[i][1]-xy[j][1]),pii(i,j)));
            if(xy[i][1]==xy[j][1])
                edges.push_back(pip(abs(xy[i][0]-xy[j][0]),pii(i,j)));
        }
    }
    sort(all(xo));
    sort(all(yo));

    sort(all(edges));

    for(auto y : edges)
    {
        int w=y.f;
        int uu=y.s.f;
        int vv=y.s.s;
        u=find(uu);
        v=find(vv);
        if(u!=v)
        {
            join(u,v);
            tree.push_back(pip(w,pii(uu,vv)));
//            cout << w << ' ' << uu << ' ' << vv << '\n';
        }
    }
    if(ds>2)
    {
        db(-1)
        return 0;
    }

//    for(auto y : tree)
//        cout << y.f << ' ' << y.s.f << ' ' << y.s.s << '\n';

    int res=0;
    if(n>2)
        res=tree[n-3].f;
    if(tree.size()==n-1)
        res=max(res,(int)(tree[n-2].f+1)/2);
    else
        res=oo;
    for(int i=0;i<n+1;i++)
        d[i]=-1;
    int ac=0;
    ds=n;
//    db("xxx")
    for(int i=0;i<((int)tree.size())-4;i++)
    {
        u=find(tree[i].s.f);
        v=find(tree[i].s.s);
        join(u,v);
        ac=max((int)tree[i].f,ac);
    }
    int base=ds+1;
    vector<pip> extras;
    reverse(all(tree));
    for(int i=0;i<min((int)tree.size(),4);i++)
        extras.push_back(pip(tree[i].f,pii(find(tree[i].s.f),find(tree[i].s.s))));
    vector<pii> state;
    for(int i=0;i<=n;i++)
        if(d[i]<0)
            state.push_back(pii(i,d[i]));
//    db("xxx")
//    for(auto y : state)
//        cout << y.f << ' ' << -y.s << '\n';

    for(auto x : xs)
        for(auto y : ys)
        {
            if(mk[pii(x,y)])
                continue;
//            cout << x << ' ' << y << '\n';
            int vv=ac;
//            db(ac)
            int px=lower_bound(all(xo),pip(x,pii(y,0)))-xo.begin();
            int py=lower_bound(all(yo),pip(y,pii(x,0)))-yo.begin();
//            db("xxx")
            vector<pip> a;
            for(auto y : extras)
                a.push_back(y);
            if(px && xo[px-1].f==x)
                a.push_back(pip(abs(y-xo[px-1].s.f),pii(n,find(xo[px-1].s.s))));
            if(py && yo[py-1].f==y)
                a.push_back(pip(abs(x-yo[py-1].s.f),pii(n,find(yo[py-1].s.s))));
            if(px<n && xo[px].f==x)
                a.push_back(pip(abs(y-xo[px].s.f),pii(n,find(xo[px].s.s))));
            if(py<n && yo[py].f==y)
                a.push_back(pip(abs(x-yo[py].s.f),pii(n,find(yo[py].s.s))));

            sort(all(a));
//            db("xxx")

            for(auto y : a)
            {
                int w=y.f;
                int u=find(y.s.f);
                int v=find(y.s.s);
//                cout << w << ' ' << u << ' ' << v << '\n';
                if(u!=v)
                {
                    vv=max(vv,w);
                    join(u,v);
                }
            }
//            db("xxx")
//            db(vv)
            if(ds==1)
                res=min(res,vv);
            ds=base;
            for(auto y : state)
                d[y.f]=y.s;
        }

    db(res)

    return 0;
}
/**
4
100 0
0 100
-100 0
0 -100

7
0 2
1 0
-3 0
0 -2
-1 -1
-1 -3
-2 -3

5
0 0
0 -1
3 0
-2 0
-2 1

5
0 0
2 0
0 -1
-2 0
-2 1
**/