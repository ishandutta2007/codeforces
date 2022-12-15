#include<bits/stdc++.h>
using namespace std;
#include<ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;

#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));
#define A first
#define B second
#define pb push_back

const ll INF=ll(1e18);

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

ll ans[200005];vector<ll> v[200005];
void dfs(ll now,ll dt)
{
    ans[now]=dt;
    debug(now,dt);
    REP(i,v[now].size())
    {
        if(ans[v[now][i]]==-1)dfs(v[now][i],!dt);
    }

}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n;
    cin>>n;
    ii d[n];
    REP(i,n)
    {
        cin>>d[i].A>>d[i].B;
        d[i].A--;d[i].B--;
        v[d[i].A].pb(d[i].B);
        v[d[i].B].pb(d[i].A);
        v[2*i].pb(2*i+1);
        v[2*i+1].pb(2*i);
    }
    FILL(ans,-1);
    REP(i,2*n)
    {
        if(ans[i]==-1)dfs(i,0);
    }
    REP(i,n)
    {
        cout<<(ans[d[i].A]+1)<<" "<<(ans[d[i].B]+1)<<endl;
    }

}