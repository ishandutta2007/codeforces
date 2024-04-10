#include<cstdio>
const int N=1e5+3;
int n,a[N],ans[N],used[N],k;
int main(){
	int T;scanf("%d",&T);for(;T--;){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)used[i]=0;
	for(int i=1;i<=n;i++){
	  scanf("%d",a+i);
	  if(a[i]>a[i-1])ans[i]=a[i],used[a[i]]=1;
	  else ans[i]=0;
	}
	k=1;
	for(int i=1;i<=n;i++)
	  if(!ans[i]){
		for(;used[k];++k);
		used[k]=1;
		ans[i]=k;
		if(ans[i]>a[i]){puts("-1");goto Brk;}
	  }
	for(int i=1;i<=n;i++)printf("%d ",ans[i]);puts("");
	Brk:;
	}return 0;
}