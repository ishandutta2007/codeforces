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
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=1e5+5,MAXlg=20;
const ll MOD = 1000000007;

ll n;
vector<ii> v[MAXn];
ll dp[MAXn],sz[MAXn];
bool chk(ll k)
{
    while(k>0)
    {
        ll tmp=k%10;
        if(tmp!=4&&tmp!=7)return 0;
        k/=10;
    }
    return 1;
}
void dfs(ll now,ll f)
{
    dp[now]=0;sz[now]=1;
    for(ii k:v[now])
    {
        if(k.X==f)continue;
        dfs(k.X,now);
        sz[now]+=sz[k.X];
        dp[now]+=(k.Y?sz[k.X]:dp[k.X]);
    }
}
ll ans=0;
void dpdfs(ll now,ll f,ll t)
{
    t+=dp[now];
    ans+=t*(t-1);
    for(ii k:v[now])
    {
        if(k.X==f)continue;
        dpdfs(k.X,now,(k.Y?sz[0]-sz[k.X]:t-dp[k.X]));
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n-1)
    {
        ll a,b,c;
        cin>>a>>b>>c;
        a--;b--;
        c=chk(c);
        v[a].pb(ii(b,c));
        v[b].pb(ii(a,c));
    }
    dfs(0,-1);
    dpdfs(0,-1,0);
    cout<<ans<<endl;
}