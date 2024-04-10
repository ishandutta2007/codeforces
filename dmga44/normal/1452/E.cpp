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
#define mod (ll)(998244353)
#define eps (1e-9)
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(2e3+5)

int a[MAXN][MAXN];
int ac[MAXN][MAXN];

void app(int x1,int y1,int x2,int y2,int v)
{
    a[x1][y1]+=v;
    a[x1][y2+1]-=v;
    a[x2+1][y1]-=v;
    a[x2+1][y2+1]+=v;
}

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    for(int i=0;i<m;i++)
    {
//        db(i)
        int l,r;
        cin >> l >> r;
        l--,r--;
        vector<int> vs(n);
        for(int j=0;j<n;j++)
        {
            int jj=j+k-1;
            int xl=max(l,j);
            int xr=min(r,jj);
            vs[j]=max(0,xr-xl+1);
        }
//        for(int j=0;j<n;j++)
//            cout << vs[j] << ' ';
//        cout << '\n';
        int ma=-1;
        int x=0;
        for(int j=0;j<n;j++)
            if(vs[j]>ma)
            {
                ma=vs[j];
                x=j;
            }
        app(x,0,x,n-1,ma);
        if(x)
            app(0,x,x-1,x,ma);
        if(x+1<n)
            app(x+1,x,n-1,x,ma);
        vector<pip> ords;
        for(int j=0;j<n;j++)
            if(j!=x)
                ords.push_back(pip(vs[j],pii(abs(j-x),j)));
        sort(allr(ords));
        int lastl=x;
        int lastr=x;
        for(auto y : ords)
        {
            int p=y.s.s;
            int v=y.f;
            if(p<x)
            {
                app(p,0,p,p,v);
                if(p)
                    app(0,p,p-1,p,v);
                if(lastr+1<n)
                {
                    app(lastr+1,p,n-1,p,v);
                    app(p,lastr+1,p,n-1,v);
                }

                lastl--;
            }
            else
            {
                app(p,p,n-1,p,v);
                if(p+1<n)
                    app(p,p+1,p,n-1,v);
                if(lastl)
                {
                    app(p,0,p,lastl-1,v);
                    app(0,p,lastl-1,p,v);
                }
                lastr++;
            }
//            db(p)
//            db("")
//            for(int i=0;i<n;i++)
//            {
//                for(int j=0;j<n;j++)
//                    cout << a[i][j] << ' ';
//                cout << '\n';
//            }
        }

    }
//    db("")

    int res=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            ac[i][j]=a[i][j];
            if(i)
                ac[i][j]+=ac[i-1][j];
            if(j)
                ac[i][j]+=ac[i][j-1];
            if(i && j)
                ac[i][j]-=ac[i-1][j-1];
            res=max(res,ac[i][j]);
//            cout << ac[i][j] << ' ';
        }
//        cout << '\n';
    }
    db(res)

    return 0;
}
/**
10 5 3
1 3
2 4
6 9
6 9
1 8

**/