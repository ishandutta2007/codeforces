#include <cstdio>
#include <cstring>

int n, m, k;
char t[2048][2048];
int sl[2048];

int main()
{
	scanf("%d %d %d", &n, &m, &k);
	for (int i = 0; i < n; i++)
	{
		scanf("%s", t[i]);
	}

	memset(sl, 0, sizeof(sl));
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (t[i][j] == 'R')
			{
				if (i + j < m)
					++sl[i + j];
			}
			if (t[i][j] == 'L')
			{
				if (j - i >= 0)
					++sl[j - i];
			}
			if (t[i][j] == 'U')
			{
				if (i % 2 == 0)
					++sl[j];
			}
		}
	}
	for (int i = 0; i + 1 < m; ++i)
	{
		printf("%d ", sl[i]);
	}
	printf("%d\n", sl[m-1]);
	return 0;
}