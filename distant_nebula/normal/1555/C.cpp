#include <cstdio>
#include <algorithm>
const int N=100005;
int T, n, a[2][N], sum[2][N], ans;
int main()
{
	int x1, y1, x2, y2;
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d", &n);
		for(int i=1; i<=n; ++i) scanf("%d", a[0]+i);
		for(int i=1; i<=n; ++i) scanf("%d", a[1]+i), sum[1][i]=sum[1][i-1]+a[1][i];
		sum[0][n+1]=0;
		for(int i=n; i; --i) sum[0][i]=sum[0][i+1]+a[0][i];
		ans=0x3f3f3f3f;
		for(int i=1; i<=n; ++i) ans=std::min(ans, std::max(sum[0][i+1], sum[1][i-1]));
		printf("%d\n", ans);
	}
	return 0;
}