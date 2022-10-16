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
const ll MAXN=3e5+10,INF=1e18;
ll n,m,S;
ll sum[MAXN],cur;
array<ll,2>a[MAXN];
void exgcd(ll a,ll b,ll& x,ll& y){
    if(!b){
        x=1;y=0;
        return;
    }
    exgcd(b,a%b,x,y);
    ll x0=x,y0=y;
    x=y0;y=x0-(a/b)*y0;
}
void tomax(ll& x,ll y){x=max(x,y);}
int main(){
    ios::sync_with_stdio(false);
    cin>>n;
    rep(i,1,n)cin>>a[i][0]>>a[i][1],S+=a[i][1],a[i][0]-=a[i][1];
    sort(a+1,a+1+n);reverse(a+1,a+1+n);
    rep(i,1,n)sum[i]=sum[i-1]+a[i][0];
    rep(i,1,n)if(a[i][0]>0)cur=i;
    cin>>m;
    rep(i,1,m){
        ll a,b;cin>>a>>b;
        ll lim=cur/a;
        ll g=__gcd(a,b);
        if(n%g){
            cout<<"-1\n";
            continue;
        }
        ll x,y;exgcd(a,b,x,y);
        x*=n/g;y*=n/g;
        ll addx=b/g,addy=a/g;
        ll ans=-INF;
        //
        if(x>=lim){
            ll cnt=(x-lim+addx-1)/addx;
            x-=addx*cnt;y+=addy*cnt;
        }else{
            ll cnt=(lim-x)/addx;
            x+=addx*cnt;y-=addy*cnt;
        }
        if(y<0){
            ll cnt=(-y+addy-1)/addy;
            x-=addx*cnt;y+=addy*cnt;
        }
        if(x>=0 && y>=0)tomax(ans,S+sum[a*x]);
        x+=addx;y-=addy;
        if(x>=0 && y>=0)tomax(ans,S+sum[a*x]);
        //
        if(ans==-INF)cout<<"-1\n";
        else cout<<ans<<"\n";
    }
    return 0;
}