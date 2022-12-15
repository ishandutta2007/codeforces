#include<bits/stdc++.h>
using namespace std;
//#include<ext/pb_ds/assoc_container.hpp>
//using namespace __gnu_pbds;
typedef long long ll;
typedef double lf;
//typedef pair<ll,ll> ii;

#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(i,n) memset(i,n,sizeof(i));

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

ll cnt[100005];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,x;
    cin>>n>>x;
    FILL(cnt,0);
    ll d[n];
    REP(i,n)cin>>d[i];
    REP(i,n)cnt[d[i]]++;
    ll ans=0;
    REP(i,n)
    {
        ll tmp=d[i]^x;
        cnt[d[i]]--;
        if(tmp<=100000)
        {
            ans+=cnt[tmp];
            debug(i,d[i],tmp,ans);
        }
    }
    cout<<ans<<endl;



}