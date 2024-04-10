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
	int mini = 1000000000;
	for (int i = 0; i < num / 2; i++)
	{
		mini = min(mini, v[i + num / 2] - v[i]);
	}
	printf("%d\n", mini);
}