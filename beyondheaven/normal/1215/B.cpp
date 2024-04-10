#include<bits/stdc++.h>
#define MaxN 200123
int a[MaxN];
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d",a+i),a[i]/=labs(a[i]);

	long long ans=0;
	std::map<int,int> mp({{1,1},{-1,0}});
	for(int i=1,s=1;i<=n;++i)
	{
		s*=a[i];
		ans+=mp[s];
		++mp[s];
	}
	
	std::cout<<1LL*n*(n+1)/2-ans<<" "<<ans<<std::endl;
	return 0;
}