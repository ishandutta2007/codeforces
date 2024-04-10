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
#define MAXN (ll)(5e2+5)

ll dp[MAXN][MAXN];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    vector<ll> xs(n);
    for(int i=0;i<n;i++)
    {
        char c;
        cin >> c;
        if(c=='-')
            xs[i]=-1;
        if(c=='+')
        {
            int x;
            cin >> x;
            xs[i]=x;
        }
    }

    vector<ll> p2(n);

    p2[0]=1;
    ll mul=1;
    for(int i=0;i<n-1;i++)
    {
        p2[i+1]=(2*p2[i])%mod;
        mul=(mul+mul)%mod;
    }

    ll ans=0;
    for(int i=0;i<n;i++)
    {
        if(xs[i]<0)
            continue;
        ans=(ans+xs[i]*mul)%mod;
        for(int j=0;j<=n;j++)
            for(int k=0;k<=n;k++)
                dp[j][k]=0;
        dp[0][0]=1;
        for(int j=0;j<n;j++)
        {
            if(j<i)
            {
                if(xs[j]>0)
                {
                    if(xs[j]>xs[i])
                    {
                        for(int k=0;k<=n;k++)
                            dp[j+1][k]=(2*dp[j][k])%mod;
                    }
                    else
                    {
                        for(int k=0;k<=n;k++)
                        {
                            dp[j+1][k]=(dp[j+1][k]+dp[j][k])%mod;
                            dp[j+1][k+1]=(dp[j+1][k+1]+dp[j][k])%mod;
                        }
                    }
                }
                else
                {
                    for(int k=1;k<=n;k++)
                    {
                        dp[j+1][k]=(dp[j+1][k]+dp[j][k])%mod;
                        dp[j+1][k-1]=(dp[j+1][k-1]+dp[j][k])%mod;
                    }
                    dp[j+1][0]=(dp[j+1][0]+2*dp[j][0])%mod;
                }
            }
            if(j==i)
            {
                for(int k=0;k<=n;k++)
                    dp[j+1][k]=dp[j][k]%mod;
            }
            if(j>i)
            {
                if(xs[j]>0)
                {
                    if(xs[j]>=xs[i])
                    {
                        for(int k=0;k<=n;k++)
                            dp[j+1][k]=(2*dp[j][k])%mod;
                    }
                    else
                    {
                        for(int k=0;k<=n;k++)
                        {
                            dp[j+1][k]=(dp[j+1][k]+dp[j][k])%mod;
                            dp[j+1][k+1]=(dp[j+1][k+1]+dp[j][k])%mod;
                        }
                    }
                }
                else
                {
                    for(int k=1;k<=n;k++)
                    {
                        dp[j+1][k]=(dp[j+1][k]+dp[j][k])%mod;
                        dp[j+1][k-1]=(dp[j+1][k-1]+dp[j][k])%mod;
                    }
                    dp[j+1][0]=(dp[j+1][0]+dp[j][0])%mod;
                    ll cant=(dp[j][0]*p2[n-1-j])%mod;
                    ans=(ans-((xs[i]*cant)%mod)+mod)%mod;
                }
            }
        }
    }
    db(ans)

    return 0;
}