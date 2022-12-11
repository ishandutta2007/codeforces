#include<stdio.h>
#include<string.h>
int n,maxi,a[110],sum;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	{
		scanf("%d",&a[i]);
		if(a[i]>maxi)maxi=a[i];	
		sum+=a[i];
	}
	if(sum*2/n+1>maxi)
	printf("%d",sum*2/n+1);
	else printf("%d",maxi);
	return 0;
}