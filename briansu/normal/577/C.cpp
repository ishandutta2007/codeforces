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
vector<ll> ans;
vector<ll> pm;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    for(int i=2;i<=n;i++)
    {
        bool b=1;
        for(int j=0;j<pm.size()&&pm[j]*pm[j]<=i;j++)if(i%pm[j]==0){b=0;break;}
        if(b)pm.pb(i);
    }
    for(int i=0;i<pm.size();i++)
    {
        ll now=pm[i];
        while(now<=n)
        {
            ans.pb(now);
            now*=pm[i];
        }
    }
    cout<<ans.size()<<endl;
    REP(i,ans.size())
    {
        cout<<ans[i]<<" ";
    }
    cout<<endl;
}