#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define SIZE 4000
vector<int>pat[SIZE];
bool flag[SIZE];
int match[SIZE];
void adde(int a, int b)
{
	pat[a].push_back(b);
	pat[b].push_back(a);
}
bool dfs(int node)
{
	flag[node] = true;
	for (int i = 0; i<pat[node].size(); i++)
	{
		int f = pat[node][i], t = match[f];
		if (t == -1 || (!flag[t] && dfs(t)))
		{
			match[node] = f;
			match[f] = node;
			return true;
		}
	}
	return false;
}
int nod;
int bimatch()
{
	int ret = 0;
	fill(match, match + nod, -1);
	for (int i = 0; i<nod; i++)
	{
		if (match[i] == -1)
		{
			fill(flag, flag + nod, false);
			if (dfs(i))ret++;
		}
	}
	return ret;
}
vector<int>dat[100];
vector<int>bun(int t)
{
	vector<int>ret;
	for (int p = 2;; p++)
	{
		if (p*p > t)break;
		for (;;)
		{
			if (t%p == 0)
			{
				t /= p;
				ret.push_back(p);
			}
			else break;
		}
	}
	if (t != 1)ret.push_back(t);
	return ret;
}
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	nod = 4000;
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		dat[i] = bun(z);
	}
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		for (int j = 0; j < dat[za].size(); j++)
		{
			for (int k = 0; k < dat[zb].size(); k++)
			{
				if (dat[za][j] == dat[zb][k])
				{
					adde(za * 40 + j, zb * 40 + k);
				}
			}
		}
	}
	printf("%d\n", bimatch());
}