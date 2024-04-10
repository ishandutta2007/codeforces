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
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e5+5)

int d[MAXN];
int e[MAXN];

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
    {
        e[u]++;
        return ;
    }
    if(d[u]>d[v])
        swap(u,v);
    d[u]+=d[v];
    d[v]=u;
    e[u]+=e[v];
    e[u]++;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t;
    cin >> t;
    while(t--)
    {
        int n,m;
        cin >> n >> m;
        for(int i=0;i<n;i++)
        {
            d[i]=-1;
            e[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            int x,y;
            cin >> x >> y;
            x--,y--;
            if(x==y)
                continue;
            join(x,y);
        }

        int res=0;
        for(int i=0;i<n;i++)
            if(d[i]<0)
            {
                res+=e[i];
                if(e[i]==-d[i])
                    res++;
            }
        db(res)
//        for(int i=0;i<n;i++)
//        {
//            cout << d[i] << ' ' << e[i] << '\n';
//        }
    }

    return 0;
}