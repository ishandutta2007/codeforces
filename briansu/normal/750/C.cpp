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

const ll INF=ll(1e18);


ll n;
ll mx=INF,mn=-INF;
ii d[200005];
int main()
{

    cin>>n;
    for(int i=n-1;i>=0;i--)cin>>d[i].X>>d[i].Y;
    if(d[0].Y==1)
        {mx=INF;mn=1900;}
    else
    {mx=1899;mn=-INF;}
    REP(i,n-1)
    {
        ll nmn,nmx;
        if(d[i].Y==1)
        {
            nmx=INF;nmn=1900-d[i+1].X;
        }
        else
        {
            nmx=1899-d[i+1].X;
            nmn=-INF;
        }
        mn-=d[i+1].X;mx-=d[i+1].X;
        if(nmx<mn||nmn>mx)
            {cout<<"Impossible"<<endl;return 0;}
        mn=max(mn,nmn);
        mx=min(mx,nmx);
        debug(i,mx,mn);
    }
    if((d[n-1].Y==1&&mx<1900))
    {
        cout<<"Impossible"<<endl;return 0;
    }
    else if((d[n-1].Y==2&&mx>=1900))
    {
        if(mn<1900)mx=1899;
        else {cout<<"Impossible"<<endl;return 0;}
    }

    REP(i,n)mx+=d[i].X;
    if(mx>=ll(1e12))cout<<"Infinity"<<endl;
    else cout<<mx<<endl;


}