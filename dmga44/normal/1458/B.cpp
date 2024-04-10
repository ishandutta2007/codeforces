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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e2+5)

int dp[MAXN][MAXN*MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN*MAXN;j++)
            dp[i][j]=-1e9;

    dp[0][0]=0;
    int n;
    cin >> n;
    int sum=0;
    for(int i=0;i<n;i++)
    {
        int a,b;
        cin >> a >> b;
        sum+=b;
        for(int j=MAXN-1;j>0;j--)
            for(int k=MAXN*MAXN-1;k>=a;k--)
                dp[j][k]=max(dp[j][k],dp[j-1][k-a]+b);
    }

    vector<ld> res(n);
    for(int i=1;i<=n;i++)
        for(int j=0;j<MAXN*MAXN;j++)
            res[i-1]=max(res[i-1],min(((ld)dp[i][j])+((ld)(sum-dp[i][j]))/2.0,(ld)j));

    prec(10);
    for(int i=0;i<n;i++)
        cout << res[i] << ' ';
    cout << '\n';

    return 0;
}