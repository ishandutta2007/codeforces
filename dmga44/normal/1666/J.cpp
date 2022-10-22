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
typedef double ld;
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
const ll mod=(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(2e2+5)

ll a[MAXN][MAXN],ac[MAXN][MAXN];
ll dp[MAXN][MAXN],best[MAXN][MAXN];
ll ans[MAXN];

ll aux(int x1,int y1,int x2,int y2)
{
    return ac[x2+1][y2+1]-ac[x1][y2+1]-ac[x2+1][y1]+ac[x1][y1];
}

void dfs(int i,int j,int k)
{
    if(i==j)
    {
        ans[i]=k;
        return;
    }
    int m=best[i][j];

    ans[m]=k;

    if(m!=i)
        dfs(i,m-1,m);
    if(m!=j)
        dfs(m+1,j,m);
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            cin >> a[i][j];

    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            ac[i+1][j+1]=a[i][j]+ac[i+1][j]+ac[i][j+1]-ac[i][j];

    for(int l=2;l<=n;l++)
        for(int i=0;i+l<=n;i++)
        {
            int j=i+l-1;
            best[i][j]=-1;
            dp[i][j]=1e18;
            for(int k=i;k<i+l;k++)
            {
                ll v=0;
                if(k>i)
                {
                    v-=aux(i,i,k-1,k-1);
                    v+=aux(i,0,k-1,n-1);
                    v+=dp[i][k-1];
                }
                if(k<j)
                {
                    v-=aux(k+1,k+1,j,j);
                    v+=aux(k+1,0,j,n-1);
                    v+=dp[k+1][j];
                }
                if(v<dp[i][j])
                {
                    dp[i][j]=v;
                    best[i][j]=k;
                }
            }
        }

//    for(int i=0;i<n;i++,cout << '\n')
//        for(int j=0;j<n;j++)
//            cout << best[i][j] << ' ';
    dfs(0,n-1,-1);

    for(int i=0;i<n;i++)
        cout << ans[i]+1 << " \n"[i==n-1];

    return 0;
}