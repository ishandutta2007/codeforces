#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 400
int imos[200001];
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>vec;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	for (int i = 1; i < num; i++)
	{
		for (int j = 1;; j++)
		{
			if ((i - 1) / j>SIZE)
			{
				if (vec[i] < vec[(i - 1) / j])
				{
					imos[j]++;
					imos[j + 1]--;
				}
			}
			else break;
		}
		for (int k = 0; k <= min(SIZE, i - 1); k++)
		{
			if (vec[i] >= vec[k])continue;
			if (k == 0)
			{
				imos[i]++;
			}
			else
			{
				imos[(i - 1) / k + 1]--;
				imos[(i - 1) / (k + 1) + 1]++;
			}
		}
	}
	for (int i = 0; i < num; i++)imos[i + 1] += imos[i];
	for (int i = 1; i < num; i++)
	{
		if (i != 1)printf(" ");
		printf("%d", imos[i]);
	}
	printf("\n");
}