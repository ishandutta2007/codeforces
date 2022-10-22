#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i++)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
typedef long long ll;const ll N=1e5+5;typedef ll aN[N];
ll readll(){
	ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}
int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int check(ll max,ll sum,ll n){return max<=(n+1)/2*n&&sum<=n*n-(n/2)*(n/2);}
aN a,c;ll s[2000][2000]; 
int cmp(ll a,ll b){return::a[a]>::a[b];}
void work(ll*a,ll m,ll n){
	printf("%lld\n",n);rep(i,1,m)c[i]=i;std::sort(c+1,c+m+1,cmp);ll x=1,y=0;rep(i,1,n)rep(j,1,n)s[i][j]=0;
	rep(i,1,m)rep(j,1,a[c[i]])y+2>n?x+2<=n?x+=2,y=2-(y&1):y&1?x=2,y=1:x=y=1:y+=2,s[x][y]=c[i];//,printf("%lld,%lld\n",x,y);
	rep(i,1,n){rep(j,1,n)printf("%lld ",s[i][j]);puts("");}
}
int main(){
	ll T=readll();
	while(T --> 0){
		ll m=readll(),k=readll(),max=0;rep(i,1,k)max=std::max(max,a[i]=readll());
		ll l=1,r=m;while(l<=r){ll mid=(l+r)>>1;if(check(max,m,mid))r=mid-1;else l=mid+1;}work(a,k,r+1);
	}
	return 0;
}