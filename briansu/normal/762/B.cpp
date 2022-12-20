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

ll n,a,b,c,ans=0,sum=0;
vector<ll> p,u;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b>>c;
    cin>>n;
    REP(i,n)
    {
        ll k;
        string s;
        cin>>k>>s;
        if(s[0]=='U')u.pb(k);
        else p.pb(k);
    }
    sort(u.begin(),u.end());
    sort(p.begin(),p.end());
    int itu=0,itp=0;
    for(itu=0;itu<u.size()&&a>0;a--)
    {
        sum+=u[itu++];
        ans++;
    }
    for(itp=0;itp<p.size()&&b>0;b--)
    {
        sum+=p[itp++];
        ans++;
    }
    for(;c>0&&(itu<u.size()||itp<p.size());c--)
    {
        ans++;
        if(itu<u.size()&&itp<p.size())
        {
            sum+=(u[itu]<p[itp]?u[itu++]:p[itp++]);
        }
        else if(itu<u.size())
        {
            sum+=u[itu++];
        }
        else
        {
            sum+=p[itp++];
        }
        debug(itu,itp);
    }
    cout<<ans<<" "<<sum<<endl;
}