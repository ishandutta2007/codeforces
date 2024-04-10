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
const ll MAXn=200005;

ll d[MAXn];
ll n;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n;
    REP(i,n)cin>>d[i];
    ll cnt=0;
    for(int i=1;i<=n-i+1;i++)
    {
        cnt++;
        if(cnt%2)swap(d[i-1],d[n-i]);
    }
    REP(i,n)cout<<(i==0?"":" ")<<d[i];
    cout<<endl;


}