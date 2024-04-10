//#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
//#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

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
const ll mod=(998244353);
const ld eps=(1e-9);
const ll oo=(ll)(1e18+5);
#define pi acos(-1)
#define MAXN (ll)(5e1+5)

ll dp[MAXN][MAXN*MAXN];
ll dp2[MAXN][MAXN];
ll dp3[MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,mod;
    cin >> n >> mod;
    dp[1][0]=1;
    for(int i=2;i<=n;i++)
        for(int j=0;j<i;j++)
            for(int k=j;k<=(i*(i-1))/2;k++)
                dp[i][k]=(dp[i][k]+dp[i-1][k-j])%mod;


//    for(int i=1;i<=n;i++,cout << '\n')
//        for(int j=0;j<=(i*(i-1))/2;j++)
//            cout << dp[i][j] << ' ';

    for(int i=1;i<n;i++)
    {
        ll ss=0;
        ll sum=0;
        for(int k=i*(i-1)/2;k>=0;k--)
        {
            ss=(ss+dp[i][k]*(sum))%mod;
            sum=(sum+dp[i][k])%mod;
        }
        dp2[i][0]=ss;
        for(int j=1;j<=i;j++)
        {
            for(int k=0;k+j<=(i*(i-1))/2;k++)
                ss=(ss-((dp[i][k]*dp[i][k+j])%mod)+mod)%mod;
            dp2[i][j]=ss;
        }
//        for(int j=0;j<=i;j++)
//            cout << i << ' ' << j << ' ' << dp2[i][j] << "\n";
    }

    dp3[1]=0;
    dp3[2]=0;
    for(int i=3;i<=n;i++)
    {
        dp3[i]=(dp3[i-1]*i)%mod;
        for(int j=1;j<i;j++)
            dp3[i]=(dp3[i]+dp2[i-1][j]*(i-j))%mod;
    }
    db(dp3[n])

    return 0;
}