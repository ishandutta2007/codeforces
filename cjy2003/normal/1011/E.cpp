#include<stdio.h>
#include<string.h>
int n,k,a[100001],g;
int gcd(int a,int b)
{
	if(!b)return a;
	return gcd(b,a%b);
}
int main()
{
	scanf("%d %d",&n,&k);
	g=k;
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]),g=gcd(g,a[i]%k);
	printf("%d\n",(k-1)/g+1);
	int s=0;
	while(s<k)
	{
		printf("%d ",s);
		s+=g;	
	}
	return 0;
}