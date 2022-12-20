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
const ll MAXn=1000005;

ll n,k;
vector<ll> f,b;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>k;
    for(ll i=1;i*i<=n;i++)
    {
        if(n%i==0)
        {
            f.pb(i);
            if(i*i!=n)b.pb(n/i);
        }

    }
    debug(f.size(),b.size(),k);
    if(f.size()>=k)cout<<f[k-1]<<endl;
    else
    {
        k-=f.size();
        debug(k);
        if(b.size()>=k)cout<<b[b.size()-k]<<endl;
        else cout<<-1<<endl;
    }
}