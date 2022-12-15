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
const ll MAXn=100005;

vector<ll> v[MAXn];
ll n;
ll d[MAXn],c[MAXn];
ll ans=-1;
void dfs(ll now,ll f)
{
    c[now]=d[now];
    for(int k:v[now])
    {
        if(k==f)continue;
        dfs(k,now);
        c[now]=(c[now]==c[k]?c[now]:-1);
    }
}
void dfs2(ll now,ll f,ll cl)
{
    ll tmp=-1,tmp2=-1,cnt=0;
    for(int k:v[now])
    {
        if(k==f)continue;
        if(d[k]!=d[now])
        {
            if(tmp2==-1)tmp2=k;
            cnt++;
        }
        if(c[k]==-1)
        {
            if(tmp==-1)tmp=k;
            else return;
        }
    }
    if(tmp==-1)ans=now;
    else if((tmp2==-1||tmp2==tmp)&&d[now]==cl&&cnt<=1)dfs2(tmp,now,cl);
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
        v[b].pb(a);
    }
    REP(i,n)
    {
        cin>>d[i];
        d[i]--;
    }
    dfs(0,-1);
    dfs2(0,-1,d[0]);
    if(ans!=-1)
    {
        cout<<"YES"<<endl;
        cout<<ans+1<<endl;
    }
    else cout<<"NO"<<endl;
}