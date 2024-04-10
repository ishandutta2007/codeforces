#include<cstdio>
#include<vector>
#include<algorithm>
int T,n;
int main()
{
	scanf("%d",&T);
	std::vector<int>a;
	while(T--)
	{
		scanf("%d",&n);
		a.clear();a.resize(n);
		for(int i=0;i<n;++i)
		scanf("%d",&a[i]);
		std::sort(a.begin(),a.end());
		printf("%lld\n",std::unique(a.begin(),a.end())-a.begin());
	}
	return 0;
}