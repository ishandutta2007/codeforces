#include<stdio.h>
#include<string.h>
int n,k;
double a[5001],s[5001],maxi;
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
	{
		scanf("%lf",&a[i]);
		s[i]=s[i-1]+a[i];
	}
	for(int i=k;i<=n;i++)
		for(int j=1;j<=n-i+1;j++)
			if(maxi<(s[j+i-1]-s[j-1])/i)maxi=(s[j+i-1]-s[j-1])/i;
	printf("%.10lf",maxi);
	return 0;
}