#include<cstdio>
#include<cstring>
const int N=1001;
int n,g[N],used[N];
int dfs(int u){
	if(!used[u]){used[u]=1;return dfs(g[u]);}
	else return u;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",g+i);
	for(int i=1;i<=n;i++)
	  memset(used,0,sizeof used),printf("%d ",dfs(i));
	return 0;
}