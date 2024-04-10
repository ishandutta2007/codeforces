#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

typedef pair<int, int> pii;

const double eps = 1e-8;

int n, m, lc = 0;
int a, b;

vector<int> g[32];

int en[32][32];
pii de[1024];

double pr[32];

void pmat(double a[256][256])
{
	for (int i = 0; i < lc; ++i)
	{
		for (int j = 0; j < lc; ++j)
		{
			printf("%lf ", a[i][j]);
		}
		printf("\n");
	}
}

void msq(double a[256][256], double b[256][256])
{
	memset(b, 0, 256 * 256 * sizeof(b[0][0]));
	int si = 32, sj = 32;
	si = sj = 8;
	for (int i1 = 0; i1 < 256; i1 += si)
	{
		for (int j1 = 0; j1 < 256; j1 += sj)
		{
			for (int k1 = 0; k1 < 256; k1 += si)
			{
				for (int i = i1; i < i1 + si; ++i)
				{
					for (int j = j1; j < j1 + sj; ++j)
					{
						for (int k = k1; k < k1 + si; ++k)
						{
							b[i][j] += a[i][k] * a[k][j];
						}
					}
				}
			}
		}
	}
}

double st[256][256];
double tmp[256][256];

int main()
{
	scanf("%d %d %d %d", &n, &m, &a, &b);
	--a; --b;
	for (int i = 0; i < m; ++i)
	{
		int j, k;
		scanf("%d %d", &j, &k);
		--j; --k;
		g[j].push_back(k);
		g[k].push_back(j);
	}
	
	for (int i = 0; i < n; i++)
	{
		scanf("%lf", &pr[i]);
		g[i].push_back(i);
	}
	
	for (int i = 0; i < n; ++i)
	{
		for (int j = i; j < n; ++j)
		{
			en[i][j] = lc;
			//~ printf("OP %d %d %d\n", i, j, lc);
			de[lc] = make_pair(i, j);
			en[j][i] = lc;
			++lc;
		}
	}
	
	memset(st, 0, sizeof(st));
	for (int i = 0; i < lc; ++i)
	{
		int x = de[i].first;
		int y = de[i].second;
		if (x == y)
		{
			st[i][i] = 1.0;
			continue;
		}
		
		int nx, ny;
		double px, py;
		for (int j = 0; j < (int) g[x].size(); ++j)
		{
			nx = g[x][j];
			if (nx == x)
			{
				px = pr[x];
			}
			else
			{
				px = (1.0 - pr[x]) / (g[x].size() - 1);
			}
			for (int k = 0; k < (int) g[y].size(); ++k)
			{
				ny = g[y][k];
				if (ny == y)
				{
					py = pr[y];
				}
				else
				{
					py = (1.0 - pr[y]) / (g[y].size() - 1);
				}
				//~ printf("ED %d %d -> %d %d :: %lf %lf %lf\n", x, y, nx, ny, px, py, px * py);
				
				st[i][ en[nx][ny] ] += px * py;
			}
		}
	}
	
	//~ pmat(st);
	
	bool fl = 1;
	while (fl)
	{
		memcpy(tmp, st, sizeof(st));
		msq(tmp, st);
		fl = 0;
		int s = en[a][b];
		for (int i = 0; i < lc; ++i)
		{
			if (st[s][i] > eps && de[i].first != de[i].second)
			{
				fl = 1;
				break;
			}
		}
	}
	
	int s = en[a][b];
	for (int i = 0; i + 1 < n; ++i)
	{
		printf("%.10lf ", st[s][ en[i][i] ]);
	}
	printf("%.10lf\n", st[s][en[n-1][n-1]]);
	
	return 0;
}