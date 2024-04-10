#include<stdio.h>
#include<string.h>
int a[101],tp[101],n,k,sum,ans[101];
int main()
{
	scanf("%d %d",&n,&k);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<=n;i++)
		if(tp[a[i]]==0)ans[++sum]=i,tp[a[i]]=1;	
	if(sum<k)printf("NO");
	else
	{
		printf("YES\n");
		for(int i=1;i<=k;i++)
			printf("%d ",ans[i]);	
	}
	return 0;
}