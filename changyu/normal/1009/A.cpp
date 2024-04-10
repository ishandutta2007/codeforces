#include<cstdio>
int n,m,a[1001],c[1001],s;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	for(int i=1;i<=m;i++)scanf("%d",a+i);
	int s=1;
	for(int j=1;s<=n&&j<=n;j++)
	  if(a[s]>=c[j])s++;
	printf("%d",s-1);
	return 0;
}