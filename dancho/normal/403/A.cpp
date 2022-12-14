#include <cstdio>
#include <cstring>

int deg[1024];
int us[1024][1024];

int main()
{
	int n, p;
	int t, T;
	scanf("%d", &T);
	for (t = 0; t < T; ++t)
	{
		scanf("%d %d", &n, &p);
		memset(deg, 0, sizeof(deg));
		memset(us, 0, sizeof(us));
		deg[0] = (1<<29);
		for (int i = 0; i < 2 * n + p; ++i)
		{
			int j = 0;
			int k = 0;
			for (int l = 1; l <= n; ++l)
			{
				for (int s = l + 1; s <= n; ++s)
				{
					if (!us[l][s] && deg[l] + deg[s] < deg[j] + deg[k])
					{
						j = l;
						k = s;
					}
				}
			}
			++deg[j];
			++deg[k];
			us[j][k] = 1;
			printf("%d %d\n", j, k);
		}
	}
	return 0;
}