#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=998244353;
int n,K,m,N,sz[103];
int g[203][203];
struct mat{
	int a[203][203];
	mat(){
		memset(a,0,sizeof(a));
	}
	mat operator *(const mat &o){
		mat ans;
		for(int i=1;i<=N;i++)for(int j=1;j<=N;j++)
			for(int k=1;k<=N;k++)
				(ans.a[i][j]+=(ll)a[i][k]*o.a[k][j]%M)%=M;
		return ans;
	}
};
mat myp(mat x,int t){
	mat ans;
	for(int i=1;i<=N;i++)ans.a[i][i]=1;
	for(;t;t>>=1,x=x*x)if(t&1)ans=ans*x;
	return ans;
}
int main(){
	scanf("%d%d%d",&n,&m,&K),N=n+n;
	for(int i=1;i<=m;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u][v]=g[v][u]=1;
		sz[u]++,sz[v]++;
	}
	mat ret;
	for(int i=1;i<=n;i++){
		ret.a[i][i+n]=(M-sz[i]+1)%M;
		ret.a[i+n][i]=1;
		for(int j=1;j<=n;j++)if(g[i][j])
			ret.a[i+n][j+n]=1;
	}
	ret=myp(ret,K-1);
	int ans=0;
	for(int i=1;i<=n;i++){
		(ans+=(ll)ret.a[i+n][i]*(M-sz[i])%M)%=M;
		for(int j=1;j<=n;j++)if(g[j][i])
			(ans+=ret.a[i+n][j+n])%=M;
	}
	printf("%d",ans);
}