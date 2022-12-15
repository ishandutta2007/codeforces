#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define X first
#define Y second
#define pb push_back
#ifdef brian
#define  debug(...) do{\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _do(__VA_ARGS__);\
}while(0)
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

ll bk[1005];
ll dp[1005][1005][2];//now len color(0-W 1-B)
ll r,c,x,y;
const ll INF=ll(1e18);
ll cost(ll i,ll k)
{
    //debug(i,k,bk[i],r-bk[i]);
    if(k==0)return bk[i];
    else return r-bk[i];
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    cin>>r>>c>>x>>y;
    FILL(bk,0);
    REP(i,r)
    {
        string s;
        cin>>s;
        stringstream ss(s);
        REP(j,c)
        {
            char tmp;
            ss>>tmp;
            if(tmp=='#')bk[j+1]++;
            assert(tmp=='#'||tmp=='.');
        }
    }
    REP(i,1005)REP(j,1005)REP(k,2)dp[i][j][k]=INF;
    //for(int i=2;i<=c;i++)bk[i]+=bk[i-1];
    FILL(dp[0],0);
    for(int i=1;i<=c;i++)
    {
        REP(k,2)
        {
            for(int j=2;j<=y&&j<=i;j++)
            {
                dp[i][j][k]=dp[i-1][j-1][k]+cost(i,k);
            }
            for(int j=x;j<=y;j++)dp[i][1][k]=min(dp[i][1][k],dp[i-1][j][!k]+cost(i,k));
        }
        REP(j,c)REP(k,2)debug(i,j,k,dp[i][j][k]);
    }
    ll ans=INF;
    for(int i=x;i<=y;i++)
    {
        ans=min({ans,dp[c][i][0],dp[c][i][1]});
    }
    cout<<ans<<endl;
}