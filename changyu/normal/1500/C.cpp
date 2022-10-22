#include<stdio.h>
#include<algorithm>
const int N=1503;
int a[N][N],b[N][N],n,m,c[N][N],d[N],f[N],t[N],ky,ans[N],k;
bool Cmp(const int&i,const int&j){return a[i][ky]<a[j][ky];}
signed main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<=m;j++)scanf("%d",&b[i][j]);
	for(int j=1;j<=m;j++)
	  for(int i=1;i<n;i++)
		if(b[i][j]>b[i+1][j])c[i][j]=1,++d[j];
	for(int p;;){
	  p=0;
	  for(int j=1;j<=m;j++)if(!d[j])p=j;
	  if(!p)break;
	  d[p]=-1;
	  ans[++k]=p;
	  for(int i=1;i<n;i++)if(!f[i]&&b[i][p]<b[i+1][p]){
		f[i]=1;
		for(int j=1;j<=m;j++)
		  if(c[i][j])c[i][j]=0,--d[j];
	  }
	}
	for(int i=1;i<=n;i++)t[i]=i;
	for(int l=k;l;l--){
	  ky=ans[l];
	  std::stable_sort(t+1,t+1+n,Cmp);
	}
	for(int i=1;i<=n;i++)
	  for(int j=1;j<=m;j++)if(a[t[i]][j]!=b[i][j])return 0*puts("-1");
	printf("%d\n",k);
	for(int l=k;l;l--)printf("%d ",ans[l]);puts("");
	return 0;
}