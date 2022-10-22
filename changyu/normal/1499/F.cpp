#include<bits/stdc++.h>
typedef long long ll;
const int N=5003,M=998244353;
int n,m,h[N],f[N][N],ans;
std::vector<int>g[N];
void Dfs(int u,int fa){
	int s,t;
	f[u][0]=1;
	for(int v:g[u])
		if(v!=fa){
			Dfs(v,u);
			s=0;for(int j=0;j<=std::min(m,h[v]);j++)s=(s+f[v][j])%M;
			for(int j=std::min(m,std::max(h[u],h[v]+1));~j;j--){
				if(j<=h[u]){
					t=s;
					for(int k=0;k<=h[v]&&k<j&&j+k<m;k++)t=(t+f[v][k])%M;
					f[u][j]=(ll)f[u][j]*t%M;
				}
				if(j&&j-1<=h[v])
					for(int k=0;k<=h[u]&&k<j&&j+k<=m;k++)f[u][j]=(f[u][j]+(ll)f[u][k]*f[v][j-1])%M;
			}
			h[u]=std::max(h[u],h[v]+1);
		}
}
int main(){
	int u,v;
	scanf("%d%d",&n,&m);
	for(int i=1;i<n;i++)scanf("%d%d",&u,&v),g[u].push_back(v),g[v].push_back(u);
	Dfs(1,0);
	for(int i=0;i<=m;i++)ans=(ans+f[1][i])%M;
	printf("%d\n",ans);
	return 0;
}