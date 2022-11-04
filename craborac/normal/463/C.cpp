#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>

using namespace std;

long long mas[2000][2000], left[5000], right[5000];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%lld", &mas[i][j]);
	for (int i = 0; i < 2 * n - 1; i++)
	{
		left[i] = 0;
		for (int x = 0; x < min(n, i + 1); x++)
		{
			int y = i - x;
			if (y < n)
				left[i] += mas[x][y];
		}
	}
	
	for (int i = -1 * n + 1; i < n; i++)
	{
		right[i + n - 1] = 0;
		for (int x = 0; x < n; x++)
		{
			int y = x + i;
			if ((y >= 0) && (y < n))
				right[i + n - 1] += mas[x][y];
		}
	}
	
	long long max0 = 0;
	long long max1 = 0;
	int x0 = 0, x1 = 1, y0 = 0, y1 = 0;
	for (int x = 0; x < n; x++)
	{
		for (int y = 0; y < n; y++)
		{
			if ((x + y) % 2 == 0)
			{
				if (left[x + y] + right[y - x + n - 1] - mas[x][y] > max0)
				{
					max0 = left[x + y] + right[y - x + n - 1] - mas[x][y];
					x0 = x;
					y0 = y;
				}
			}
			else if(left[x + y] + right[y - x + n - 1] - mas[x][y] > max1)
			{
				max1 = left[x + y] + right[y - x + n - 1] - mas[x][y];
				x1 = x;
				y1 = y;
			}
		}
	}
	printf("%lld\n", max0 + max1);
	printf("%d %d %d %d", x0 + 1, y0 + 1, x1 + 1, y1 + 1);
	
	return 0;
}