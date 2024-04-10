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
const ll MAXn=55;

ll n,l;
ll d[MAXn][2];
int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    cin>>n>>l;
    REP(i,n)cin>>d[i][0];
    ll tmp=d[n-1][0];
    for(int i=n-1;i>0;i--)d[i][0]-=d[i-1][0];
    d[0][0]+=l-tmp;
    REP(i,n)cin>>d[i][1];
    tmp=d[n-1][1];
    for(int i=n-1;i>0;i--)d[i][1]-=d[i-1][1];
    d[0][1]+=l-tmp;
    bool ans=0;
    REP(k,n)
    {
        bool b=1;
        REP(i,n)
        {
            if(d[i][0]!=d[(i+k)%n][1])b=0;
            //debug(d[i][0],d[i][1],i);
        }
        ans=ans|b;
    }

    if(ans)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
}