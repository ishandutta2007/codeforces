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
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

int d[MAXN];

int find(int u)
{
    if(d[u]<0)
        return u;
    d[u]=find(d[u]);
    return d[u];
}

int join(int u,int v)
{
    u=find(u);
    v=find(v);
    if(u==v)
        return -1;
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    return -d[u];
}

ll dot(point a, point b) { return real(conj(a) * b); }

ll cross(point a, point b) { return imag(conj(a) * b); }

ll area2(point a, point b, point c) { return cross(b - a, c - a); }

struct hull : vector<point>
{
    void add_point(point p)
    {
        for (int s = size(); s > 1; --s)
            if (area2(at(s - 2), at(s - 1), p) < 0) break;
            else pop_back();
        push_back(p);
    }

    ll max_dot(point p)
    {
        int lo = 0, hi = (int) size() - 1, mid;

        while (lo < hi)
        {
            mid = (lo + hi) / 2;

            if (dot(at(mid), p) <= dot(at(mid + 1), p))
                lo = mid + 1;
            else hi = mid;
        }

        return dot(at(lo), p);
    }
};

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    vector<ll> ac(n+1);
    vector<ll> a(n);
    vector<pii> evs;
    hull dp;
    dp.add_point(point(0,0));
    for(int i=0;i<n;i++)
    {
        cin >> a[i];
        ac[i+1]=ac[i]+a[i];
        ll v=0;
        for(ll po=(1<<30);po;po>>=1)
            if(dp.max_dot(point(-1,v+po))>(v+po)*(i+1)-ac[i+1])
                v+=po;
        dp.add_point(point(ac[i+1],i+1));
        v++;
        if(i!=n-1)
            evs.push_back(pii(v,i));
    }
//    for(int i=0;i<n;i++)
//        cout << evs[i].f << ' ';
//    cout << '\n';
    vector<ll> ks(m);
    for(int i=0;i<m;i++)
        cin >> ks[i];

    vector<bool> mk(n);
    for(int i=0;i<n;i++)
        d[i]=-1;

    int v=0;
    sort(allr(evs));
    int p=0;
    vector<ll> res(m);
    for(int i=m-1;i>=0;i--)
    {
        while(p<evs.size() && evs[p].f>ks[i])
        {
            int pos=evs[p].s;
            if(pos && mk[pos-1])
                v=max(v,join(pos,pos-1));
            if(pos+1<n && mk[pos+1])
                v=max(v,join(pos,pos+1));
            mk[pos]=1;
            v=max(v,1);
            p++;
        }
        res[i]=v;
    }

    for(int i=0;i<m;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}