#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef double lf;
typedef pair<int,int> ii;
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

const ll INF=ll(1e12);

ll r,c,k,x,y;
ll ans[3]={0};
ll get(ll cnt)
{
    return (k-cnt>=0?1:0)+max(ll(0),k-cnt)/((r*2-2)*c);
}
int main()
{
    cin>>r>>c>>k>>x>>y;
    ll rows=k/c+(k%c>0?1:0);
    ll num=(x-1)*c+y;
    if(r==1)
    {
        ans[0]=rows;
        ans[1]=rows-(k%c>0?1:0);
        ans[2]=k/c+(y!=c&&k%c>=y?1:0);
    }
    else if(r==2)
    {
        ans[0]=rows/2+rows%2;
        ans[1]=k/c/2;
        ans[2]=(k-num>=0?1:0)+max(ll(0),k-num)/(r*c);
    }
    else
    {
        //cout<<rows<<endl;
        ans[0]=max(ll(1),max(get(c+1)+get((r*2-3)*c+1),get((r-2)*c+1)+get(r*c+1)));
        ans[1]=get(r*c);
        ans[2]=get(num);
        if(x!=1&&x!=r)ans[2]+=get(r*c+(r-x-1)*c+y);
    }
    cout<<ans[0]<<" "<<ans[1]<<" "<<ans[2]<<endl;

}