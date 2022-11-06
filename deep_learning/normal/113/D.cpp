#include <iostream>
#include <cstring>
#include <cstdio>
#include <cmath>
using namespace std; 
double mat[625][625], p[25][25]; 
int lst[25], to[625], pre[625], tot; 
inline void add_edge(int u, int v)
{
	to[tot] = v; 
	pre[tot] = lst[u]; 
	lst[u] = tot++; 
}
inline void guass(int n, int m)
{
	for (int i = 0; i < n; i++)
	{
		int k = i; 
		for (int j = i + 1; j < n; j++)
		{
			if (fabs(mat[j][i]) > fabs(mat[k][i]))
				k = j; 
		}
		if (k != i)
		{
			for (int j = 0; j < m; j++)
				swap(mat[k][j], mat[i][j]); 
		}
		for (int j = i + 1; j < n; j++)
		{
			double tmp = mat[j][i] / mat[i][i]; 
			for (int x = i; x < m; x++)
				mat[j][x] -= tmp * mat[i][x]; 
		}
	}
	for (int i = n - 1; i >= 0; i--)
	{
		for (int j = i + 1; j < n; j++)
		{
			for (int x = n; x < m; x++)
				mat[i][x] -= mat[j][x] * mat[i][j]; 
		}
		for (int x = n; x < m; x++)
			mat[i][x] /= mat[i][i]; 
	}
}
int main()
{
	// freopen("113D.in", "r", stdin); 
	memset(lst, -1, sizeof(lst));
	int n, m, s, t; 
	scanf("%d%d%d%d", &n, &m, &s, &t); 
	s--; 
	t--; 
	for (int i = 0; i < m; i++)
	{
		int u, v; 
		scanf("%d%d", &u, &v); 
		add_edge(--u, --v); 
		add_edge(v, u); 
	}
	for (int i = 0; i < n; i++)
		scanf("%lf", p[i] + i); 
	for (int i = 0; i < n; i++)
	{
		double x = 1.0 - p[i][i]; 
		int cnt = 0;
		for (int j = lst[i]; ~j; j = pre[j])
			cnt++;
		for (int j = lst[i]; ~j; j = pre[j])
			p[i][to[j]] = x / cnt; 
	}
	if (s == t)
	{
		for (int i = 0; i < n; i++)
			printf("%.15lf%c", i == s ? 1.0 : 0.0, " \n"[i + 1 == n]);
		return 0;
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (i == j)
			{
				mat[i * n + j][i * n + j] = 1; 
				continue; 
			}
			mat[i * n + j][i * n + j] = -1; 
			for (int u = 0; u < n; u++)
			{
				for (int v = 0; v < n; v++)
					mat[i * n + j][u * n + v] += p[i][u] * p[j][v]; 
			}
		}
	}
	for (int x = 0; x < n; x++)
		mat[x * n + x][n * n + x] = 1; 
	guass(n * n, n * n + n); 
	for (int i = 0; i < n; i++)
		printf("%.15lf%c", mat[s * n + t][n * n + i], " \n"[i + 1 == n]);
	return 0; 
}