#include <cstdio>
#include <algorithm>
int T, n, k;
int main()
{
	scanf("%d", &T);
	while(T--)
	{
		scanf("%d%d", &n, &k);
		printf("%d\n", k/2+(n-k));
		for(int i=k-1; i*2>=k; --i) printf("%d ", i);
		for(int i=k+1; i<=n; ++i) printf("%d ", i);
		puts("");
	}
	return 0;
}