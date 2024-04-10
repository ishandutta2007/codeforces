#include<bits/stdc++.h>
#define rep(i,l,r) rfor(ll i=l;i<=r;i++)
#define per(i,l,r) rfor(ll i=l;i>=r;i--)
#define ref(i,l,r) rfor(ll i=l;i<r;i++)
#define rfor(x...) for(register x)
#define IO(x...) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
#define nxt y=(y+k[x]%2520+2520)%2520,x=to[x][y%m[x]]
typedef long long ll;const ll N=1e6+7,inf=0x3f3f3f3f3f3f3f3f,mod=998244353;typedef ll aN[N];
ll to[1111][11],ans[1111][2527],m[1111],k[1111],v[1111];
inline ll readll(){ll x=0,w=1;int c=getchar();for(;c<'0'||c>'9';c-'-'||(w=-w),c=getchar());
	for(;c>='0'&&c<='9';x=x*10+(c^48),c=getchar());return x*w;
}inline int readchar(int l='A',int r='z'){int c=getchar();for(;c<l||c>r;c=getchar());return c;}
int main(){
	ll n=readll();rep(i,1,n)k[i]=readll();rep(i,1,n){m[i]=readll();ref(j,0,m[i])to[i][j]=readll();}
	rep(i,1,n)ref(j,0,2520)if(!ans[i][j]){ll x=i,y=j,s=0;
	while(!ans[x][y])ans[x][y]=-1,nxt;//,printf("%lld %lld\n",x,y);exit(0);
	if(ans[x][y]!=-1)s=ans[x][y];else{
	ll lx=x,ly=y;do s+=!v[x]++,nxt;while(x!=lx||y!=ly);/*printf("==%lld\n",s);*/}//exit(0);
	x=i,y=j;while(!~ans[x][y])v[x]=0,ans[x][y]=s,nxt;}
	ll m=readll(),x,y;rep(i,1,m)x=readll(),y=readll(),printf("%lld\n",ans[x][(y%2520+2520)%2520]);return 0; 
}