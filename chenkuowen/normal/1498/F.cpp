#include<bits/stdc++.h>
using namespace std;
const int N=5+1e5;
int n,k;
int f[N][45],g[N][45],a[N];
vector<int> e[N];
void dfs(int x,int pre){
	if(pre!=0) e[x].erase(find(e[x].begin(),e[x].end(),pre));
	f[x][0]^=a[x];
	for(auto y:e[x]){
		dfs(y,x);
		for(int i=0;i<k+k;++i)
			f[x][(i+1)%(k+k)]^=f[y][i];
	}
}
void dfs2(int x,int pre){
	for(int i=0;i<k+k;++i) g[x][i]=f[x][i];
	if(pre!=0){
		for(int i=0;i<k+k;++i)
			g[x][(i+1)%(k+k)]^=g[pre][i]^f[x][(i+k+k-1)%(k+k)];
	}
	for(auto y:e[x]) dfs2(y,x);
}
int main(){
	scanf("%d%d",&n,&k);
	for(int i=1;i<n;++i){
		int x,y; scanf("%d%d",&x,&y);
		e[x].push_back(y); e[y].push_back(x);
	}
	for(int i=1;i<=n;++i) scanf("%d",&a[i]);
	dfs(1,0); dfs2(1,0);
	for(int x=1;x<=n;++x){
		int ans=0;
		for(int i=k;i<k+k;++i) ans^=g[x][i];
//		for(int i=0;i<k+k;++i) printf("[%d]",g[x][i]); puts("");
		printf("%d ",int(ans>0));
	}
	return 0;
}