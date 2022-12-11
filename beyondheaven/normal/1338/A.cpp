#include<bits/stdc++.h>
#define MaxN 100123
typedef long long LL;
int n,T;
LL a[MaxN];
inline int Lg2(LL x)
{
	if(x==0)return -1;
	else if(x==1)return 0;
	else return Lg2(x>>1)+1;
}
inline void Solve()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%lld",a+i);
	int ans=0;
	for(int i=2;i<=n;++i)
	{
		if(a[i]<a[i-1])
		{
			ans=std::max(ans,Lg2(a[i-1]-a[i])+1);
			a[i]=a[i-1];
		}
	}
	printf("%d\n",ans);
}
int main()
{
	scanf("%d",&T);
	while(T--)Solve();
	return 0;
}