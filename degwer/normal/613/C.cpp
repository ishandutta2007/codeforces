#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int gcd(int a, int b)
{
	if (a == 0)return b;
	for (;;)
	{
		if (a < b)swap(a, b);
		a %= b;
		if (a == 0)return b;
	}
}
int main()
{
	int num;
	scanf("%d", &num);
	int cnt = 0;
	int g = 0;
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		v.push_back(z);
		if (z % 2 == 1)cnt++;
		g = gcd(g, z);
	}
	vector<int>ans;
	if (cnt >= 2)
	{
		printf("0\n");
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < v[i]; j++)ans.push_back(i);
		}
	}
	else if (cnt == 1)
	{
		printf("%d\n",g);
		vector<int>z;
		int rr = -1;
		for (int i = 0; i < num; i++)
		{
			if (v[i] % 2 == 1)rr = i;
			for (int j = 0; j < v[i] / (g*2); j++)
			{
				z.push_back(i);
			}
		}
		for (int i = 0; i < g; i++)
		{
			for (int j = 0; j < z.size(); j++)ans.push_back(z[j]);
			ans.push_back(rr);
			for (int j = z.size() - 1; j >= 0; j--)ans.push_back(z[j]);
		}

	}
	else
	{
		printf("%d\n", g);
		vector<int>z;
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < v[i] / g; j++)
			{
				z.push_back(i);
			}
		}
		for (int i = 0; i < g / 2; i++)
		{
			for (int j = 0; j < z.size(); j++)ans.push_back(z[j]);
			for (int j = z.size()-1; j >=0; j--)ans.push_back(z[j]);
		}
	}
	for (int i = 0; i < ans.size(); i++)printf("%c", ans[i] + 'a');
	printf("\n");
}