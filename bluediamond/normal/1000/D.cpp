#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;

const ll N=1000;
const ll MOD=998244353;

ll n;
ll v[N+5];
ll dp[N+5];

ll fact[N+5];

void build()
{
    fact[0]=1;
    for(ll i=1;i<=N;i++)
        fact[i]=(ll)fact[i-1]*i%MOD;
}

ll expow(ll a,ll b)
{
    ll ans=1;
    while(b)
    {
        if(b%2==1)
            ans=(ll)ans*a%MOD;
        a=(ll)a*a%MOD;
        b/=2;
    }
    return ans;
}

ll comb(ll n,ll k)
{
    ll x=fact[n];
    ll y=(ll)fact[k]*fact[n-k]%MOD;
    y=expow(y,MOD-2);
    ll ans=x*y%MOD;
    return ans;
}

ll ans=0;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    build();
    cin>>n;
    for(ll i=1;i<=n;i++)
        cin>>v[i];
    for(ll st=1;st<=n;st++)
    {
        ll add=v[st];
        if(add<=0)continue;
        ll sum=1;
        for(ll i=1;i<st;i++)
        {
            sum+=dp[i];
            sum%=MOD;
        }
        for(ll i=add;st+i<=n;i++)
        {
            dp[st+i]+=sum*comb(i-1,add-1);
            dp[st+i]%=MOD;
        }
        /**cout<<st<<" - > "<<sum<<"\n";
        for(ll j=1;j<=n;j++)
            cout<<dp[j]<<" ";
        cout<<"\n\n";**/
    }
   /// cout<<"\n\n\n";
    for(ll i=1;i<=n;i++)
    {
    ///    cout<<i<<" : "<<dp[i]<<"\n";
        ans+=dp[i];
        ans%=MOD;
    }
    cout<<ans<<"\n";
    return 0;
}
/**


**/