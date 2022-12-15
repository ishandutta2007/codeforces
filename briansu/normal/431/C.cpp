#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define A first
#define B second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&x){cerr<<x<<endl;}
template<typename t,typename ...T> void _do(t &&x,T &&...tail){cerr<<x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian
const ll INF=ll(1e18);

const ll MOD=ll(1e9)+7;
ll n,k,d;
ll dp[101][2];

ll it(ll now,bool big)
{
    ll ans=0;
    if(big&&now<d)return 0;
    if(now==0)return 1;
    if(dp[now][big]!=-1)return dp[now][big];
    debug(now,big);
    for(ll i=1;i<=k&&i<=now;i++)
    {
        ans=(ans+it(now-i,(i>=d?0:big)))%MOD;
    }
    debug(now,big,ans);
    return dp[now][big]=ans;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k>>d;
    FILL(dp,-1);
    cout<<it(n,1)<<endl;
}