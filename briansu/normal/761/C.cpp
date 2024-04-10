#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
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
template<typename t> void _do(t &&x){cerr<<x<<endl;}
template<typename t,typename ...T> void _do(t &&x,T &&...tail){cerr<<x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=55;

ll n,m;
//1,a,*
string d[MAXn];
ll dis[MAXn][3];
ll dp[MAXn][8];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>m;
    REP(i,n)cin>>d[i];
    REP(i,n)dis[i][0]=dis[i][1]=dis[i][2]=INF;
    REP(i,n)
    {
        REP(j,m)
        {
            ll tmpdis=min(ll(j),m-j);
            if(d[i][j]-'0'>=0&&d[i][j]-'0'<=9)dis[i][0]=min(dis[i][0],tmpdis);
            else if(d[i][j]-'a'>=0&&d[i][j]-'a'<=25)dis[i][1]=min(dis[i][1],tmpdis);
            else dis[i][2]=min(dis[i][2],tmpdis);
        }
    }
    REP(i,n+1)REP(j,8)dp[i][j]=INF;
    dp[0][0]=0;
    REP(i,n)
    {
        REP(j,8)dp[i+1][j]=dp[i][j];
        REP(j,7)
        {
            REP(k,3)
            {
                if((j&(1<<k))==0)
                {
                    dp[i+1][j|(1<<k)]=min(dp[i+1][j|(1<<k)],dp[i][j]+dis[i][k]);
                }
            }
        }
    }
    cout<<dp[n][7]<<endl;
}