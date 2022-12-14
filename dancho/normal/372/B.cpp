#include <cstdio>
#include <cstring>

int n, m, q;
int ps[64][64];
char x[64][64];

int it[64][64][64][64];

int main()
{
	scanf("%d %d %d", &n, &m, &q);
	
	for (int i = 0; i < n; i++)
	{
		scanf("%s", x[i]);
	}
	memset(ps, 0, sizeof(ps));
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			ps[i][j] = ps[i-1][j] + ps[i][j-1] - ps[i-1][j-1] + (x[i-1][j-1] == '1');
		}
	}
	
	memset(it, 0, sizeof(it));
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int k = i; k <= n; ++k)
			{
				for (int l = j; l <= m; ++l)
				{
					if (ps[k][l] - ps[i-1][l] - ps[k][j-1] + ps[i-1][j-1] == 0)
					{
						++it[n-i+1][m-j+1][k][l];
					}
				}
			}
		}
	}
	
	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			for (int k = 1; k <= n; ++k)
			{
				for (int l = 1; l <= m; ++l)
				{
					it[i][j][k][l] = it[i][j][k][l] + it[i][j][k][l-1] + it[i][j][k-1][l] + it[i][j-1][k][l] + it[i-1][j][k][l]
						- it[i][j][k-1][l-1] - it[i][j-1][k][l-1] - it[i-1][j][k][l-1] - it[i-1][j][k-1][l]
						- it[i][j-1][k-1][l] - it[i-1][j-1][k][l]
						+ it[i-1][j-1][k-1][l] + it[i-1][j-1][k][l-1] + it[i-1][j][k-1][l-1] + it[i][j-1][k-1][l-1]
						- it[i-1][j-1][k-1][l-1];
				}
			}
		}
	}
	
	int a, b, c, d;
	for (int i = 0; i < q; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		printf("%d\n", it[n-a+1][m-b+1][c][d]);
	}
	return 0;
}