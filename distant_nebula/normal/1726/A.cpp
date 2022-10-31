#include <cstdio>
#include <algorithm>
#define INF 0x3f3f3f3f
const int N=2000005;
int T, n, a[N];
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a+i);
		if(n==1) { puts("0"); continue; }
		int ans=-INF;
		int mn=INF, mx=-INF;
		for(int i=1; i<n; ++i) mn=std::min(mn, a[i]);
		ans=a[n]-mn;
		for(int i=2; i<=n; ++i) mx=std::max(mx, a[i]);
		ans=std::max(ans, mx-a[1]);
		for(int i=1; i<n; ++i) ans=std::max(ans, a[i]-a[i+1]);
		printf("%d\n", ans);
	}
	return 0;
}