#include<cstdio>
int n,t=1;
int main()
{
	scanf("%d",&n);
	for(;n;n>>=1,t<<=1){
	  if(n==3)return 0*printf("%d %d %d ",t,t,3*t);
	  for(int i=1;i<=n;i+=2)printf("%d ",t);
	}return 0;
}