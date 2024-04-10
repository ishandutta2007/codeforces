#include<cstdio>
inline int max(int a,int b){return a>b?a:b;}
const int N=2001;
int n,f[N],d[N],ans=1;
int dfs(int u){return d[u]=d[u]?d[u]:dfs(f[u])+1;}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
	  scanf("%d",f+i);
	  if(f[i]==-1)f[i]=0;
	}
	d[0]=1;
	for(int i=1;i<=n;i++)ans=max(dfs(i),ans);
	printf("%d",ans-1);
	return 0;
}