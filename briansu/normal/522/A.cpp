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
const ll MAXn=205;
ll n;
map<string,int> mp;
ll it=-1;
ll dp[MAXn];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    //cout<<(int)'A'<<" "<<(int)'a'<<endl;
    cin>>n;
    ll ans=0;
    FILL(dp,0);
    REP(i,n)
    {
        string a,b,c;
        cin>>a>>c>>b;
        REP(j,a.length())if(a[j]>='a')a[j]-=('a'-'A');
        REP(j,b.length())if(b[j]>='a')b[j]-=('a'-'A');
        debug(a,b);
        if(b=="POLYCARP")
        {
            if(!mp.count(a))mp[a]=++it;
            dp[mp[a]]=max(dp[mp[a]],(ll)2);
            ans=max(ans,dp[mp[a]]);
        }
        else
        {
            if(!mp.count(a))mp[a]=++it;
            if(!mp.count(b))mp[b]=++it;
            dp[mp[a]]=max(dp[mp[a]],dp[mp[b]]+1);
            ans=max(ans,dp[mp[a]]);
        }
        debug(ans,i);
    }
    cout<<ans<<endl;

}