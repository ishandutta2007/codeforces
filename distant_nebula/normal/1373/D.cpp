#include <cstdio>
#include <algorithm>
#define N 200005
#define ll long long
int T, n, a[N];
ll sum, ad, mx, cur;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		sum=ad=mx=cur=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		for(int i=1; i<=n; i+=2) sum+=a[i];
		for(int i=2; i<=n; i+=2) cur+=a[i]-a[i-1], ad=std::max(ad, cur-mx), mx=std::min(mx, cur);
		mx=cur=0;
		for(int i=2; i<n; i+=2) cur+=a[i]-a[i+1], ad=std::max(ad, cur-mx), mx=std::min(mx, cur);
		printf("%lld\n", sum+ad);
	}
	return 0;
}