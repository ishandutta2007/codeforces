#include<cstdio>
int n,p;bool d[1000],g[1000][1000];
bool dfs(int u)
{
	int c=0;
	for(int v=1;v<n;v++)if(g[u][v]){
	  if(d[v]&&!dfs(v))return 0;
	  if(!d[v])c++;
	}
	return c>=3;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++)scanf("%d",&p),p--,d[p]=g[p][i]=1;
	puts(dfs(0)?"Yes":"No");
	return 0;
}