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

ll n,m,h,ans=0;
ll d[18],c[18][18],dp[18][(1<<19)];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m>>h;
    FILL(c,0);FILL(dp,0);
    REP(i,n)cin>>d[i];
    REP(i,h)
    {
        ll a,b,x;
        cin>>a>>b>>x;
        a--;b--;
        c[a][b]=x;
    }
    REP(i,(1<<n))
    {
        REP(j,n)
        {
            ll th=(1<<j);
            if((th&i)==0)continue;
            ll lt=i&~th,cnt=1;
            dp[j][i]=d[j];
            REP(k,n)
            {
                if(((1<<k)&lt)==0)continue;
                cnt++;
                dp[j][i]=max(dp[j][i],dp[k][lt]+c[k][j]+d[j]);
            }
            if(cnt==m)ans=max(ans,dp[j][i]);
        }
    }
    cout<<ans<<endl;
}