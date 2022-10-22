#include<bits/stdc++.h>
using namespace std;
int n,k,a[203];
vector<int>g[203];
int f[203][203],nf[203];
void dfs(int x,int fa){
	bool leaf=1;
	for(auto y:g[x])if(y!=fa)dfs(y,x),leaf=0;
	if(leaf){
		for(int i=0;i<203;i++)f[x][i]=max(f[x][i],0);
		f[x][0]=max(f[x][0],a[x]);
	}else{
		bool lst=1;
		for(auto y:g[x])if(y!=fa){
			if(lst)for(int i=0;i<202;i++)f[x][i+1]=max(f[x][i+1],f[y][i]);
			else{
				for(int i=0;i<203;i++)nf[i]=-1e9;
				for(int i=202;i;i--)for(int j=0;j<201;j++)if(i+j+1>k)
					nf[min(i,j+1)]=max(nf[min(i,j+1)],f[x][i]+f[y][j]);
				for(int i=0;i<203;i++)f[x][i]=nf[i];
			}
			lst=0;
		}
		f[x][0]=a[x];
		for(auto y:g[x])if(y!=fa)f[x][0]+=f[y][k];
		for(int i=201;~i;i--)f[x][i]=max(f[x][i],f[x][i+1]);
	}
}
int main(){
	for(int i=0;i<203;i++)for(int j=0;j<203;j++)f[i][j]=-1e9;
	scanf("%d%d",&n,&k);
	for(int i=1;i<=n;i++)scanf("%d",&a[i]);
	for(int i=1;i<n;i++){
		int u,v;scanf("%d%d",&u,&v);
		g[u].push_back(v),g[v].push_back(u);
	}
	dfs(1,0);
	printf("%d",f[1][0]);
}