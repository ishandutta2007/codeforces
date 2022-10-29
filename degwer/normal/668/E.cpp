#include<stdio.h>
#include<vector>
#include<algorithm>
#include<bitset>
using namespace std;
class graph
{
public:
	int num;
	vector<int>pat[2000];
	vector<int>rpat[2000];
	bool flag[2000];
	vector<int>topo;
	int ban[2000];
	bitset<2048>dat[2000];
	vector<int>np[2000];
	int pt;
	void adde(int a, int b)
	{
		pat[a].push_back(b);
		rpat[b].push_back(a);
	}
	void dfs(int node)
	{
		if (flag[node])return;
		flag[node] = true;
		for (int i = 0; i < pat[node].size(); i++)dfs(pat[node][i]);
		topo.push_back(node);
	}
	void rdfs(int node, int b)
	{
		if (flag[node])return;
		flag[node] = true;
		for (int i = 0; i < rpat[node].size(); i++)rdfs(rpat[node][i], b);
		ban[node] = b;
		dat[b][node] = 1;
	}
	bitset<2048>zb[2000];
	bitset<2048>bi[2000];
	void scc()
	{
		fill(flag, flag + num, false);
		topo.clear();
		for (int i = 0; i < num; i++)if (!flag[i])dfs(i);
		for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)dat[i][j] = 0;
		fill(flag, flag + num, false);
		pt = 0;
		for (int i = 0; i < num; i++)ban[i] = 0;
		for (int i = num - 1; i >= 0; i--)
		{
			if (!flag[topo[i]])
			{
				rdfs(topo[i], pt);
				pt++;
			}
		}
		for (int i = 0; i < num; i++)
		{
			for (int j = 0; j < pat[i].size(); j++)
			{
				np[ban[i]].push_back(ban[pat[i][j]]);
			}
		}
		for (int i = 0; i < pt; i++)for (int j = 0; j < num; j++)zb[i][j] = 0;
		for (int i = 0; i < pt; i++)
		{
			zb[i] |= dat[i];
			for (int j = 0; j < np[i].size(); j++)
			{
				zb[np[i][j]] |= zb[i];
			}
		}
		for (int i = 0; i < num; i++)
		{
			bi[i] = zb[ban[i]];
		}
	}
	vector<int>getdata()
	{
		vector<int>ret;
		for (int i = 0; i < num / 2; i++)
		{
			int t1 = i * 2, t2 = i * 2 + 1;
			if (bi[t1][t2] && bi[t2][t1])ret.push_back(-1);
			else if (bi[t2][t1])ret.push_back(1);
			else if (bi[t1][t2])ret.push_back(2);
			else ret.push_back(0);
		}
		return ret;
	}

};
graph g1, g2;
int ans[1000];
int main()
{
	int num, w1, w2;
	scanf("%d%d%d", &num, &w1, &w2);
	g1.num = g2.num = num * 2;
	for (int i = 0; i < w1; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (za > 0 && zb > 0)
		{
			za--;
			zb--;
			g1.adde(za * 2 + 1, zb * 2);
			g1.adde(zb * 2 + 1, za * 2);
		}
		if (za > 0 && zb < 0)
		{
			za--;
			zb = -zb;
			zb--;
			g1.adde(za * 2 + 1, zb * 2 + 1);
			g1.adde(zb * 2, za * 2);
		}
		if (za < 0 && zb > 0)
		{
			za = -za;
			za--;
			zb--;
			g1.adde(za * 2, zb * 2);
			g1.adde(zb * 2 + 1, za * 2 + 1);
		}
		if (za < 0 && zb < 0)
		{
			za = -za;
			za--;
			zb = -zb;
			zb--;
			g1.adde(za * 2, zb * 2 + 1);
			g1.adde(zb * 2, za * 2 + 1);
		}
	}
	for (int i = 0; i < w2; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		if (za > 0 && zb > 0)
		{
			za--;
			zb--;
			g2.adde(za * 2 + 1, zb * 2);
			g2.adde(zb * 2 + 1, za * 2);
		}
		if (za > 0 && zb < 0)
		{
			za--;
			zb = -zb;
			zb--;
			g2.adde(za * 2 + 1, zb * 2 + 1);
			g2.adde(zb * 2, za * 2);
		}
		if (za < 0 && zb > 0)
		{
			za = -za;
			za--;
			zb--;
			g2.adde(za * 2, zb * 2);
			g2.adde(zb * 2 + 1, za * 2 + 1);
		}
		if (za < 0 && zb < 0)
		{
			za = -za;
			za--;
			zb = -zb;
			zb--;
			g2.adde(za * 2, zb * 2 + 1);
			g2.adde(zb * 2, za * 2 + 1);
		}
	}
	g1.scc();
	g2.scc();
	vector<int>v1 = g1.getdata(), v2 = g2.getdata();
	bool f1 = true, f2 = true;
	for (int i = 0; i < num; i++)
	{
		if (v1[i] == -1)f1 = false;
		if (v2[i] == -1)f2 = false;
	}/*
	for (int i = 0; i < num*2; i++)
	{
		printf("%d  ", g1.ban[i]);
		for (int j = 0; j < num*2; j++)
		{
			printf("%d ", int(g1.bi[i][j]));
		}
		printf("\n");
	}
	for (int i = 0; i < num * 2; i++)
	{
		printf("%d  ", g2.ban[i]);
		for (int j = 0; j < num * 2; j++)
		{
			printf("%d ", int(g2.bi[i][j]));
		}
		printf("\n");
	}
	for (int i = 0; i < num; i++)
	{
		printf("%d   %d\n", v1[i], v2[i]);
	}*/
	if ((!f1) && (!f2))
	{
		printf("SIMILAR\n");
		return 0;
	}
	if (!f2)
	{
		for (int i = 0; i < num; i++)
		{
			ans[i] = g1.ban[i * 2]>g1.ban[i * 2 + 1];
		}
	}
	else if (!f1)
	{
		for (int i = 0; i < num; i++)
		{
			ans[i] = g2.ban[i * 2]>g2.ban[i * 2 + 1];
		}
	}
	else
	{
		if (v1 != v2)
		{
			for (int i = 0; i < num; i++)
			{
				if (v1[i] != v2[i])
				{
					if (v1[i] == 1)
					{
						g2.adde(i * 2 + 1, i * 2);
						g2.scc();
						for (int j = 0; j < num; j++)
						{
							ans[j] = g2.ban[j * 2]>g2.ban[j * 2 + 1];
						}
						break;
					}
					else if (v1[i] == 2)
					{
						g2.adde(i * 2, i * 2 + 1);
						g2.scc();
						for (int j = 0; j < num; j++)
						{
							ans[j] = g2.ban[j * 2]>g2.ban[j * 2 + 1];
						}
						break;
					}
					else if (v2[i] == 1)
					{
						g1.adde(i * 2 + 1, i * 2);
						g1.scc();
						for (int j = 0; j < num; j++)
						{
							ans[j] = g1.ban[j * 2]>g1.ban[j * 2 + 1];
						}
						break;
					}
					else
					{
						g1.adde(i * 2, i * 2 + 1);
						g1.scc();
						for (int j = 0; j < num; j++)
						{
							ans[j] = g1.ban[j * 2]>g1.ban[j * 2 + 1];
						}
						break;
					}
				}
			}
		}
		else
		{
		//	g1.scc();
		//	g2.scc();
			bool f = false;
			for (int i = 0; i < num * 2; i++)
			{
				for (int j = 0; j < num * 2; j++)
				{
					if (v1[i / 2] != 0 || v1[j / 2] != 0)continue;
					if (g1.bi[i][j] != g2.bi[i][j])
					{
						//printf("%d %d\n", i, j);
						f = true;
						if (g1.bi[i][j] != 0)
						{
							if (i % 2 == 0)g2.adde(i, i + 1);
							else g2.adde(i, i - 1);
							if (j % 2 == 0)g2.adde(j + 1, j);
							else g2.adde(j - 1, j);
							g2.scc();
							for (int k = 0; k < num; k++)
							{
								ans[k] = g2.ban[k * 2]>g2.ban[k * 2 + 1];
							}
						}
						else
						{
							if (i % 2 == 0)g1.adde(i, i + 1);
							else g1.adde(i, i - 1);
							if (j % 2 == 0)g1.adde(j + 1, j);
							else g1.adde(j - 1, j);
							g1.scc();
							for (int k = 0; k < num; k++)
							{
								ans[k] = g1.ban[k * 2]>g1.ban[k * 2 + 1];
							}
						}
						break;
					}
				}
				if (f)break;
			}
			if (!f)
			{
				printf("SIMILAR\n");
				return 0;
			}
		}
	}
	for (int i = 0; i < num; i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ans[i]);
	}
	printf("\n");
}