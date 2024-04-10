#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
const double EPS=(1e-13);
const ll INF=ll(1e18);
const int sINF=int(1e9);
using namespace std;
using namespace __gnu_pbds;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(n,i) memset(n,i,sizeof n)
#ifdef brian
#define debug(...){\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I &&x){cerr<<x<<endl;}
template<typename I,typename ...T> void _DO(I &&x,T &&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif // brian
ll dis[1001];
ll fd(ll i)
{
    return dis[i]=(dis[i]==i?i:fd(dis[i]));
}
void mg(ll a,ll b)
{
    dis[fd(a)]=fd(b);
}
vector<ll> gp[1000];ll gps=0;
ll dp[1001][1001];
ll w[1001],b[1001];

ll it(int n,int nw)
{
    if(nw<0)return -1*INF;
    if(nw==0)return 0;
    if(n<0)return 0;
    if(dp[n][nw]!=-1)return dp[n][nw];
    ll mx=it(n-1,nw),sumw=0,sumb=0;
    REP(i,gp[n].size())
    {
        mx=max(mx,it(n-1,nw-w[gp[n][i]])+b[gp[n][i]]);
        sumw+=w[gp[n][i]];sumb+=b[gp[n][i]];
    }
    mx=max(mx,it(n-1,nw-sumw)+sumb);
    return dp[n][nw]=mx;

}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,m,W;
    cin>>n>>m>>W;
    REP(i,n)cin>>w[i];
    REP(i,n)cin>>b[i];
    REP(i,n)dis[i]=i;
    REP(i,m)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        mg(a,b);
    }
    map<ll,ll> mp;

    REP(i,n)
    {
        if(mp.count(fd(i)))
        {
            gp[mp[fd(i)]].push_back(i);
        }
        else
        {
            mp[fd(i)]=gps;
            gp[gps].push_back(i);
            gps++;
        }
    }
    FILL(dp,-1);
    ll ans=it(gps-1,W);
    cout<<ans<<endl;
    //0

}