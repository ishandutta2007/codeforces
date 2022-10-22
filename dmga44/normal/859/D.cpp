#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

///UH Top
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
typedef pair<int,int> pii;
typedef pair<ld,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<ld,pdd> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<int,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
typedef vector<point> polygon;
typedef pair<point,int> ppi;
#define prec(n) cout.precision(n); cout<<fixed
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(6e1+5)

ld p[MAXN][MAXN][7],e[MAXN][MAXN][7];
ld ins[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<(1<<n);i++)
        for(int j=0;j<(1<<n);j++)
        {
            int x;
            cin >> x;
            ins[i][j]=x;
            ins[i][j]/=100;
        }

    for(int i=0;i<(1<<n);i++)
        p[i][i][0]=1;

    int sz=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=0;j<(1<<n);j+=2*sz)
        {
            for(int k1=j;k1<j+sz;k1++)
                for(int k2=j+sz;k2<j+sz+sz;k2++)
                {
                    p[j][k1][i]+=ins[k1][k2]*p[j][k1][i-1]*p[j+sz][k2][i-1];
                    p[j][k2][i]+=ins[k2][k1]*p[j][k1][i-1]*p[j+sz][k2][i-1];
                }
            for(int k1=j;k1<j+sz;k1++)
                for(int k2=j+sz;k2<j+sz+sz;k2++)
                {
                    e[j][k1][i]=max(e[j][k1][i],e[j][k1][i-1]+e[j+sz][k2][i-1]+p[j][k1][i]*sz);
                    e[j][k2][i]=max(e[j][k2][i],e[j][k1][i-1]+e[j+sz][k2][i-1]+p[j][k2][i]*sz);
                }
//            db("")
//            cout << i << ' ' << j << '\n';
//            for(int k=0;k<2*sz;k++)
//                cout << j+k << ' ' << p[j][j+k][i] << ' ' << e[j][j+k][i] << '\n';
        }
        sz+=sz;
    }

    ld ans=0;
    for(int i=0;i<(1<<n);i++)
        ans=max(ans,e[0][i][n]);
    prec(10);
    db(ans)

    return 0;
}