#include<cstdio>
#include<iostream>
#include<vector>

using namespace std;

vector<int> mas[(int)1e5];
int a[(int)1e5];
int main()
{
	int n, k, p;
	cin >> n >> k >> p;
	int col = 0;
	for(int i = 0; i < n; i++)
	{
		cin >> a[i];
		if(a[i] % 2 == 1)
			col++;
	}
	if((col % 2 == (k - p) % 2) && (col >= k - p))
	{
		if(n - col + ((col - (k - p)) / 2) >= p)
		{
			printf("YES\n");
			int col1 = 0;
			int col2 = 0;
			for(int i = 0; i < n; i++)
			{
				if(a[i] % 2 == 0)
				{
					if(col2 < p)
					{
						mas[col2].push_back(a[i]);
						col2++;		
					}
					else
						mas[0].push_back(a[i]);
				}
			}
			if(col2 < p)
			{
				for(int i = 0; i < n; i++)
				{
					if(a[i] % 2 == 1)
					{
						if(col2 + (col1 / 2) < p)
						{
							mas[col2 + (col1 / 2)].push_back(a[i]);
							col1++;
						}
						else
						{
							if(col1 < (p - col2) * 2 + k - p)
							{
								mas[p + col1 - (p - col2) * 2].push_back(a[i]);
								col1++;
							}
							else
								mas[0].push_back(a[i]);
						}
					}
				}	
			}
			else
			{
				for(int i = 0; i < n; i++)
				{
					if(a[i] % 2 == 1)
					{
						if(col1 < k - p)
						{
							mas[p + col1].push_back(a[i]);
							col1++;
						}
						else
							mas[0].push_back(a[i]);
					}	
				}
			}
			for(int i = 0; i < k; i++)
			{
				printf("%d ", (int)mas[i].size());
				for(int j = 0; j < (int)mas[i].size(); j++)
					printf("%d ", mas[i][j]);
				printf("\n");
			}
		}
		else
			printf("NO");
	}
	else
		printf("NO");
	return 0;
}