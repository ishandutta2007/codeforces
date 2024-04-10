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

stringstream ss;

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    ll n,k,a,b;
    cin>>n>>k>>a>>b;
    if(a==0||b==0)
    {
        if(k<n){cout<<"NO\n";return 0;};
        if(a)REP(i,n)cout<<'G';
        else REP(i,n)cout<<'B';
        cout<<endl;
        return 0;
    }
    ll now=(a>b),tmp=0;
    for(int i=0;i<n;i++)
    {
        if(tmp==0)
        {
            now=!now;
            if(now)tmp=min(k,b);
            else tmp=min(a,k);
            debug(i,now,a,b);
        }
        else if((b>a)^now)
        {
            now=(b>a);
            if(now)tmp=min(k,b);
            else tmp=min(a,k);
            debug(i,now,a,b);
        }
        if(now&&b==0){cout<<"NO\n";return 0;}
        else if(!now&&a==0){cout<<"NO\n";return 0;}
        if(now)ss<<'B';
        else ss<<'G';
        tmp--;
        if(now)b--;
        else a--;
    }
    string s;
    ss>>s;
    cout<<s<<endl;

}