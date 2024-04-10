#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=314514,inf=0x3f3f3f3f3f3f3f3f;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;char c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(){char c=getchar();for(;c<'A'||c>'z';c=getchar());return c;}
ll r[1111][1111],d[1111][1111],f[13][666][666];
int main(){
	//IO(C);
	ll n=readll(),m=readll(),k=readll();
	if(k%2){
		rep(i,1,n){
			rep(j,1,m){
				printf("-1 ");
			}
			puts("");
		}
		return 0;
	}
	k/=2;
	rep(i,1,n)rep(j,1,m-1)r[i][j]=readll();
	rep(i,1,n-1)rep(j,1,m)d[i][j]=readll();
	rep(i,1,n)rep(j,1,m)f[0][i][j]=0;
	rep(s,1,k)rep(i,1,n)rep(j,1,m)f[s][i][j]=
	std::min(
	std::min(
	i!=1?f[s-1][i-1][j]+d[i-1][j]:inf,
	i!=n?f[s-1][i+1][j]+d[i][j]:inf),
	std::min(
	j!=1?f[s-1][i][j-1]+r[i][j-1]:inf,
	j!=m?f[s-1][i][j+1]+r[i][j]:inf));
	rep(i,1,n){
		rep(j,1,m){
			printf("%lld ",f[k][i][j]*2);
		}
		puts("");
	}
	return 0;
}