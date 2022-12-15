#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define SZ(A) ((int)A.size())
#define ALL(A) A.begin(),A.end()
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
const ll MAXn=1e6+5,MAXlg=20;
const ll MOD = 1000000007;

ll n;
vector<ll> v[MAXn];
ll d[MAXn];
ll rt;
ll sum=0;
ll tt[MAXn];
ll ans=-1;
void dfs(ll now)
{
    bool b=(ans==-1);
    tt[now]=d[now];
    for(int k:v[now])
    {
        dfs(k);
        tt[now]+=tt[k];
    }
    if(b&&ans!=-1&&now!=rt&&tt[now]==2*sum)
    {
        cout<<ans+1<<" "<<now+1<<endl;
        exit(0);
    }
    if(!b&&tt[now]==sum&&now!=rt)
    {
        cout<<ans+1<<" "<<now+1<<endl;
        exit(0);
    }
    if(tt[now]==sum&&now!=rt)ans=now;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)
    {
        ll a,b;
        cin>>a>>b;
        d[i]=b;
        sum+=b;
        a--;
        if(a==-1)rt=i;
        else v[a].pb(i);
    }
    if(sum%3!=0){cout<<-1<<endl;return 0;}
    sum/=3;
    debug(sum);
    dfs(rt);
    cout<<-1<<endl;

}