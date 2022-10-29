#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
#include<queue>
using namespace std;
vector<int>ret;
bool isok(vector<int>v, int med)
{
	set<int>se;
	priority_queue<int>que;
	for (int i = 0; i < v.size(); i++)
	{
		for (;;)
		{
			if (v[i] > med)v[i] /= 2;
			else break;
		}
		que.push(v[i]);
	}
	ret.clear();
	for (;;)
	{
		if(que.empty())return true;
		int z = que.top();
		que.pop();
		if (se.find(z) == se.end())
		{
			ret.push_back(z);
			se.insert(z);
		}
		else
		{
			if (z == 1)return false;
			que.push(z / 2);
		}
	}
}
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
	int beg = 1, end = 1000000000;
	for (;;)
	{
		if (beg == end)break;
		int med = (beg + end) / 2;
		if (isok(vec, med))end = med;
		else beg = med + 1;
	}
	isok(vec, beg);
	for (int i = 0; i < num; i++)printf("%d ", ret[i]); printf("\n");
}