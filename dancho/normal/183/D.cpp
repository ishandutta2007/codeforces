#include <cstdio>
#include <cstring>

const double eps = 1e-10;

int n, m;
double pr[320][3020];

double dp[4000][3020];
int la = 0;

int c[320];
int row[320][3020];

double getDP(int s, int c, int p)
{
	if (c == 0.0)
		return 1.0;
	if (p >= n)
		return 0.0;
	if (dp[ row[s][c] ][p] == dp[ row[s][c] ][p])
	{
		return dp[ row[s][c] ][p];
	}
	double sol = 0.0;
	sol += pr[s][p] * getDP(s, c - 1, p + 1);
	sol += (1.0 - pr[s][p]) * getDP(s, c, p + 1);
	return (dp[ row[s][c] ][p] = sol);
}

int main()
{
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; ++j)
		{
			scanf("%lf", &pr[j][i]);
			pr[j][i] /= 1000.0;
		}
	}
	
	memset(dp, -1, sizeof(dp));
	memset(row, -1, sizeof(row));
	la = 0;
	for (int i = 0; i < m; ++i)
	{
		row[i][1] = la++;
		c[i] = 1;
	}
	
	double tot = 0.0;
	for (int i = 0; i < n; i++)
	{
		int mx = 0;
		for (int j = 0; j < m; ++j)
		{
			if (getDP(j, c[j], 0) + eps > getDP(mx, c[mx], 0))
				mx = j;
		}
		tot += getDP(mx, c[mx], 0);
		++c[mx];
		row[mx][c[mx]] = la++;
	}
	
	printf("%.12lf\n", tot);
	return 0;
}