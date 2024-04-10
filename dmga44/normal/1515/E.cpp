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
#define MAXN (ll)(4e2+5)

ll dp[MAXN][MAXN];
ll pas[MAXN][MAXN];

ll comb(int n,int m)
{
    return pas[n][m+1];
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    ll n,mod;
    cin >> n >> mod;
    pas[0][1]=1;
    for(int i=1;i<MAXN;i++)
        for(int j=1;j<MAXN;j++)
            pas[i][j]=(pas[i-1][j-1]+pas[i-1][j])%mod;

    vector<ll> facs(n+1);
    vector<ll> aux(n+1);
    facs[0]=1;
    for(int i=1;i<=n;i++)
        facs[i]=(facs[i-1]*i)%mod;
    dp[0][0]=1;
    for(int i=1;i<=n;i++)
    {
        for(int j=2;j<=i;j++)
            for(int k=0;k<i;k++)
                dp[i+1][j]=(dp[i+1][j]+((aux[i-k]*comb(i-(j-1),i-k))%mod)*dp[k][j-1])%mod;
        ll sum=0;
        for(int j=1;j<=i;j++)
            sum=(sum+comb(i-1,j-1))%mod;
        aux[i]=dp[i+1][1]=sum;
    }
    
    ll ans=0;
    for(int i=1;i<=n;i++)
    {
        ans=(ans+dp[n+1][i])%mod;
        // cout << i << ' ' << dp[n+1][i] << '\n';
    }
    cout << ans << '\n';

    return 0;
}