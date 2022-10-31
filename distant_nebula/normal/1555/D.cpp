#include <cstdio>
#include <algorithm>
const int N=200005;
int n, m, sum[6][N];
char s[N];
int main()
{
	scanf("%d%d%s", &n, &m, s+1);
	for(int i=1; i<=n; ++i)
	{
		for(int j=0; j<6; ++j)
			sum[j][i]=sum[j][i-1]+(s[i]-'a'!=(j+(j>=3?2:1)*i)%3);
	}
	for(int i=1, x, y; i<=m; ++i)
	{
		scanf("%d%d", &x, &y);
		int ans=0x3f3f3f3f;
		for(int i=0; i<6; ++i) ans=std::min(ans, sum[i][y]-sum[i][x-1]);
		printf("%d\n", ans);
	}
	return 0;
}