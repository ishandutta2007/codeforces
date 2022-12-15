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

map<ii,ll> pt;
map<ll,ll> x,y;
ll n,ans=0;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)
    {
        ll a,b;
        cin>>a>>b;
        if(!x.count(a))x[a]=0;
        if(!y.count(b))y[b]=0;
        if(!pt.count(ii(a,b)))pt[ii(a,b)]=0;
        ans+=x[a]+y[b]-pt[ii(a,b)];
        x[a]++;
        y[b]++;
        pt[ii(a,b)]++;
    }
    cout<<ans<<endl;

}