#include <cstdio>
#include <cstring>

int n;
char s[100020][2][55];
bool dp[100020][2];
int p[100020];

int main()
{
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < 2; ++j)
		{
			scanf("%s", s[i][j]);
		}
	}
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &p[i]);
		--p[i];
	}
	
	memset(dp, 0, sizeof(dp));
	dp[0][0] = dp[0][1] = 1;
	for (int i = 0; i + 1 < n; i++)
	{
		bool fl = 0;
		for (int j = 0; j < 2; ++j)
		{
			for (int k = 0; k < 2; ++k)
			{
				//~ printf("NCMP %d %s %s\n", i, s[i][j], s[i + 1][k]);
				if (dp[i][j] && strcmp(s[p[i]][j], s[p[i + 1]][k]) < 0)
				{
					fl = 1;
					dp[i + 1][k] = 1;
				}
			}
		}
		if (!fl)
		{
			printf("NO\n");
			return 0;
		}
	}
	
	printf("YES\n");
	return 0;
}