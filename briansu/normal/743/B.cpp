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


ll it(ll n,ll k)
{

    ll tmp=1;
    REP(i,n+1)tmp*=2;
    tmp--;
    debug(n,k,tmp);
    if(k*2==tmp+1)return n+1;
    else if(k*2<tmp+1)return it(n-1,k);
    else return it(n-1,k-tmp/2-1);
}
ll n,k;
int main()
{
    cin>>n>>k;
    n--;
    cout<<it(n,k)<<endl;
}