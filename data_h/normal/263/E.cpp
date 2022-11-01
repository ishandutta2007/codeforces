#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 1100;

int n, m, k;
long long sM[MAXN][MAXN], g[MAXN][MAXN], suma[MAXN][MAXN], sumb[MAXN][MAXN], bak[MAXN][MAXN];
long long sr[MAXN][MAXN], ra[MAXN][MAXN], rb[MAXN][MAXN], la[MAXN][MAXN], lb[MAXN][MAXN];

void Rot(long long a[MAXN][MAXN], int n, int m)
{
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			bak[j][n - i + 1] = a[i][j];
	for(int i = 1; i <= m; i++)
		for(int j = 1; j <= n; j++)
			a[i][j] = bak[i][j];
}

void Rotate()
{
	Rot(sM, n, m);
	Rot(g, n, m);
	swap(n, m);
}

void calc()
{
	memset(suma, 0, sizeof(suma));
	memset(sumb, 0, sizeof(sumb));
	memset(la, 0, sizeof(la));
	memset(lb, 0, sizeof(lb));
	memset(ra, 0, sizeof(ra));
	memset(rb, 0, sizeof(rb));
	memset(sr, 0, sizeof(sr));
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
		{
			sr[i][j] = sr[i - 1][j + 1] + sM[i][j];
			la[i][j] = la[i - 1][j] + sM[i][j] * i;
			lb[i][j] = lb[i - 1][j] + sM[i][j];
			ra[i][j] = ra[i][j - 1] + sM[i][j] * j;
			rb[i][j] = rb[i][j - 1] + sM[i][j];
		}
	for(int i = k; i <= n - k + 1; i++)
		for(int j = k; j <= m - k + 1; j++)
		{
			if (i == k && j == k)
			{
				for(int u = 1; u <= k; u++)
					for(int v = 1; v <= k; v++)
					{
						suma[i][j] += sM[u][v] * max(0, k - abs(u - i) - abs(v - j));
						if (k - abs(u - i) - abs(v - j) > 0)
							sumb[i][j] += sM[u][v];
					}
			} else
			if (i - 1 >= k)
			{
				suma[i][j] = (suma[i - 1][j] - sumb[i - 1][j]) + (ra[i][j] - ra[i][j - k])
															   - (rb[i][j] - rb[i][j - k]) * (j - k);
				sumb[i][j] = (sumb[i - 1][j] - (sr[i - 1][j - k + 1] - sr[i - k - 1][j + 1])) 
																	 + rb[i][j] - rb[i][j - k];
			} else
			{
				suma[i][j] = (suma[i][j - 1] - sumb[i][j - 1]) + (la[i][j] - la[i - k][j]) 
															   - (lb[i][j] - lb[i - k][j]) * (i - k);
				sumb[i][j] = (sumb[i][j - 1] - (sr[i][j - k] - sr[i - k][j])) + lb[i][j] - lb[i - k][j];
			}
		}
	for(int i = k; i <= n - k + 1; i++)
		for(int j = k; j <= m - k + 1; j++)
			g[i][j] += suma[i][j] - (ra[i][j] - ra[i][j - k] - (rb[i][j] - rb[i][j - k]) * (j - k));
}

int main()
{

	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%I64d", &sM[i][j]);
	for(int i = 1; i <= 4; i++)
	{
		calc();
		//break;
		Rotate();
	}
	long long ans = -1;
	int ansx, ansy;
	for(int i = k; i <= n - k + 1; i++)
		for(int j = k; j <= m - k + 1; j++)
		{
			g[i][j] += sM[i][j] * k;
			if (g[i][j] > ans)
				ans = g[i][j], ansx = i, ansy = j;
			//printf("%I64d ", g[i][j]);
		}
	printf("%d %d\n", ansx, ansy);
	/*
	if (ansx == 5 && ansy == 8)
	{
		printf("%I64d %I64d\n", g[ansx][ansy], g[7][17]);
	}
	*/
	return 0;
}