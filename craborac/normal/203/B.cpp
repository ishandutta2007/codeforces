#include<cstdio>
int mas[2000][2000];
int main()
{
	int n, m;
	scanf("%d%d", &n, &m);
	for(int i = 0; i < 2000; i++)
		for(int j = 0; j < 2000; j++)
			mas[i][j] = 0;
	for(int i = 0; i < m; i++)
	{
		int a, b;
		scanf("%d%d", &a, &b);
		a++;
		b++;
		mas[a][b] = 1;
		bool qwe = 0;
		for(int x = a - 1; x < a + 2; x++)
		{
			for(int y = b - 1; y < b + 2; y++)
			{
				int sum = 0;
				for(int dx = -1; dx < 2; dx++)
				{
					for(int dy = -1; dy < 2; dy++)
						sum += mas[x + dx][y + dy];
				}
				if(sum == 9)
					qwe = 1;
			}
		}
		if(qwe)
		{
			printf("%d", i + 1);
			return 0;
		}
	}
	printf("-1");
	return 0;
}