#include<stdio.h>
#include<vector>
#include<algorithm>
#include<set>
using namespace std;
set<int>pat[300000];
set<int>se;
void dfs(int node)
{
	vector<int>v;
	set<int>::iterator it = se.begin();
	for (;;)
	{
		if (it == se.end())break;
		int t = *it;
		if (pat[node].find(t) == pat[node].end())
		{
			se.erase(it++);
			v.push_back(t);
		}
		else it++;
	}
	for (int i = 0; i < v.size(); i++)dfs(v[i]);
}
int main()
{
	int num, way, gen;
	scanf("%d%d%d", &num, &way, &gen);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		pat[za].insert(zb);
		pat[zb].insert(za);
	}
	for (int i = 1; i < num; i++)se.insert(i);
	dfs(0);
	if (se.size() != 0)
	{
		printf("impossible\n");
		return 0;
	}
	int maxi = num - 1 - pat[0].size();
	int mini = 0;
	for (int i = 1; i < num; i++)se.insert(i);
	for (int i = 1; i < num; i++)
	{
		if (se.find(i) != se.end())
		{
			se.erase(i);
			dfs(i);
			mini++;
		}
	}
	if (mini <= gen&&gen <= maxi)printf("possible\n");
	else printf("impossible\n");
}