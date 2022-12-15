#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;

typedef long long ll;
typedef double lf;
typedef pair<ll,ll> ii;
const double EPS=(1e-13);
const ll INF=ll(1e18);
const int sINF=int(1e9);
using namespace std;
using namespace __gnu_pbds;
#define REP(i,n) for(int i=0;i<n;i++)
#define FILL(n,i) memset(n,i,sizeof n)
#ifdef brian
#define debug(...){\
    fprintf(stderr,"%s - %d : (%s) = ",__PRETTY_FUNCTION__,__LINE__,#__VA_ARGS__);\
    _DO(__VA_ARGS__);\
}while(0)
template<typename I>void _DO(I &&x){cerr<<x<<endl;}
template<typename I,typename ...T> void _DO(I &&x,T &&...tail){cerr<<x<<", ";_DO(tail...);}
#else
#define debug(...)
#endif // brian


int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);

    ll n;
    cin>>n;
    if(n==0)cout<<1<<endl;
    else if(n%4==0)cout<<6<<endl;
    else if(n%4==1)cout<<8<<endl;
    else if(n%4==2)cout<<4<<endl;
    else cout<<2<<endl;
}