#include<cstdio>
#include<algorithm>
#define MaxN 100123
int a[MaxN];
typedef long long LL;
int main()
{
	int n,T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		LL sum=0;
		for(int i=1;i<=n;++i)
		{
			scanf("%d",a+i);
			sum+=a[i];
		}
		LL maxv=-0x3f3f3f3f,tmp=0;
		for(int i=1;i<=n-1;++i)
		{
			maxv=std::max(maxv,tmp+=a[i]);
			tmp=std::max(tmp,0LL);
		}
		tmp=0;
		for(int i=2;i<=n;++i)
		{
			maxv=std::max(maxv,tmp+=a[i]);
			tmp=std::max(tmp,0LL);
		}
		if(sum>maxv)puts("YES");
		else puts("NO");
	}
	return 0;
}