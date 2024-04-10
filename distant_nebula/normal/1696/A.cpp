#include <cstdio>
#include <algorithm>
const int N=2005;
int T, n, a[N], z;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &z);
		int mx=0;
		for(int i=1; i<=n; ++i) scanf("%d", a+i), mx=std::max(mx, z|a[i]);
		printf("%d\n", mx);
	}
	return 0;
}