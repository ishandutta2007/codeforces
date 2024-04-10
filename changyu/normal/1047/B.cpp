#include<cstdio>
int a,b,n,x;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	  scanf("%d %d",&a,&b),
	  x=a+b>x?a+b:x;
	printf("%d",x);
	return 0;
}