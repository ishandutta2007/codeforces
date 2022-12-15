#include<bits/stdc++.h>
using namespace std;

const int maxN=500005; 
int N;
int fa[maxN];
int find(int x){return (fa[x]==x?x:fa[x]=find(fa[x]));}
vector<int> G[2][maxN];
int f[2][maxN];
void dfs(int k,int x){
	for(auto v:G[k][x]) if(v!=f[k][x])
		f[k][v]=x,dfs(k,v);
}
void Solve(int x){
	for(auto v:G[0][x]) if(v!=f[0][x]){
		Solve(v);
		if(x!=f[1][v]&&v!=f[1][x]) printf("%d %d %d %d\n",v,x,find(v),f[1][find(v)]);
	}
}

int main(){
	scanf("%d",&N);
	for(int i=1;i<N;i++){int u,v;scanf("%d%d",&u,&v);G[0][u].push_back(v);G[0][v].push_back(u);}
	for(int i=1;i<N;i++){int u,v;scanf("%d%d",&u,&v);G[1][u].push_back(v);G[1][v].push_back(u);}
	dfs(0,1);dfs(1,1);
	int ans=0;
	fa[1]=1;for(int i=2;i<=N;i++) if(f[0][i]==f[1][i]||f[0][f[1][i]]==i) fa[i]=f[1][i];else fa[i]=i,ans++;
	printf("%d\n",ans);
	Solve(1);
}