#include <cstdio>
#include <cstring>

int isc[1 << 20];

int main()
{
	memset(isc, 0, sizeof(isc));
	for (int i = 2; i <= 1000000; ++i)
	{
		if (!isc[i])
		{
			for (int j = i + i; j <= 1000000; j += i)
			{
				isc[j] = 1;
			}
		}
	}
	
	int n;
	scanf("%d", &n);
	for (int i = 2; i < n; ++i)
	{
		if (isc[i] && isc[n-i])
		{
			printf("%d %d\n", i, n - i);
			return 0;
		}
	}
	return 0;
}