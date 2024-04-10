#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=314514;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll a[111][111],b[111][111];
struct zb{
	ll x,y;
	int operator<(const zb&b)const{
		return a[x][y]<a[b.x][b.y];
	}
}c[114514];
int main(){
	//IO(A);
	ll T=readll();
	rep(f,1,T){
		ll n=readll(),m=readll(),cnt=0;
		rep(i,1,n)rep(j,1,m)a[i][j]=readll(),b[i][j]=0,c[++cnt]=(zb){i,j};
		std::sort(c+1,c+cnt+1);
		rep(j,1,m)b[c[j].x][j]=a[c[j].x][c[j].y],a[c[j].x][c[j].y]=0;
		rep(i,1,n){
			ll cnt=1;
			rep(j,1,m)if(a[i][j]){while(b[i][cnt])cnt++;b[i][cnt]=a[i][j];}
		}
		rep(i,1,n){rep(j,1,m)printf("%lld ",b[i][j]);puts("");}	
	}
	return 0;
}