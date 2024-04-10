#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

const int MAXN = 110, inf = 1000000000;

int row[MAXN], col[MAXN];
int mat[MAXN][MAXN];

int main()
{
	int n, m;
	scanf("%d %d", &n, &m);
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &mat[i][j]);
	while(1)
	{
		//row
		int vrow = inf, prow;
		for(int i = 1; i <= n; i++)
		{
			int sum = 0;
			for(int j = 1; j <= m; j++)
				sum += mat[i][j];
			if (sum < vrow)
				vrow = sum, prow = i;
		}
		int vcol = inf, pcol;
		for(int i = 1; i <= m; i++)
		{
			int sum = 0;
			for(int j = 1; j <= n; j++)
				sum += mat[j][i];
			if (sum < vcol)
				vcol = sum, pcol = i;
		}
		if (min(vcol, vrow) >= 0)
			break;
		if (vrow < vcol)
		{
			row[prow] ^= 1;
			for(int i = 1; i <= m; i++)
				mat[prow][i] *= -1;
		} else
		{
			col[pcol] ^= 1;
			for(int i = 1; i <= n; i++)
				mat[i][pcol] *= -1;
		}
	}
	int cnt = 0;
	for(int i = 1; i <= n; i++)
		cnt += row[i];
	printf("%d", cnt);
	for(int i = 1; i <= n; i++)
		if (row[i])
			printf(" %d", i);
	printf("\n");
	
	cnt = 0;
	for(int i = 1; i <= m; i++)
		cnt += col[i];
	printf("%d", cnt);
	for(int i = 1; i <= m; i++)
		if (col[i])
			printf(" %d", i);
	printf("\n");
	return 0;
}