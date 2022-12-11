#include<stdio.h>
#include<string.h>
int n,len,maxi,a[200001];
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;++i)
	{
		if(a[i]<=a[i-1]*2)len++;
		else
		{
			if(len>maxi)maxi=len;
			len=1;	
		}	
	}
	if(maxi<len)maxi=len;
	printf("%d",maxi);
	return 0;
}