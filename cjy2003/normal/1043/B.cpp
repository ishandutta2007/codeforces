#include<stdio.h>
#include<string.h>
int n,a[1010],ans[1010],num;
bool flag;
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
		scanf("%d",&a[i]);	
	for(int i=n;i>=1;--i)
		a[i]=a[i]-a[i-1];
	for(int i=1;i<=n;++i)
	{
		flag=0;
		for(int j=i+1;j<=n;++j)
			if(a[j]!=a[j-i])
			{
				flag=1;
				break;	
			}
		if(!flag)ans[++num]=i;
	}
	printf("%d\n",num);
	for(int i=1;i<=num;++i)
		printf("%d ",ans[i]);
	return 0;
}