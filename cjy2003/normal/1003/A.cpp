#include<stdio.h>
#include<string.h>
int n,a[101],x,maxi;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&x);
		a[x]++;	
	}
	for(int i=1;i<=100;i++)
	if(maxi<a[i])maxi=a[i];
	printf("%d",maxi);
	return 0;
}