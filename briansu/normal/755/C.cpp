#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

const ll INF=ll(1e12);

vector<ll> g;
ll fd(ll a)
{
    return g[a]=(g[a]==a?a:fd(g[a]));
}
void uni(ll a,ll b)
{
    g[fd(a)]=fd(b);
}
int main()
{
    ll n;
    cin>>n;
    g.resize(n);
    REP(i,n)g[i]=i;

    REP(i,n)
    {
        ll k;
        cin>>k;
        uni(i,k-1);
    }
    ll ans=0;
    REP(i,n)if(g[i]==i)ans++;
    cout<<ans<<endl;

}