#include<bits/stdc++.h>
#define MaxN 1123
int a[MaxN];
int pre[MaxN],suf[MaxN];
int main()
{
	int T,n;
	scanf("%d",&T);
	while(T--)
	{
		memset(pre,0,sizeof(pre));
		memset(suf,0,sizeof(suf));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		scanf("%d",a+i);
		for(int i=1;i<=n;++i)
		for(int j=i-1;j;--j)
		if(a[j]<a[i])pre[i]=j;
		for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
		if(a[j]<a[i])suf[i]=j;
		bool flag=false;
		for(int i=1;i<=n;++i)
		if(pre[i]&&suf[i])
		{
			puts("YES");
			printf("%d %d %d\n",pre[i],i,suf[i]);
			flag=true;
			break;
		}
		if(!flag)puts("NO");
	}
	return 0;
}