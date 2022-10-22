#include<cstdio>
int n,m,ans=-1;
int main(){
	scanf("%d%d",&n,&m);
	for(int i=0;i<=n/2;i++)
	  if((n-i)%m==0)ans=n-i;
	printf("%d",ans);
	return 0;
}