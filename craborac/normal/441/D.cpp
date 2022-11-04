#include<cstdio>
#include<algorithm>
#include<cmath>

using namespace std;

int mas[3010];
int used[3010];

int main()
{
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &mas[i]);
		mas[i]--;
		used[i] = 0;
	}
	int col = 0;
	for (int i = 0; i < n; i++)
	{
		if (used[i] == 0)
		{
			col++;
			used[i] = col;
			int q = mas[i];
			while (q != i)
			{
				used[q] = col;
				q = mas[q];
			}
		}
	}
	int m;
	scanf("%d", &m);
	int k = n - m;
	printf("%d\n", abs(col - k));
	if (col > k)
	{
		for (int qwe = 0; qwe < col - k; qwe++)
		{
			int w;
			for(int i = n - 1; i > 0; i--)
				if(used[i] != used[0])
					w = i;
			int e = used[w];
			for(int i = 0; i < n; i++)
				if(used[i] == e)
					used[i] = used[0];
			printf("1 %d ", w + 1);
		}
	}
	else if (col < k)
	{
		for (int qwe = 0; qwe < k - col; qwe++)
		{
			for (int i = 0; i < n; i++)
			{
				if (mas[i] != i)
				{
					int q = mas[i];
					int w = mas[i];
					while (q != i)
					{
						if (q < w)
							w = q;
						q = mas[q];
					}
					printf("%d %d ", i + 1, w + 1);
					int e = mas[i];
					mas[i] = mas[w];
					mas[w] = e;
					break;
				}
			}
			for(int i = 0; i < n; i++)
				used[i] = 0;
			int coll = 0;
			for(int i = 0; i < n; i++)
			{
				if(used[i] == 0)
				{
					coll++;
					used[i] = coll;
					int q = mas[i];
					while(q != i)
					{
						used[q] = coll;
						q = mas[q];	
					}
				}
			}
		}
	}
	return 0;
}