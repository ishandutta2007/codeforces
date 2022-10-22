#include<bits/stdc++.h>
typedef long long ll;
const int N=1e5+3,K=9,D=512,M=998244353;
inline int Pow(int a,int m){int s=1;for(;m;m>>=1)m&1?s=(ll)s*a%M:0,a=(ll)a*a%M;return s;}
std::vector<int>g[N];
int n,m,vis[N],sg[N],b[D],e[D][D+1],t[D];
void Dfs(int u){
	int v;
	vis[u]=1;
	for(int i=0;i<g[u].size();i++)if(!vis[v=g[u][i]])Dfs(v);
	for(int i=0;i<g[u].size();i++)++b[sg[g[u][i]]];
	for(;b[sg[u]];sg[u]++);
	for(int i=0;i<g[u].size();i++)--b[sg[g[u][i]]];
}
int main(){
	int tmp,u,v;
	scanf("%d%d",&n,&m);
	for(;m--;)scanf("%d%d",&u,&v),g[u].push_back(v);
	for(u=1;u<=n;u++)if(!vis[u])Dfs(u);
	for(u=1;u<=n;u++)++b[sg[u]];
	tmp=Pow(n+1,M-2);
	for(int i=0;i<D;i++)b[i]=(ll)b[i]*tmp%M;
	for(int i=0;i<D;i++){
	  for(int j=0;j<D;j++)e[i][j]=(M-b[i^j])%M;
	  e[i][i]=(e[i][i]+1)%M;
	  e[i][D]=i?0:tmp;
	  t[i]=i;
	}
	for(int i=0;i<D;i++){
	  for(int j=i;j<D;j++)if(e[t[j]][D-i-1]){
		std::swap(t[i],t[j]);
		break;
	  }
	  for(int j=i+1;j<D;j++){
	    tmp=(ll)Pow(e[t[i]][D-i-1],M-2)*e[t[j]][D-i-1]%M;
		for(int k=0;k<D-i;k++)e[t[j]][k]=(e[t[j]][k]-(ll)e[t[i]][k]*tmp)%M;
		e[t[j]][D]=(e[t[j]][D]-(ll)e[t[i]][D]*tmp)%M;
	  }
	}
	v=(e[t[D-1]][0]+M)%M;
	u=(e[t[D-1]][D]+M)%M;
	printf("%lld\n",(1-(ll)u*Pow(v,M-2)%M+M)%M);
	return 0;
}