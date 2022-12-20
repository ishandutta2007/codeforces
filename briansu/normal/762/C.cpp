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
const ll MAXn=100005;

string a,b;
ll dp[MAXn][2],it;
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>a>>b;
    it=-1;
    for(int i=0;i<a.length();i++)
    {
        if(it+1<b.length()&&a[i]==b[it+1])it++;
        dp[i][0]=it;
        debug(dp[i][0],i);
    }
    it=b.length();
    for(int i=a.length()-1;i>=0;i--)
    {
        if(it-1>=0&&a[i]==b[it-1])it--;
        dp[i][1]=it;
        debug(dp[i][1],i);
    }
    ll l=-1,r=dp[0][1];
    for(int i=0;i<a.length()-1;i++)
    {
        if(dp[i+1][1]-dp[i][0]<r-l)
        {
            r=dp[i+1][1];
            l=dp[i][0];
        }
    }
    if(b.length()-dp[a.length()-1][0]<r-l)
    {
        r=b.length();
        l=dp[a.length()-1][0];
    }
    debug(l,r);
    if(l==-1&&r==b.length())cout<<"-";
    else
    {
        for(int i=0;i<=l;i++)cout<<b[i];
        for(int j=max(l+1,r);j<b.length();j++)cout<<b[j];
    }
    cout<<endl;
}