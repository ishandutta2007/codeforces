#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
vector<int>vec;
int count(int t)
{
	if (t == 0 || t == vec.size() - 1)return 0;
	if (t % 2 == 1)return int(vec[t] < vec[t + 1]) + int(vec[t] < vec[t - 1]);
	else return int(vec[t] > vec[t + 1]) + int(vec[t]>vec[t - 1]);
}
int main()
{
	int num;
	scanf("%d", &num);
	vec.push_back(1000000000);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		vec.push_back(z);
	}
	if (num % 2 == 1)vec.push_back(1000000000);
	else vec.push_back(0);
	int t = 0;
	vector<int>dis;
	for (int i = 1; i <= num; i++)
	{
		t += count(i);
		if (count(i) != 2)dis.push_back(i);
	}
	if (dis.size() >= 10)
	{
		printf("0\n");
		return 0;
	}
	set<pair<int,int> >se;
	for (int i = 1; i <= num; i++)
	{
		if (count(i) != 2)
		{
			for (int j = i - 1; j <= i + 1; j++)
			{
				if (j == 0 || j == num + 1)continue;
				for (int k = 1; k <= num; k++)
				{
					swap(vec[j], vec[k]);
					bool f = true;
					for (int l = 0; l < dis.size(); l++)
					{
						if (count(dis[l]) != 2)f = false;
					}
					if (count(j) != 2)f = false;
					if (count(k) != 2)f = false;
					if (f)se.insert(make_pair(min(j, k), max(j, k)));
					swap(vec[j], vec[k]);
				}
			}
			printf("%d\n", se.size());
			return 0;
		}
	}
}