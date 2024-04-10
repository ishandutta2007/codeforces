#include<cstdio>
#include<algorithm>
const int N=2003;
int n,a[N],b[N],t[N],rnk[N],p,s,f;bool ans[N][N];
bool Cmp(const int &i,const int &j){return a[i]<a[j];}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",a+i),b[i]=a[i],t[i]=i;
	std::sort(t+1,t+1+n,Cmp);
	for(int i=1;i<=n;i++)rnk[t[i]]=i;
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=n;j++)
		if(a[t[j]])a[t[j]]--,ans[(i+j-1)%(n+1)+1][j]=1;
	for(int j=1;j<=n;j++)if(ans[1][j]!=ans[n+1][j])goto Brk;
	for(int j=1;j<=n;j++)if(ans[1][j]){p=j;break;}
	if(b[t[p]]==n)std::swap(ans[p][p-1],ans[1][p-1]);
	else std::swap(ans[p-1][p],ans[1][p]);
	Brk:;
	for(int i=1;i<=n+1;i++)
	  for(int j=1;j<=n;j++)
		if(ans[i][j]){s++;break;}
	printf("%d\n",s);
	for(int i=1;i<=n+1;i++){
	  f=0;
	  for(int j=1;j<=n;j++)
		if(ans[i][j]){f=1;break;}
	  if(f){
		for(int j=1;j<=n;j++)printf("%d",ans[i][rnk[j]]);
		puts("");
	  }
	}return 0;
}