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
const ll mod=(ll)(1ll<<60);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(1e5+5)

ll a[MAXN];
ll dp[MAXN][5];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    string s;
    cin >> s;
    for(int i=0;i<n;i++)
        cin >> a[i];

    string x="hard";
    for(int i=0;i<=n;i++)
        for(int j=0;j<5;j++)
            dp[i][j]=1e18;
    dp[0][0]=0;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<4;j++)
        {
            if(s[i]==x[j])
            {
                dp[i+1][j+1]=min(dp[i+1][j+1],dp[i][j]);
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]+a[i]);
            }
            else
                dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
        }
    }

    ll res=1e18;
    for(int i=0;i<4;i++)
        res=min(res,dp[n][i]);
    db(res)

    return 0;
}