#include <iostream>
#include <cstdio>
#define int long long
#define mod 1000000007
using namespace std;
inline int Qpow(register int a,register int p){
	if (p==0)return 1;
	register int t=Qpow(a,p/2);
	t=t*t%mod;
	if (p%2==1)t=t*a%mod;
	return t;
}
inline int inv(register int a){
	return Qpow(a,mod-2);
}
int n,u[405],v[405],first[205],nxt[405],depth[205],fa[205][15],LCA[205][205];
int dp[405][405],ans;
inline int upd(register int x){
	return (x>=mod)?(x-mod):x;
}
inline void dfs(register int now,register int f,register int d){
	fa[now][0]=f;
	for (register int i=1;i<=10;i++)fa[now][i]=fa[fa[now][i-1]][i-1];
	depth[now]=d;
	for (register int i=first[now];i;i=nxt[i])
		if (v[i]!=f)dfs(v[i],now,d+1);
	return;
}
inline int getLCA(register int a,register int b){
	if (depth[a]<depth[b])swap(a,b);
	for (register int i=10;i>=0;i--)
		if (depth[fa[a][i]]>=depth[b])a=fa[a][i];
	if (a==b)return a;
	for (register int i=10;i>=0;i--)
		if (fa[a][i]!=fa[b][i])a=fa[a][i],b=fa[b][i];
	return fa[a][0];
}
signed main(){
	cin>>n;
	for (register int i=1;i<n;i++){
		cin>>u[i]>>v[i];
		nxt[i]=first[u[i]],first[u[i]]=i;
		u[i+n]=v[i],v[i+n]=u[i];
		nxt[i+n]=first[u[i+n]],first[u[i+n]]=i+n;
	}
	for (register int i=1;i<=400;i++)dp[0][i]=1;
	for (register int i=1;i<=400;i++)
		for (register int j=1;j<=400;j++)
			dp[i][j]=inv(2)*(dp[i][j-1]+dp[i-1][j])%mod;
	for (register int i=1;i<=n;i++){
		dfs(i,0,1);
		for (register int j=1;j<=n;j++)
			for (register int k=1;k<=n;k++)
				LCA[j][k]=getLCA(j,k);
		for (register int j=1;j<=n;j++)
			for (register int k=1;k<j;k++)
				ans=upd(ans+dp[depth[j]-depth[LCA[j][k]]][depth[k]-depth[LCA[j][k]]]);
	}
	cout<<ans*inv(n)%mod<<endl;
	return 0;
}