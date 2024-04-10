#include <iostream>
#include <cstdio>
#define int long long
using namespace std;
int n,mod;
int u[5005],v[5005],first[5005],nxt[5005];
int f[2005][2005],sum[2005][2005],C[2005][2005],h[2005];
int d[2005],tot;
int val[2005],_val[15][2005];
void calc(int l,int r,int w,int x){
	if (l>r)return;
	if (l==r){
		int s=0;
		for (int i=1;i<=n;i++){
			f[x][i]=(f[x][i]+f[d[l]][i]*s)%mod;
			s=(s+val[i])%mod;
		}
		return;
	}
	int mid=(l+r)/2;
	for (int i=1;i<=n;i++)_val[w][i]=val[i];
	for (int i=l;i<=mid;i++)
		for (int j=1;j<=n;j++)
			val[j]=val[j]*sum[d[i]][j]%mod;
	calc(mid+1,r,w+1,x);
	for (int i=1;i<=n;i++)val[i]=_val[w][i];
	for (int i=mid+1;i<=r;i++)
		for (int j=1;j<=n;j++)
			val[j]=val[j]*sum[d[i]][j]%mod;
	calc(l,mid,w+1,x);
	for (int i=1;i<=n;i++)val[i]=_val[w][i];
	return;
}
void dfs(int now,int fa){
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
	}
	tot=0;
	for (int i=first[now];i;i=nxt[i])
		if (v[i]!=fa)d[++tot]=v[i];
	for (int i=1;i<=n;i++){
		f[now][i]=1;
		for (int j=1;j<=tot;j++)f[now][i]=f[now][i]*sum[d[j]][i]%mod;
	}
	for (int i=1;i<=n;i++)val[i]=1;
	calc(1,tot,0,now);
	for (int i=1;i<=n;i++)sum[now][i]=(sum[now][i-1]+f[now][i])%mod;
	for (int i=2;i<=n;i++){
		h[i]=1;
		for (int j=1;j<=tot;j++)h[i]=h[i]*sum[d[j]][i-1]%mod;
	}
	return;
}
signed main(){
	cin>>n>>mod;
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	dfs(1,0);
	for (int i=0;i<=n;i++)C[i][0]=1;
	for (int i=1;i<=n;i++)
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
	for (int i=2;i<=n;i++){
		for (int j=1;j<i;j++)
			h[i]=(h[i]+mod-h[j]*C[i-1][j-1]%mod)%mod;
		printf("%d ",h[i]);
	}
	printf("\n");
	return 0;
}