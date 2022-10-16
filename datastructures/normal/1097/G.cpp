#include <iostream>
#include <cstdio>
#include <cstring>
#define mod 1000000007
#define int long long
using namespace std;
int n,m,u[200005],v[200005],first[200005],nxt[200005];
int C[205][205];
int sz[100005],f[100005][205],_f[205],c[205],s[205],d[205][205],ans;
void upd(int &x,int y){
	x+=y;
	if (x>=mod)x-=mod;
	return;
}
void dfs(int now,int fa){
	sz[now]=1;
	f[now][0]=1;
	for (int i=first[now];i;i=nxt[i]){
		if (v[i]==fa)continue;
		dfs(v[i],now);
		for (int j=0;j<=sz[v[i]]&&j<=m;j++){
			c[j]=f[v[i]][j];
			if (j>0)upd(c[j],f[v[i]][j-1]);
		}
		memset(_f,0,sizeof(_f));
		for (int j=0;j<=sz[now]&&j<=m;j++)
			for (int k=0;k<=sz[v[i]]&&j+k<=m;k++)
				upd(_f[j+k],f[now][j]*c[k]%mod);
		sz[now]+=sz[v[i]];
		for (int j=0;j<=sz[now]&&j<=m;j++)upd(f[now][j],_f[j]);
		for (int j=0;j<=sz[v[i]]&&j<=m;j++){
			upd(f[now][j],c[j]);
			upd(s[j],mod-c[j]);
		}
	}
	for (int i=0;i<=sz[now]&&i<=m;i++)upd(s[i],f[now][i]);
	return;
}
signed main(){
	cin>>n>>m;
	for (int i=1;i<n;i++){
		scanf("%lld%lld",&u[i],&v[i]);
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (int i=0;i<=m;i++)C[i][0]=1;
	for (int i=1;i<=m;i++)	
		for (int j=1;j<=i;j++)
			C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
	dfs(1,0);
	d[0][0]=1;
	for (int i=1;i<=m;i++)
		for (int j=1;j<=m;j++)
			for (int k=1;k<=j;k++)
				upd(d[i][j],C[j][k]*d[i-1][j-k]%mod);
	for (int i=1;i<=m;i++)upd(ans,s[i]*d[i][m]%mod);
	cout<<ans<<endl;
	return 0;
}