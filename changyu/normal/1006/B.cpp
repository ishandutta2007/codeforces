#include<cstdio>
#include<algorithm>
int n,m,a[2001],p[2001],k,s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int j=2000;j;j--)
	  for(int i=1;i<=n;i++)
		if(j==a[i])p[++k]=i;
	std::sort(p+1,p+1+m);
	for(int j=1;j<=m;j++)s+=a[p[j]];
	printf("%d\n",s);if(m>1)printf("%d ",p[1]);
	for(int j=2;j<m;j++)
	  printf("%d ",p[j]-p[j-1]);
	printf("%d",n-p[m-1]);
	return 0;
}