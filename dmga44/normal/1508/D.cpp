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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(2e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

ll cross(point a, point b) { return imag(conj(a) * b); }

int quad(point x)
{
    if(x.imag()>=0 && x.real()>0) return 0;
    if(x.imag()>0 && x.real()<=0) return 1;
    if(x.imag()<=0 && x.real()<0) return 2;
    return 3;
}

vector<ppi> angular_sort(vector<ppi> &v)
{
    sort(all(v),[&](ppi &a,ppi &b){
        if(quad(a.f)!=quad(b.f)) return quad(a.f)<quad(b.f);
        return cross(a.f,b.f)>0;
    });

    return v;
}

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
        return;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<pip> ts;
    vector<int> p(n);
    vector<point> ps;
    for(int i=0;i<n;i++)
    {
        d[i]=-1;
        int x,y,a;
        cin >> x >> y >> a;
        a--;
        p[i]=a;
        ts.push_back(pip(x,pii(y,i)));
        ps.push_back(point(x,y));
    }

    sort(all(ts));

    for(int i=0;i<n;i++)
        join(i,p[i]);

    int piv=n-1;
    while(piv>=0 && ts[piv].s.s==p[ts[piv].s.s])
        piv--;
    if(piv==-1)
    {
        db(0)
        return 0;
    }

    piv=ts[piv].s.s;
    vector<ppi> vp;
    for(int i=0;i<n;i++)
        if(i!=piv && i!=p[i])
            vp.push_back(ppi(ps[i]-ps[piv],i));

    angular_sort(vp);

    vector<bool> mk(n);
    vector<pii> ans;
    int cont=0;
    for(int i=0;i<vp.size();i++)
    {
        int c=find(vp[i].s);
        if(mk[c])
            continue;
        if(cont)
        {
            ans.push_back(pii(vp[i].s,vp[i-1].s));
            swap(p[vp[i].s],p[vp[i-1].s]);
        }
        mk[c]=1;
        cont++;
    }

    while(p[piv]!=piv)
    {
        ans.push_back(pii(piv,p[piv]));
        swap(p[piv],p[p[piv]]);
    }

    db(ans.size())
    for(auto p : ans)
        cout << p.f+1 << ' ' << p.s+1 << '\n';

    return 0;
}