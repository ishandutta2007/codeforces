#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
inline int read(){
	int f=1,r=0;char c=getchar();
	while(!isdigit(c))f^=c=='-',c=getchar();
	while(isdigit(c))r=(r<<1)+(r<<3)+(c&15),c=getchar();
	return f?r:-r;
}
const int N=2e5+7,mod=1e9+7;
inline void inc(int &x,int y){x+=y;if(x>=mod)x-=mod;}
inline int qpow(int a,int b){
	int res=1;
	for(;b;b>>=1,a=1ll*a*a%mod)
		if(b&1)res=1ll*res*a%mod;
	return res;
}
int fac[N],ifac[N];
inline int C(int n,int m){
	if(n<m || m<0)return 0;
	return 1ll*fac[n]*ifac[m]%mod*ifac[n-m]%mod;	
}
inline void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n;i;i--)ifac[i-1]=1ll*ifac[i]*i%mod;	
}
int n,K,sz[N],a[N],fa[N],siz[N];
vector<int>G[N];
void dfs(int x){
	sz[x]=1;
	for(int y:G[x]){
		if(y==fa[x])continue;
		fa[y]=x,dfs(y),sz[x]+=sz[y];
	}
}
int main(){	
#ifndef ONLINE_JUDGE
	freopen("1.in","r",stdin);
	freopen("1.out","w",stdout);
#endif
	n=read(),K=read(),init(n);
	for(int i=1;i<n;i++){
		int x=read(),y=read();
		G[x].push_back(y),G[y].push_back(x);
	}
	dfs(1);
	int ans=0;
	for(int x=1;x<=n;x++){
		int sum=0;
		for(int y:G[x])
			siz[y]=y==fa[x]?n-sz[x]:sz[y],a[y]=C(siz[y],K),inc(sum,a[y]);
		ans=(ans+1ll*n*(C(n,K)+mod-sum))%mod;
		for(int y:G[x])
			ans=(ans+1ll*(n-siz[y])*siz[y]%mod*(C(n-siz[y],K)+\
				mod-(sum+mod-a[y])%mod))%mod;
	}
	printf("%d\n",ans);
	return 0;
}