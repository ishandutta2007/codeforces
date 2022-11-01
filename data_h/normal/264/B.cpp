#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 200000;

int n;
int a[MAXN];
int f[MAXN];

int main()
{

	scanf("%d", &n);
	for(int i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	for(int i = 1; i <= n; i++)
	{
		int tmp = 1;
		for(int j = 1; j * j <= a[i]; j++)
		if (a[i] % j == 0)
		{
			if (j != 1) tmp = max(tmp, f[j] + 1);
			if (a[i] / j != 1) tmp = max(tmp, f[a[i] / j] + 1);
		}
		for(int j = 1; j * j <= a[i]; j++)
		if (a[i] % j == 0)
		{
			f[j] = max(f[j], tmp);
			f[a[i] / j] = max(f[a[i] / j], tmp);
		}
	}
	int ans = 0;
	for(int i = 1; i <= 100000; i++)
		ans = max(ans, f[i]);
	printf("%d\n", ans);
	return 0;
}