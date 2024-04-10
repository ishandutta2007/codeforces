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
	sort(v.begin(), v.end());
	int pt = 0;
	for (int i = 1;; i++)
	{
		for (;;)
		{
			if (pt == num)
			{
				printf("%d\n", i);
				return 0;
			}
			if (i <= v[pt++])break;
		}
	}
}