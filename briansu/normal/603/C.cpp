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
template<typename t> void _do(t &&_x){cerr<<_x<<endl;}
template<typename t,typename ...T> void _do(t &&_x,T &&...tail){cerr<<_x<<", ";_do(tail...);}
#else
#define debug(...)
#endif // brian

const ll INF=ll(1e15);
const ll MAXn=100005;
const ll MOD = 1000000007;
ll sg(ll a,ll k)
{
    if(a==0)return 0;
    if(k==0)
    {
        if(a<=2)return a;
        else return !(a%2);
    }
    else
    {
        if(a%2==1&&a<4)return 1;
        else if(a%2==1)return 0;
        else
        {
            ll c=sg(a/2,k);
            ll d=sg(a-1,k);
            if(min(d,c)==0&&max(d,c)==1)return 2;
            else if(min(c,d)==0)return 1;
            else return 0;
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,k;
    ll ans=0;
    cin>>n>>k;
    k%=2;
    REP(i,n)
    {
        ll tmp;
        cin>>tmp;
        ans^=sg(tmp,k);
    }
    if(ans==0)cout<<"Nicky"<<endl;
    else cout<<"Kevin"<<endl;
}