#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;

int n, k;
int f[2048];

int main()
{
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &f[i]);
	}
	
	sort(f, f + n);
	int c = 0;
	int b = -1;
	int ans = 0;
	for (int i = n - 1; i >= 0; --i)
	{
		if (c == k)
		{
			ans += 2 * (f[b] - 1);
			b = -1;
			c = 0;
		}
		++c;
		if (b == -1)
			b = i;
	}
	if (b != -1)
	{
		ans += 2 * (f[b] - 1);
	}
	printf("%d\n", ans);
	
	return 0;
}