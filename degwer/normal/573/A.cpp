#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (a == 0)return b;
	for (;;)
	{
		if (a > b)swap(a, b);
		b %= a;
		if (b == 0)return a;
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	vector<int>v;
	int g = 0;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
		g = gcd(g, z);
	}
	for (int i = 0; i < num; i++)v[i] /= g;
	for (int i = 0; i < num; i++)
	{
		for (;;)
		{
			if (v[i] % 2 != 0)break;
			v[i] /= 2;
		}
		for (;;)
		{
			if (v[i] % 3 != 0)break;
			v[i] /= 3;
		}
		if (v[i] != 1)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}