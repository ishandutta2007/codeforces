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
ll a[1111][1111];
int main(){
	//IO(C);
	ll n=readll();
	rep(i,1,n)a[i][i]=readll();
	rep(i,1,n){
		ll p=0;
		rep(j,i,n){
			if(a[j][j-i+1]==i)p=1;
			else a[j+!p][j-i+1-p]=a[j][j-i+1];
		}
	}
	rep(i,1,n){
		rep(j,1,i)printf("%lld ",a[i][j]);
		puts("");
	}
	return 0;
}