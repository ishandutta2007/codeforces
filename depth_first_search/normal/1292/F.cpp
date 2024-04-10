#include<bits/stdc++.h>
#define Cn const
#define CI Cn int&
#define N 60
#define X 1000000007
using namespace std;
int n,a[N+5],C[N+5][N+5],c,s[N+5],tt,ans=1;
int vis[N+5];void dfs(int x)
{
	vis[x]=1,s[++c]=a[x];for(int i=1;i<=n;++i) !vis[i]&&(!(a[i]%a[x])||!(a[x]%a[i]))&&(dfs(i),0);
}
int w[N+5],q[N+5],g[1<<N/4],f[N+5][1<<N/4];void Solve()
{
	if(c==1) return;sort(s+1,s+c+1);
	int i,j,k,c_=0,ct=0;for(i=1;i<=c;++i) {j=1;for(j=1;j<=ct&&s[i]%q[j];++j);(j>ct?q[++ct]:s[++c_])=s[i];}c=c_;
	for(i=1;i<=c;++i) {w[i]=0;for(j=1;j<=ct;++j) !(s[i]%q[j])&&(w[i]|=1<<j-1);++g[w[i]];}
	int l=1<<ct;for(i=1;i<=n;++i) for(j=0;j^l;++j) f[i][j]=0;for(j=0;j^l;++j) g[j]=0;
	for(i=1;i<=c;++i) ++f[1][w[i]],++g[w[i]];
	for(i=0;i^ct;++i) for(j=0;j^l;++j) j>>i&1&&(g[j]+=g[j^(1<<i)]);
	for(i=1;i^c;++i) for(j=0;j^l;++j) if(f[i][j])
	{
		f[i+1][j]=(f[i+1][j]+1LL*f[i][j]*(g[j]-i))%X;
		for(k=1;k<=c;++k) w[k]&j&&(w[k]|j)^j&&(f[i+1][w[k]|j]=(f[i+1][w[k]|j]+f[i][j])%X);
	}
	ans=1LL*ans*f[c][l-1]%X*C[tt+c-1][tt]%X,tt+=c-1;
}
int main()
{
	int i,j;for(scanf("%d",&n),i=1;i<=n;++i) scanf("%d",a+i);
	for(C[0][0]=i=1;i<=n;++i) for(C[i][0]=j=1;j<=i;++j) C[i][j]=(C[i-1][j-1]+C[i-1][j])%X;
	for(i=1;i<=n;++i) !vis[i]&&(c=0,dfs(i),Solve(),0);return printf("%d\n",ans),0;
}