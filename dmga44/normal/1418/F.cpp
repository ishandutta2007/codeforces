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
typedef complex<ll> point;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(998244353)
#define eps (1e-9)
#define oo (ll)(1e9)
#define pi acos(-1)
#define MAXN (ll)(2e5+5)

vector<int> psn[MAXN];
vector<pii> psnp[MAXN];
vector<int> psm[MAXN];
vector<int> ms[MAXN];
int abi[MAXN];

void update(int p,int v)
{
    while(p<MAXN)
    {
        abi[p]+=v;
        p+=(p&-p);
    }
}

int query(int p)
{
    int res=0;
    while(p)
    {
        res+=abi[p];
        p-=(p&-p);
    }
    return res;
}

int nexx(int l,int r)
{
    int v=query(l-1);
    int s=query(r)-v;
    if(!s)
        return -1;

    int res=0;
    int ac=0;
    for(int po=(1<<17);po;po>>=1)
        if(res+po<MAXN && ac+abi[res+po]<=v)
        {
            res+=po;
            ac+=abi[res];
        }
    return res+1;
}

void doo(int i,int v)
{
    for(auto y : psm[i])
        update(y,v);
}

int32_t main()
{
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);

    ll n,m,l,r;
    cin >> n >> m;
    cin >> l >> r;

    for(int i=1;i<=n;i++)
        for(int j=i;j<=n;j+=i)
        {
            ms[i].push_back(j);
            psn[j].push_back(i);
        }
    for(int i=1;i<=n;i++)
    {
        for(auto y : psn[i])
        {
            int l=(i/y)+1;
            int r=ms[y].size();
            if(l>r)
                continue;
            psnp[i].push_back(pii(l,r));
        }
    }

    for(int i=1;i<=n;i++)
        ms[i].clear();

    for(int i=1;i<=m;i++)
        for(int j=i;j<=m;j+=i)
        {
            ms[i].push_back(j);
            psm[j].push_back(ms[i].size());
        }

    ll pl=m+1;
    ll pr=m;
    for(int i=1;i<=n;i++)
    {
        while((pl-1)*i>=l)
        {
            doo(pl-1,1);
            pl--;
        }
        while(pr*i>r)
        {
            doo(pr,-1);
            pr--;
        }
        if(pl>pr)
        {
            db(-1)
            continue;
        }

        bool ok=0;
        for(auto y : psnp[i])
        {
            int xl=y.f;
            int xr=y.s;
//            db(i)
            int v=nexx(xl,xr);
//            cout << i << ' ' << xl << ' ' << xr << ' ' << v << '\n';
            if(v==-1)
                continue;
            else
            {
                ll d=i/(xl-1);
                int x1=i;
                int x2=d*v;
                int y1=pl-(pl%v);
                if(y1!=pl)
                    y1+=v;
                int y2=(y1/v)*(xl-1);
                cout << x1 << ' ' << y1 << ' ' << x2 << ' ' << y2 << '\n';
                ok=1;
                break;
            }
        }
        if(!ok)
            db(-1)
    }

    return 0;
}