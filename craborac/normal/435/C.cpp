#include<cstdio>
int mas[1010][2002];
int a[1010];
int main()
{
	int n;
	scanf("%d", &n);
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < 1010; i++)
		for(int j = 0; j < 2002; j++)
			mas[i][j] = 0;
	int q1 = 0;
	int q2 = 1001;
	int q = 1;
	int maxx = 1001;
	int minn = 1001;
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < a[i]; j++)
		{
			if(q > 0)
			{
				mas[q1 + j][q2 + j]	= 1;
			}
			else
			{
				mas[q1 + j][q2 - j] = -1;
			}
		}	
		q1 += a[i];
		q2 += (a[i] - 1) * q;
		if(q2 > maxx)
			maxx = q2;
		if(q2 < minn)
			minn = q2;
		q *= -1;
	}
	for(int j = maxx; j >= minn; j--)
	{
		for(int i = 0; i < q1; i++)
		{
			if(mas[i][j] == 0)
			{
				printf(" ");
			}
			else if(mas[i][j] > 0)
			{
				printf("/");
			}
			else
			{
				printf("\\");
			}
		}
		printf("\n");
	}
	return 0;
}