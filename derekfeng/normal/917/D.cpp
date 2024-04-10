#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=1e9+7;
int myp(int x,int t){
	int ans=1;
	for(;t;t>>=1,x=(ll)x*x%M)if(t&1)ans=(ll)ans*x%M;
	return ans;
}
int n;
vector<int>g[103];
int f[103][103][103][2],sz[103];
int tran[103][103][2];
void dfs(int u,int fa){
	f[u][0][1][0]=1,sz[u]=1;
	for(int i=0;i<g[u].size();i++)if(g[u][i]!=fa){
		int v=g[u][i];dfs(v,u);
		memset(tran,0,sizeof(tran));
		for(int j1=0;j1<=sz[u];j1++)for(int k1=0;k1<=sz[u];k1++)
			for(int s1=0;s1<2;s1++)if(f[u][j1][k1][s1])
				for(int j2=0;j2<=sz[v];j2++)for(int k2=0;k2<=sz[v];k2++)
					for(int s2=0;s2<2;s2++)if(f[v][j2][k2][s2]){
						int a=f[u][j1][k1][s1],b=f[v][j2][k2][s2];
						(tran[j1+j2+1][k1][s1^s2]+=(ll)a*b%M*n*k2%M)%=M;
						(tran[j1+j2+1][k1+k2][s1^s2^1]+=(ll)a*b%M)%=M;
						(tran[j1+j2][k1+k2][s1^s2]+=(ll)a*b%M)%=M;
					}
		sz[u]+=sz[v];
		memcpy(f[u],tran,sizeof(f[u]));
	}
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	int invn=myp(n,M-2);
	for(int i=0;i<n;i++){
		int ans=0;
		for(int j=0;j<=n;j++){
			int mul=(ll)j*invn%M;
			(ans+=(ll)f[1][n-1-i][j][0]*mul%M)%=M;
			(ans+=M-(ll)f[1][n-1-i][j][1]*mul%M)%=M;
		}
		printf("%d ",ans);
	}
}