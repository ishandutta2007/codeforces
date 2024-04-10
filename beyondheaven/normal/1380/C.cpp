#include<bits/stdc++.h>
#define MaxN 100123
typedef long long LL;
int a[MaxN];
int main()
{
	int T,n,x;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d%d",&n,&x);
		for(int i=1;i<=n;++i)
		scanf("%d",a+i);
		std::sort(a+1,a+n+1);
		std::reverse(a+1,a+n+1);
		int c=0,ans=0;
		for(int i=1;i<=n;++i)
		if((++c)*a[i]>=x)
		++ans,c=0;
		printf("%d\n",ans);
	}
	return 0;
}