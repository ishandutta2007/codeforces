#include<cstdio>

int n, m, x, y;
int col[45010];
void next()
{
	if(y % 2 == 1)
	{
		if(x == n)
			y++;
		else
			x++;
	}
	else
	{
		if(x == 1)
			y++;
		else
			x--;
	}
}

int main()
{
	int k;
	scanf("%d %d %d", &n, &m, &k);
	x = 1;
	y = 1;
	for(int i = 0; i < k; i++)
		col[i] = 0;
	int q = 0;
	while(true)
	{
		if(q < k - 1)
		{
			if(col[q] == 0)
			{
				printf("2 %d %d ", x, y);
				col[q]++;
				next();
			}
			else
			{
				printf("%d %d\n", x, y);
				q++;
				next();
			}
		}
		else
		{
			if(col[q] == 0)
			{
				printf("%d %d %d ", n * m - 2 * (k - 1), x, y);
			}
			else
				printf("%d %d ", x, y);
			col[q]++;
			next();
			if(col[q] == n * m - 2 * (k - 1))
				break;
		}
	}
	return 0;
}