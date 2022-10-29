#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
vector<int>pat[100000];
vector<int>rev[100000];
vector<bool>flag[100000];
int pt[100000];
void adde(int a, int b)//Ot
{
	pat[a].push_back(b);
	pat[b].push_back(a);
	rev[a].push_back(pat[b].size() - 1);
	rev[b].push_back(pat[a].size() - 1);
	flag[a].push_back(false);
	flag[b].push_back(false);
}
vector<int>euler;
void calceuler(int node)//eulerHeuler n_
{
	for (;;)
	{
		if (pt[node] == pat[node].size())break;
		if (!flag[node][pt[node]])
		{
			flag[node][pt[node]] = true;
			flag[pat[node][pt[node]]][rev[node][pt[node]]] = true;
			pt[node]++;
			calceuler(pat[node][pt[node] - 1]);
		}
		else pt[node]++;
	}
	euler.push_back(node);
}
int deg[100000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		adde(za, zb);
		deg[za]++;
		deg[zb]++;
	}
	vector<int>v;
	for (int i = 0; i < num; i++)
	{
		if (deg[i] % 2 == 1)v.push_back(i);
	}
	for (int i = 0; i < v.size() / 2; i++)
	{
		adde(v[i * 2], v[i * 2 + 1]);
		way++;
	}
	if (way % 2 == 1)adde(0, 0);
	calceuler(0);
	euler.pop_back();
	printf("%d\n", euler.size());
	for (int i = 0; i < euler.size(); i++)
	{
		if (i % 2 == 0)printf("%d %d\n", euler[i] + 1, euler[(i + 1) % euler.size()] + 1);
		else printf("%d %d\n", euler[(i + 1) % euler.size()] + 1, euler[i] + 1);
	}
}