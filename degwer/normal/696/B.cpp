#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 100000//_
#define LOG 20
#define ROOT 0
class FOREST
{
public:
	int num;//_
	vector<int>pat[SIZE];
	vector<int>ko[SIZE];
	bool flag[SIZE];
	int subsiz[SIZE];//TCY
	void adde(int s, int t)//s-t
	{
		pat[s].push_back(t);
		pat[t].push_back(s);
	}
	void initdfs(int node)
	{
		if (flag[node])return;
		flag[node] = true;
		subsiz[node] = 1;
		for (int i = 0; i < pat[node].size(); i++)
		{
			if (!flag[pat[node][i]])
			{
				initdfs(pat[node][i]);
				ko[node].push_back(pat[node][i]);
				subsiz[node] += subsiz[pat[node][i]];
			}
		}
	}
	double ans[SIZE];
	void dfs(int node, double d)
	{
		ans[node] = d + 1.0;
		for (int i = 0; i < ko[node].size(); i++)
		{
			dfs(ko[node][i], d + 1 + double(subsiz[node] - subsiz[ko[node][i]] - 1) / 2.0);
		}
	}
};
FOREST tree;
int main()
{
	int num;
	scanf("%d", &num);
	for (int i = 1; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		tree.adde(i, z);
	}
	tree.initdfs(0);
	tree.dfs(0, 0.0);
	for (int i = 0; i < num; i++)
	{
		printf("%lf ", tree.ans[i]);
	}
	printf("\n");
}