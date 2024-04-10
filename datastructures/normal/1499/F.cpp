#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 998244353
#define int long long 
using namespace std;
int n,k,u[10005],v[10005],first[5005],nxt[10005],f[5005][5005],c[5005],d[5005],sumc[5005],sumd[5005],ans;
inline void merge(){
	sumc[0]=c[0],sumd[0]=d[0];
	c[0]=(c[0]*d[0])%mod;
	for (register int i=1;i<=k;i++){
		int val=0;
		sumc[i]=(sumc[i-1]+c[i])%mod;
		sumd[i]=(sumd[i-1]+d[i])%mod;
		val=(d[i]*sumc[min(i,k-i)]+c[i]*sumd[min(i,k-i)])%mod;
		if (i*2<=k)val=((val-c[i]*d[i])%mod+mod)%mod;
		c[i]=val;
	}
	return;
}
inline void dfs(register int now,register int fa){
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
	}
	memset(c,0,sizeof(c));
	c[0]=1;
	for (register int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		d[0]=0;
		for (register int j=0;j<=k;j++)d[0]=(d[0]+f[v[i]][j])%mod; 
		for (register int j=1;j<=k;j++)d[j]=f[v[i]][j-1];
		merge();
	}
	for (register int i=0;i<=k;i++)f[now][i]=c[i];
	return;
}
signed main(){
	cin>>n>>k;
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0);
	for (register int i=0;i<=k;i++)ans=(ans+f[1][i])%mod;
	cout<<ans<<endl;
	return 0;
}