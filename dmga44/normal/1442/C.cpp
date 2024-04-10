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
//typedef complex<ld> point;
//typedef vector<point> polygon;
//typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<pii> g[MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

struct point{
    int f,s;
    point() : f(0),s(0){}
    point(int x,int y) : f(x),s(y){}
};
point best[MAXN];
map<int,int> bb[MAXN];

bool const operator>(const point a,const point b)
{
    int ax=a.f;
    int ay=a.s;
    int bx=b.f;
    int by=b.s;
    if(max(ay,by)<=20)
        return (1<<(ay+1))+ax>(1<<(by+1))+bx;
    if(ay==by)
        return ax>bx;
    return ay>by;
}

bool const operator<(const point a,const point b)
{
    int ax=a.f;
    int ay=a.s;
    int bx=b.f;
    int by=b.s;
    if(max(ay,by)<=20)
        return (1<<(ay+1))+ax<(1<<(by+1))+bx;
    if(ay==by)
        return ax<bx;
    return ay<by;
}
typedef pair<point,int> ppi;

void dijkstra()
{
    priority_queue<ppi,vector<ppi>,greater<ppi>> pq;
    best[0].f=0;
    best[0].s=-1;
    pq.push(ppi(best[0],0));
    while(!pq.empty())
    {
        ppi x=pq.top();
        pq.pop();
        int u=x.s;
//        db(u)
        int ax=x.f.f;
        int ay=x.f.s;
//        cout << ax << ' ' << ay << '\n';
        for(auto e : g[u])
        {
            if(e.s!=(ay&1))
            {
                if(best[e.f]>point(ax+1,ay) || best[e.f].s==ay-1 || (best[e.f].s>ay && ay<20))
                {
                    if(best[e.f]>point(ax+1,ay))
                        best[e.f]=point(ax+1,ay);
                    if(!bb[e.f][ay])
                        bb[e.f][ay]=1e6;
                    if(ax+1<bb[e.f][ay])
                        bb[e.f][ay]=ax+1;
                    else
                        continue;
                    pq.push(ppi(point(ax+1,ay),e.f));
                }
            }
            else
                if(best[e.f]>point(ax+1,ay+1) || best[e.f].s==ay || (best[e.f].s>ay+1 && ay+1<20))
                {
                    if(best[e.f]>point(ax+1,ay+1))
                        best[e.f]=point(ax+1,ay+1);
                    if(!bb[e.f][ay+1])
                        bb[e.f][ay+1]=1e6;
                    if(ax+1<bb[e.f][ay+1])
                        bb[e.f][ay+1]=ax+1;
                    else
                        continue;
                    pq.push(ppi(point(ax+1,ay+1),e.f));
                }
        }
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        best[i].f=1e6;
        best[i].s=1e6;
    }
    for(int i=0;i<m;i++)
    {
        int u,v;
        cin >> u >> v;
        u--,v--;
        g[u].push_back(pii(v,0));
        g[v].push_back(pii(u,1));
    }

    dijkstra();

    point res=best[n-1];
    ll ans=qp(2,res.s+1)-1;
    ans=(ans+res.f)%mod;
    db(ans)

    return 0;
}