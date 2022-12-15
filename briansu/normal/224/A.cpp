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

int a,b,c;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>c;
    for(int i=1;i<=a;i++)
    {
        if(a%i!=0)continue;
        ll tmp1=a/i;
        if(b%tmp1!=0)continue;
        ll tmp2=b/tmp1;
        if(c%tmp2!=0)continue;
        if(c/tmp2==i)
        {
            cout<<tmp1*4+tmp2*4+i*4<<endl;
            return 0;
        }
    }
}