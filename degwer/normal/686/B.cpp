#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
	}
	for (int i = 0; i < num; i++)
	{
		for (int j = 0; j < num - 1; j++)
		{
			if (v[j] > v[j + 1])
			{
				printf("%d %d\n", j + 1, j + 2);
				swap(v[j], v[j + 1]);
			}
		}
	}
}