#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int main()
{
	int num;
	scanf("%d", &num);
	vector<vector<int> >ans;
	vector<int>rem;
	if (num == 3)
	{
		vector<int>v;
		v.push_back(0);
		v.push_back(1);
		v.push_back(2);
		ans.push_back(v);
		ans.push_back(v);
	}
	else if (num % 4 == 0)
	{
		for (int i = 0; i < num; i++)
		{
			vector<int>v;
			v.push_back(i);
			v.push_back((i + num / 4) % num);
			v.push_back((i + num / 2) % num);
			ans.push_back(v);
		}
		for (int i = 1; i <= num / 4 - 1; i++)rem.push_back(i);
		for (int i = num / 4 + 1; i <= num / 2 - 1; i++)rem.push_back(i);
	}
	else if (num % 4 == 1)
	{
		for (int i = 1; i <= num / 2; i++)rem.push_back(i);
	}
	else if (num % 4 == 2)
	{
		for (int i = 0; i < num; i++)
		{
			vector<int>v;
			v.push_back(i);
			v.push_back((i + 1) % num);
			v.push_back((i + num / 2) % num);
			ans.push_back(v);
		}
		for (int i = 0; i < num / 2; i++)
		{
			vector<int>v;
			v.push_back(i);
			v.push_back((i + 1) % num);
			v.push_back((i + num / 2) % num);
			v.push_back((i + num / 2 + 1) % num);
			ans.push_back(v);
		}
		for (int i = 2; i <= num / 2 - 2; i++)rem.push_back(i);
	}
	else
	{
		for (int i = 0; i < num; i++)
		{
			vector<int>v;
			v.push_back(i);
			v.push_back((i + 1) % num);
			v.push_back((i + 3) % num);
			ans.push_back(v);
			ans.push_back(v);
		}
		for (int i = 4; i <= num / 2; i++)rem.push_back(i);
	}
	if (rem.size() % 2 != 0)abort();
	for (int i = 0; i < rem.size() / 2; i++)
	{
		int x = rem[i * 2], y = rem[i * 2 + 1];
		for (int j = 0; j < num; j++)
		{
			vector<int>v;
			v.push_back(j);
			v.push_back((j + y) % num);
			v.push_back((j + num + y - x) % num);
			v.push_back((j + num - x) % num);
			ans.push_back(v);
		}
	}
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++)
	{
		printf("%d", ans[i].size());
		for (int j = 0; j < ans[i].size(); j++)
		{
			printf(" %d", ans[i][j] + 1);
		}
		printf("\n");
	}
}