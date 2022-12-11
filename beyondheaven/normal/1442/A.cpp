#include<bits/stdc++.h>
#define MaxN 30123
typedef long long LL;

int n,a[MaxN];
LL d[MaxN];

int main()
{
	int T;scanf("%d",&T);
	while(T--)
	{
		for(int i=1;i<=n;++i)a[i]=d[i]=0;
		
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		scanf("%d",a+i),d[i]=a[i]-a[i-1];
		
		for(int i=n;i>1;--i)
		if(d[i]<0)d[1]+=d[i];
		
		if(d[1]>=0)puts("YES");
		else puts("NO");
	}
	return 0;
}