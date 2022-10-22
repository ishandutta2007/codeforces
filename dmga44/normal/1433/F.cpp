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
typedef pair<ld,pii> pdp;
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
#define MAXN (ll)(7e1+5)

ll dp[MAXN][MAXN][MAXN];

vector<ll> solve(vector<int> v,int k,int c)
{
    int n=v.size();
    for(int i=0;i<=n;i++)
        for(int j=0;j<k;j++)
            for(int l=0;l<=c;l++)
                dp[i][j][l]=-oo;
    dp[0][0][0]=0;
    for(int i=0;i<=n;i++)
        for(int j=0;j<k;j++)
            for(int l=0;l<=c;l++)
            {
                if(l<c)
                    dp[i+1][(j+v[i])%k][l+1]=max(dp[i][j][l]+v[i],dp[i+1][(j+v[i])%k][l+1]);
                dp[i+1][j][l]=max(dp[i+1][j][l],dp[i][j][l]);
            }
    vector<ll> res(k,-1e9);
    for(int i=0;i<k;i++)
        for(int j=0;j<=c;j++)
            res[i]=max(res[i],dp[n][i][j]);
    return res;
}

ll dp1[2][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,m,k;
    cin >> n >> m >> k;
    int res=0;
    for(int i=0;i<2;i++)
        for(int j=0;j<k;j++)
            dp1[i][j]=-1e9;
    dp1[0][0]=0;
    for(int i=0;i<n;i++)
    {
        vector<int> v(m);
        for(int j=0;j<m;j++)
            cin >> v[j];
        vector<ll> x=solve(v,k,m/2);
        int a=i&1;
        int b=1-a;
        for(int j=0;j<k;j++)
        {
            dp1[b][j]=max(dp1[b][j],dp1[a][j]);
            for(int l=0;l<k;l++)
                dp1[b][(j+l)%k]=max(dp1[b][(j+l)%k],dp1[a][j]+x[l]);
        }
    }
    db(dp1[n&1][0])

    return 0;
}
/**
3 4 3
5 2 2 2
1 2 3 4
7 1 1 4

**/