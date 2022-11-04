#include<cstdio>
int a[1000], mas[1000][10], mas10[100];
int main()
{
	int n, k;
	
	int col = 0;
	scanf("%d%d", &n, &k);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=k;j++)
			mas[i][j] = 0;
	}
	for(int i = 0;i<n;i++)
	{
		scanf("%d", &a[i]);
		int l = 1;
		int r = 0;
		while(l <= a[i])
		{
			mas10[r] = l;
			l *= 10;
			r++;
		}
		mas10[r] = l;
		mas10[r + 1] = 10 * l;
		for(int j=0;j<r;j++)
		{
			if (j == 0)
				mas[i][a[i] % 10] = 1;
			else
			{
				 int x = ((a[i] % mas10[j+1]) - (a[i] % mas10[j])) / mas10[j];
				 mas[i][x] = 1;
			}
		}
		int q = 1;
		for (int j=0;j<=k;j++)
			if (mas[i][j] != 1) q = 0;
		if (q == 1) col++;
	}
	printf("%d", col);
	return 0;
}