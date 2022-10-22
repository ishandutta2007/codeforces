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
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(6e2+5)

ll d[MAXN][MAXN];
ll b[MAXN][MAXN];
ll best[MAXN][MAXN];
ll l[MAXN][MAXN];
int mk[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            d[i][j]=d[j][i]=oo;
    for(int i=0;i<m;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        d[u][v]=w;
        d[v][u]=w;
        b[u][v]=w;
        b[v][u]=w;
    }

    int q;
    cin >> q;
    for(int i=0;i<q;i++)
    {
        int u,v,w;
        cin >> u >> v >> w;
        u--,v--;
        l[u][v]=w;
        l[v][u]=w;
    }

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            for(int k=0;k<n;k++)
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            if(i!=j)
                for(int k=0;k<n;k++)
                    if(l[i][j]>=d[j][k])
                        best[k][i]=best[i][k]=max(best[i][k],l[i][j]-d[j][k]);

    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            for(int k=0;k<n;k++)
            {
                if(b[k][i] && b[k][i]+d[k][j]<=best[i][j])
                    mk[i][k]=mk[k][i]=1;
                if(b[k][j] && b[k][j]+d[k][i]<=best[i][j])
                    mk[j][k]=mk[k][j]=1;
            }

    int res=0;
    for(int i=0;i<n;i++)
        for(int j=i+1;j<n;j++)
            res+=mk[i][j];
    db(res)

    return 0;
}
/**
4 6
1 2 1
2 3 1
3 4 1
1 3 3
2 4 3
1 4 5
1
1 4 4
**/