#include<cstdio>
const int N=1e5+1,M=5e5+1;
int n,used[N*3],x[M],m,y[M],ans[M],k;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n*3;i++)used[i]=0;
	k=0;
	for(int j=1;j<=m;j++){
	  scanf("%d%d",x+j,y+j);
	  if(!used[x[j]]&&!used[y[j]])used[x[j]]=used[y[j]]=1,ans[++k]=j;
	}
	if(k>=n){
	  puts("Matching");
	  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	  puts("");
	}
	else{
	  puts("IndSet");
	  k=0;
	  for(int i=1;i<=n*3;i++)
		if(!used[i])ans[++k]=i;
	  for(int i=1;i<=n;i++)printf("%d ",ans[i]);
	  puts("");
	}
	}return 0;
}