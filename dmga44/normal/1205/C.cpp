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
const ll oo=(ll)(1e9);
#define pi acos(-1)
#define MAXN (ll)(5e1+5)

int d[MAXN*MAXN];
vector<ppp> edges;

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

int n;

int trans(int i,int j)
{
    return (i-1)*n+j-1;
}

vector<pip> g[MAXN][MAXN];
int v1[MAXN][MAXN];
int v2[MAXN][MAXN];
bool mk[MAXN][MAXN];

int ask(ppp p)
{
    int x1=p.f.f;
    int y1=p.f.s;
    int x2=p.s.f;
    int y2=p.s.s;
    cout << "? " << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n' ;
    cout.flush();

    int res;
    cin >> res;
    return res;
}

void dfs(int x,int yy)
{
    mk[x][yy]=1;
    for(auto y : g[x][yy])
    {
        int c=y.f;
        int x2=y.s.f;
        int y2=y.s.s;
        if(mk[x2][y2])
            continue;
        v1[x2][y2]=(v1[x][yy]+c)&1;
        dfs(x2,y2);
    }
}

bool solve1(int x1,int y1,int x2,int y2)
{
//    cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
    bool res=0;
    for(int i=0;i<(1<<((x2-x1+1)*(y2-y1+1)));i++)
    {
        if(__builtin_popcount(i)!=(x2-x1)+(y2-y1+1))
            continue;
        if(!(i&1))
            continue;
        if(!(i&(1<<( ((x2-x1+1)*(y2-y1+1)) -1))))
            continue;
        vector<pii> path;
        for(int j=0;j<((x2-x1+1)*(y2-y1+1));j++)
        {
            if(!(i&(1<<j)))
                continue;
            int ax=j/(y2-y1+1);
            int ay=j%(y2-y1+1);
            path.push_back(pii(x1+ax,y1+ay));
        }

        bool ok=1;
        for(int j=1;j<path.size();j++)
        {
            int x1=path[j-1].f;
            int y1=path[j-1].s;
            int x2=path[j].f;
            int y2=path[j].s;
            ok&=(x2>=x1 && y2>=y1);
            ok&=(x1+y1+1==x2+y2);
        }

        bool kk=1;
        for(int j=0;j<path.size();j++)
            kk&=(v1[path[j].f][path[j].s]==v1[path[path.size()-j-1].f][path[path.size()-j-1].s]);
        if(ok && kk)
            res=1;
    }
    return res;
}

bool solve2(int x1,int y1,int x2,int y2)
{
    bool res=0;
    for(int i=0;i<(1<<((x2-x1+1)*(y2-y1+1)));i++)
    {
        if(__builtin_popcount(i)!=(x2-x1)+(y2-y1+1))
            continue;
        if(!(i&1))
            continue;
        if(!(i&(1<<( ((x2-x1+1)*(y2-y1+1)) -1))))
            continue;
        vector<pii> path;
        for(int j=0;j<((x2-x1+1)*(y2-y1+1));j++)
        {
            if(!(i&(1<<j)))
                continue;
            int ax=j/(y2-y1+1);
            int ay=j%(y2-y1+1);
            path.push_back(pii(x1+ax,y1+ay));
        }

        bool ok=1;
        for(int j=1;j<path.size();j++)
        {
            int x1=path[j-1].f;
            int y1=path[j-1].s;
            int x2=path[j].f;
            int y2=path[j].s;
            ok&=(x2>=x1 && y2>=y1);
            ok&=(x1+y1+1==x2+y2);
        }

        bool kk=1;
        for(int j=0;j<path.size();j++)
            kk&=(v2[path[j].f][path[j].s]==v2[path[path.size()-j-1].f][path[path.size()-j-1].s]);
        if(ok && kk)
            res=1;
    }
    return res;
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    cin >> n;
    for(int i=0;i<n*n;i++)
        d[i]=-1;
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            if(i+1<=n && j+1<=n)
            {
                if(join(trans(i,j),trans(i+1,j+1)))
                    edges.push_back(ppp(pii(i,j),pii(i+1,j+1)));
            }
            if(i+2<=n)
            {
                if(join(trans(i,j),trans(i+2,j)))
                    edges.push_back(ppp(pii(i,j),pii(i+2,j)));
            }
            if(j+2<=n)
            {
                if(join(trans(i,j),trans(i,j+2)))
                    edges.push_back(ppp(pii(i,j),pii(i,j+2)));
            }
        }
    }

    for(auto p : edges)
    {
        int x1=p.f.f;
        int y1=p.f.s;
        int x2=p.s.f;
        int y2=p.s.s;
        int c=ask(p);
        c=1-c;
        g[x1][y1].push_back(pip(c,pii(x2,y2)));
        g[x2][y2].push_back(pip(c,pii(x1,y1)));
    }

    v1[1][1]=v1[1][2]=1;
    dfs(1,1);
    dfs(1,2);

    for(int i=1;i<=n;i++)
        for(int j=1;j<=n;j++)
        {
            if((i+j)&1)
                v2[i][j]=1-v1[i][j];
            else
                v2[i][j]=v1[i][j];
        }

//    for(int i=1;i<=n;i++,cout << '\n')
//        for(int j=1;j<=n;j++)
//            cout << v1[i][j];
//    cout << '\n';
//    for(int i=1;i<=n;i++,cout << '\n')
//        for(int j=1;j<=n;j++)
//            cout << v2[i][j];
//    cout << '\n';

//    db("xxx")
    vector<ppp> pos;
    for(int x1=1;x1<=n;x1++)
        for(int y1=1;y1<=n;y1++)
            for(int x2=x1;x2<=n;x2++)
                for(int y2=y1;y2<=n;y2++)
                    if((x1+y1+3==x2+y2 || x1+y1+5==x2+y2) && solve1(x1,y1,x2,y2)!=solve2(x1,y1,x2,y2))
                        pos.push_back(ppp(pii(x1,y1),pii(x2,y2)));
//    db("xxx")
    int kk=ask(pos[0]);
    cout << "!\n";
    if(kk==solve1(pos[0].f.f,pos[0].f.s,pos[0].s.f,pos[0].s.s))
    {
        for(int i=1;i<=n;i++,cout << '\n')
            for(int j=1;j<=n;j++)
                cout << v1[i][j];
        cout << '\n';
        cout.flush();
    }
    else
    {
        for(int i=1;i<=n;i++,cout << '\n')
            for(int j=1;j<=n;j++)
                cout << v2[i][j];
        cout << '\n';
        cout.flush();
    }

    return 0;
}
/**
100
001
000

0
0
0
0
1
1
1
**/