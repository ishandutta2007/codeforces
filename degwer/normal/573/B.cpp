#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int a1[100000], a2[100000];
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
	int now = 0;
	for (int i = 0; i < num; i++)
	{
		now = min(now + 1, vec[i]);
		a1[i] = now;
	}
	now = 0;
	for (int i = num - 1; i >= 0; i--)
	{
		now = min(now + 1, vec[i]);
		a2[i] = now;
	}
	int maxi = 0;
	for (int i = 0; i < num; i++)maxi = max(maxi, min(a1[i], a2[i]));
	printf("%d\n", maxi);
}