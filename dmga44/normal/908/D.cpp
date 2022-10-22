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
typedef pair<string,ll> psi;
typedef pair<ll,string> pls;
typedef pair<string,string> pss;
typedef pair<ll,pii> pip;
typedef pair<pii,pii> ppp;
typedef complex<ld> point;
#define mod (ll)(1e9+7)
#define MAXN 1005

ll cnt;
ll dp[MAXN][MAXN];

ll qp(ll b,ll e)
{
    if(!e)
        return 1;
    ll x=qp(b,e/2);
    x=(x*x)%mod;
    if(e&1)
        x=(x*b)%mod;
    return x;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll k,pa,pb;
    cin >> k >> pa >> pb;
    cnt=qp(pa+pb,mod-2);
    ll base=(pa*qp(pb,mod-2))%mod;
    dp[1][0]=1;
    pa=(pa*cnt)%mod;
    pb=(pb*cnt)%mod;
    for(int i=1;i<k;i++)
        for(int j=1;j<=i;j++)
        {
            dp[j+1][i-j]=(dp[j+1][i-j]+dp[j][i-j]*pa)%mod;
            dp[j][i]=(dp[j][i]+dp[j][i-j]*pb)%mod;
        }

    ll res=0;
    for(int i=0;i<MAXN;i++)
        for(int j=0;j<MAXN;j++)
            if(i+j>=k)
                res=(res+dp[i][j]*(base+i+j))%mod;
    db(res)

    return 0;
}