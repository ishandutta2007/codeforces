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

ll n,k;
vector<ll> v[100005];
bool d[100005];

ll dfs(ll f,ll now,ll cts)
{
    if(d[now])cts++;
    else cts=0;
    if(cts>k)return 0;
    bool b=true;
    ll r=0;
    REP(i,v[now].size())
    {
        if(v[now][i]!=f)
        {
            b=0;
            r+=dfs(now,v[now][i],cts);
        }
    }
    return r+b;
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    REP(i,n)cin>>d[i+1];
    REP(i,n-1)
    {
        ll a,b;
        cin>>a>>b;
        v[a].pb(b);
        v[b].pb(a);
    }
    cout<<dfs(-1,1,0)<<endl;
}