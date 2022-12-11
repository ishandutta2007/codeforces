#include<cstdio>
int n,a[15],tot;
int main()
{
	int tmp,num;
	scanf("%d",&n);for (int i=1;i<=n;i++) scanf("%d",a+i),tot+=a[i];
	if (n==1){return puts("-1"),0;}
	for (int i=1;i<(1<<n)-1;i++)
	{
		tmp=num=0;
		for (int j=0;j<n;j++) if ((i>>j)&1) tmp+=a[j+1],num++;
		if (tmp!=tot-tmp)
		{
			printf("%d\n",num);
			for (int j=0;j<n;j++) if ((i>>j)&1) printf("%d ",j+1);
			putchar('\n');
			return 0;
		}
	}
	puts("-1");
	return 0;
}