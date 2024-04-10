#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define op(x) ((x&1)?x+1:x-1)
#define odd(x) (x&1)
#define even(x) (!odd(x))
#define lc(x) (x<<1)
#define rc(x) (lc(x)|1)
#define lowbit(x) (x&-x)
#define mp(x,y) make_pair(x,y)
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
using namespace std;
const int MAXN=2e5+10,INF=1e18;
ll T,n,x,a[MAXN],ans;
void solve(){
    cin>>n>>x;
    ll sum;ans=0;
    ll minn=INF,maxn=-INF;
    rep(i,1,n)cin>>a[i],minn=min(minn,a[i]),maxn=max(maxn,a[i]);
    rep(i,2,n)ans+=abs(a[i]-a[i-1]); 
    ll cost1=INF,cost2=INF;
    cost1=min(cost1,abs(a[1]-1));
    cost1=min(cost1,abs(a[n]-1));
    cost2=min(cost2,abs(a[1]-x));
    cost2=min(cost2,abs(a[n]-x));
    rep(i,2,n)cost1=min(cost1,abs(a[i-1]-1)+abs(a[i]-1)-abs(a[i]-a[i-1])),cost2=min(cost2,abs(a[i-1]-x)+abs(a[i]-x)-abs(a[i]-a[i-1]));
    if(minn>1)ans+=cost1;
    if(maxn<x)ans+=cost2;
    cout<<ans<<'\n';
}
int main(){
    cin>>T;
    while(T--)solve();


    return 0;
}