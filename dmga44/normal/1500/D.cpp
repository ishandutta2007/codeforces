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
#define MAXN (ll)(1.5e3+5)

int sz[MAXN][MAXN];
int cs[MAXN][MAXN][12];
int ds[MAXN][MAXN][12];
int c[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

//    freopen(".in","r",stdin);

    int n,q;
    cin >> n >> q;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> c[i][j];
//    db("xxx")
    for(int i=n-1;i>=0;i--)
        for(int j=n-1;j>=0;j--)
        {
            vector<pii> ts;
            ts.push_back(pii(0,c[i][j]));
            for(int dx=0;dx<2;dx++)
                for(int dy=0;dy<2;dy++)
                {
                    if(i+dx>=n || j+dy>=n)
                        continue;
                    int ii=i+dx;
                    int jj=j+dy;
                    for(int k=0;k<sz[ii][jj];k++)
                        ts.push_back(pii(ds[ii][jj][k]+1,cs[ii][jj][k]));
                }

            sort(all(ts));

//            db("")
//            cout << i << ' ' <<  j << '\n';
            for(auto p : ts)
            {
                if(sz[i][j]==q+1)
                    break;
//                cout << "par: " << p.f << ' ' << p.s << '\n';
                int x=p.s;
                bool ok=1;
                for(int k=0;k<sz[i][j] && ok;k++)
                    ok&=(x!=cs[i][j][k]);
                if(ok)
                {
                    cs[i][j][sz[i][j]]=x;
                    ds[i][j][sz[i][j]]=p.f;
                    sz[i][j]++;
                }
            }
        }
//    db("xxx")

    vector<int> res(n+1);
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
        {
//            cout << i << ' ' << j << ' ' << sz[i][j];
            if(sz[i][j]<=q)
            {
//                cout << ' ' << min(n-i,n-j);
                res[min(n-j,n-i)]++;
            }
            else
            {
//                cout << ' ' << min(ds[i][j][q],min(n-i,n-j));
                res[min(ds[i][j][q],min(n-i,n-j))]++;
            }
//            db("")
        }

    for(int i=n-1;i>=0;i--)
        res[i]+=res[i+1];
    for(int i=1;i<=n;i++)
        db(res[i])

    return 0;
}
/**
3 4
1 2 3
4 5 6
7 8 9
**/