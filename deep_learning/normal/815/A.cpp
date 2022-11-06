#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std; 
int arr[105][105], row[105], col[105], row_mn[105], col_mn[105]; 
int main()
{
	// freopen("815A.in", "r", stdin); 
	memset(row_mn, 0x3f, sizeof(row_mn)); 
	memset(col_mn, 0x3f, sizeof(col_mn)); 
	int n, m; 
	scanf("%d%d", &n, &m); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			scanf("%d", arr[i] + j); 
			row_mn[i] = min(row_mn[i], arr[i][j]); 
			col_mn[j] = min(col_mn[j], arr[i][j]); 
		}
	}
	if (n < m)
		row[0] += row_mn[0]; 
	else
		col[0] += col_mn[0]; 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (row[i] + col[j] != arr[i][j])
				continue; 
			for (int x = 0; x < n; x++)
			{
				row[x] = max(row[x], arr[x][j] - row[x] - col[j]); 
				if (row[x] > row_mn[x])
				{
					printf("-1\n");
					return 0; 
				}
			}
			for (int x = 0; x < m; x++)
			{
				col[x] = max(col[x], arr[i][x] - row[i] - col[x]); 
				if (col[x] > col_mn[x])
				{
					printf("-1\n");
					return 0; 
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (row[i] + col[j] != arr[i][j])
			{
				printf("-1\n");
				return 0; 
			}
		}
	}
	int cnt = 0; 
	for (int i = 0; i < n; i++)
		cnt += row[i]; 
	for (int i = 0; i < m; i++)
		cnt += col[i]; 
	printf("%d\n", cnt);
	for (int i = 0; i < n; i++)
	{
		while (row[i]--)
			printf("row %d\n", i + 1);
	}
	for (int i = 0; i < m; i++)
	{
		while (col[i]--)
			printf("col %d\n", i + 1);
	}
	return 0; 
}