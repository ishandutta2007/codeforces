#include <cstdio>
#include <algorithm>
#define N 100005
int T, n, cnt[N], mx, tot, ct;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		std::fill(cnt+1, cnt+n+1, 0);
		scanf("%d", &n);
		tot=n, ct=0;
		for(int i=1, x; i<=n; ++i) scanf("%d", &x), ++cnt[x];
		mx=0;
		for(int i=1; i<=n; ++i) mx=std::max(mx, cnt[i]);
		for(int i=1; i<=n; ++i) if(cnt[i]==mx) tot-=mx, ++ct;
		printf("%d\n", tot/(mx-1)+ct-1);
	}
	return 0;
}