#pragma GCC optimize("Ofast","unroll-loops","omit-frame-pointer","inline") //Optimization flags
#pragma GCC option("arch=native","tune=native","no-zero-upper") //Enable AVX
#pragma GCC target("avx2") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define f first
#define s second
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<ll,ll> pii;
typedef pair<double,ll> pdi;
typedef pair<ld,ld> pdd;
typedef pair<double,ll> pdi;
typedef pair<double,pii> pdp;
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define eps (1e-9)
#define oo (ll)(0x3f3f3f3f)
#define pi acos(-1)
#define MAXN (ll)(2e6+5)

ll dp[MAXN][2];

void prec()
{
    dp[1][0]=0;
    dp[1][1]=0;
    dp[2][0]=0;
    dp[2][1]=0;
    for(int i=3;i<MAXN;i++)
    {
        dp[i][1]=(1+dp[i-1][0]+2*dp[i-2][0])%mod;
        ///max(dp[i-1][0],dp[i-1][1])
        ll ad1=1;
        if((i-1)%3)
            ad1=0;
        ///max(dp[i-2][0],dp[i-2][1])
        ll ad2=1;
        if((i-2)%3)
            ad2=0;
        dp[i][0]=(dp[i-1][ad1]+2*dp[i-2][ad2])%mod;
    }
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    prec();

//    for(int i=1;i<40;i++)
//        cout << i << ' ' << dp[i][0] << ' ' << dp[i][1] << '\n';
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        if(n%3)
            cout << (4*dp[n][0])%mod << '\n';
        else
            cout << (4*dp[n][1])%mod << '\n';
    }

    return 0;
}