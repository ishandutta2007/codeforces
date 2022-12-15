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
ll n;
vector<ll> v[200005];
ll sz[200005],d[200005],sum[200005],mx[200005],sec[200005];
ll szdfs(ll f,ll now)
{
    vector<ll> cs;
    sz[now]=1;sum[now]=d[now];mx[now]=-1*INF;sec[now]=-1*INF;
    REP(i,v[now].size())
    {
        if(v[now][i]!=f){
            sz[now]+=szdfs(now,v[now][i]);
            sum[now]+=sum[v[now][i]];
            cs.pb(max(mx[v[now][i]],sum[v[now][i]]));

        }
    }
    if(cs.size()>0)
    {
        nth_element(cs.begin(),cs.begin(),cs.end(),greater<ll>());
        mx[now]=cs[0];
        if(cs.size()>1)
        {
            nth_element(cs.begin(),cs.begin()+1,cs.end(),greater<ll>());
            sec[now]=cs[1];
        }
    }
    debug(now,mx[now],sec[now],sum[now],cs.size());
    return sz[now];
}
ll dfs(ll f,ll now)
{
    if(sz[now]==1)return -1*INF;
    if((now==1&&v[now].size()==1)||(now!=1&&v[now].size()==2))
    {
        if(v[now][0]!=f)return dfs(now,v[now][0]);
        else return dfs(now,v[now][1]);
    }
    ll ans=mx[now]+sec[now];
    REP(i,v[now].size())
    {
        if(v[now][i]!=f)
        {
            ans=max(ans,dfs(now,v[now][i]));
        }
    }

    return ans;
}
int main()
{
    cin>>n;
    REP(i,n)cin>>d[i+1];
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    szdfs(-1,1);
    ll ans=dfs(-1,1);
    if(ans==-1*INF)cout<<"Impossible"<<endl;
    else cout<<ans<<endl;
}