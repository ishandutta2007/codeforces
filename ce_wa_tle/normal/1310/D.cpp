#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef int ll;const ll N=1e5+5,inf=1e9;typedef ll aN[N];ll a[111][111],col[111],f[17][111];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
	ll n=readll(),k=readll(),ans=inf;rep(i,1,n)rep(j,1,n)a[i][j]=readll();
	rep(T,1,10240){
		rep(i,1,n)col[i]=std::min(1,rand()/(RAND_MAX/2));rep(j,0,k)rep(i,1,n)f[j][i]=inf;f[0][1]=0;
		rep(l,1,k)rep(i,1,n)rep(j,1,n)if(col[i]!=col[j])f[l][i]=std::min(f[l][i],f[l-1][j]+a[j][i]);
//		rep(l,1,k)rep(i,1,n)printf("f[%lld][%lld]=%lld\n",l,i,f[l][i]);
		ans=std::min(ans,f[k][1]);
	}printf("%d\n",ans);return 0;
}