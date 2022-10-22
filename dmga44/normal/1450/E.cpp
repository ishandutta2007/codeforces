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
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
#define mod (ll)(1e9+7)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

int d[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            d[i][j]=1e4;
    for(int i=0;i<n;i++)
        d[i][i]=0;

    vector<pii> edges;
    for(int i=0;i<m;i++)
    {
        int u,v,b;
        cin >> u >> v >> b;
        u--,v--;
        edges.push_back(pii(u,v));
        if(b)
        {
            d[u][v]=1;
            d[v][u]=-1;
        }
        else
        {
            d[u][v]=1;
            d[v][u]=1;
        }
    }

    for(int k=0;k<n;k++)
        for(int i=0;i<n;i++)
            for(int j=0;j<n;j++)
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
    bool ok=1;
    for(int i=0;i<n;i++)
        ok&=(d[i][i]>=0);

    int ma=0;
    int u=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(d[i][j]>ma)
            {
                ma=d[i][j];
                u=i;
            }

    vector<int> res(n);
    res[u]=0;
    for(int i=0;i<n;i++)
        if(i!=u)
            res[i]=d[u][i];

    for(int i=0;i<m;i++)
        ok&=((res[edges[i].f]&1)!=(res[edges[i].s]&1));

    if(ok)
    {
        db("YES")
        db(ma)
        for(int i=0;i<n;i++)
            cout << res[i] << ' ';
        cout << '\n';
    }
    else
        db("NO")

    return 0;
}