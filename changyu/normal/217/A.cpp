#include<cstdio>
const int N=101;
int n,x[N],y[N],used[N],ans;
int dfs(int t){
	used[t]=1;
	for(int i=1;i<=n;i++)
	  if(!used[i]&&(x[i]==x[t]||y[i]==y[t]))
		dfs(i);
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d%d",x+i,y+i);
	for(int i=1;i<=n;i++)
	  if(!used[i])dfs(i),ans++;
	printf("%d",ans-1);
	return 0;
}