#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int mypow(int x,int t){
	int ans=1,res=x;
	while(t){
		if(t&1)ans=(ll)ans*res%M;
		res=(ll)res*res%M,t>>=1;
	}
	return ans;
}
int n,inv[203];
void init(){
	inv[0]=1;
	for(int i=1;i<=n;i++)inv[i]=mypow(i,M-2);
}
vector<int>g[203],F[203];
int lca[203][203],dep[203];
void dfs(int x,int par){
	F[x].clear(),F[x].push_back(x);
	for(auto y:g[x])if(y!=par){
		dep[y]=dep[x]+1,dfs(y,x);
		for(auto z:F[y])for(auto w:F[x])
			lca[z][w]=lca[w][z]=x;
		for(auto z:F[y])F[x].push_back(z);
	}
}
int f[203][203];
int main(){
	scanf("%d",&n);
	init();
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);  
	}
	int sum=0,inv2=mypow(2,M-2);
	for(int i=1;i<=n;i++)f[i][0]=1;
	for(int i=1;i<=n;i++)for(int j=1;j<=n;j++)f[i][j]=(ll)inv2*(f[i][j-1]+f[i-1][j])%M;
	for(int i=1;i<=n;i++){
		dep[i]=0,dfs(i,0);
		for(int j=1;j<=n;j++)for(int k=j+1;k<=n;k++)
			sum=((ll)f[dep[j]-dep[lca[j][k]]][dep[k]-dep[lca[j][k]]]+sum)%M;
	}
	printf("%d",(ll)sum*mypow(n,M-2)%M);
}