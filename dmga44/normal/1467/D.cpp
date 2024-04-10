#pragma GCC optimize("Ofast,no-stack-protector,unroll-loops","omit-frame-pointer","inline")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,sse4.1,sse4.2,popcnt,abm,mmx,avx,avx2,fma,tune=native")
#pragma GCC option("arch=native","no-zero-upper") //Enable AVX

#include <bits/stdc++.h>
#define db(x) cout << (x) << '\n';
#define sz(v) ((int)(v).size())
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
const ll mod=(ll)(1e9+7);
const ld eps=(1e-9);
const ll oo=(ll)(1e18);
#define pi acos(-1)
#define MAXN (ll)(5e3+5)

ll dp[MAXN][MAXN];

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n,k,q;
    cin >> n >> k >> q;
    for(int i=0;i<n;i++)
        dp[i][0]=1;
    for(int i=1;i<=k;i++)
        for(int j=0;j<n;j++)
        {
            if(j)
                dp[j][i]=(dp[j][i]+dp[j-1][i-1])%mod;
            if(j+1<n)
                dp[j][i]=(dp[j][i]+dp[j+1][i-1])%mod;
        }

    vector<ll> cant(n);
    for(int i=0;i<n;i++)
        for(int j=0;j<=k;j++)
            cant[i]=(cant[i]+dp[i][j]*dp[i][k-j])%mod;

    vector<ll> a(n);
    for(int i=0;i<n;i++)
        cin >> a[i];
    ll res=0;
    for(int i=0;i<n;i++)
        res=(res+a[i]*cant[i])%mod;

    while(q--)
    {
        ll p,v;
        cin >> p >> v;
        p--;
        res=(res-(a[p]*cant[p])%mod+mod)%mod;
        a[p]=v;
        res=(res+(a[p]*cant[p])%mod+mod)%mod;
        db(res)
    }

    return 0;
}