#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 200000//_
#define LOG 20
#define ROOT 0
class FOREST
{
public:
	int num;//_
	vector<int>pat[SIZE];
	vector<int>ko[SIZE];
	int depth[SIZE];//[
	int ord[SIZE];//ord
	int fin[SIZE];//fin 
	int rord[SIZE];//ordtz
	bool flag[SIZE];
	int subsiz[SIZE];//TCY
	int par[SIZE];
	int lcapar[LOG][SIZE];
	bool isroot[SIZE];
	int ordpt;
	void adde(int s, int t)//s-t
	{
		pat[s].push_back(t);
		pat[t].push_back(s);
	}
	void initdfs(int node, int d)
	{
		if (flag[node])return;
		flag[node] = true;
		subsiz[node] = 1;
		rord[ordpt] = node;
		ord[node] = ordpt++;
		depth[node] = d;
		for (int i = 0; i < pat[node].size(); i++)
		{
			if (!flag[pat[node][i]])
			{
				initdfs(pat[node][i], d + 1);
				ko[node].push_back(pat[node][i]);
				subsiz[node] += subsiz[pat[node][i]];
				par[pat[node][i]] = node;
				lcapar[0][pat[node][i]] = node;
			}
		}
		fin[node] = ordpt - 1;
	}
	void lcainit(int n)//_ V_
	{
		num = n;
		ordpt = 0;
		for (int i = 0; i < num; i++)
		{
			if (!flag[i])
			{
				isroot[i] = true;
				par[i] = lcapar[0][i] = i;
				initdfs(i, 0);
			}
			else isroot[i] = false;
		}
		for (int i = 1; i < LOG; i++)
		{
			for (int j = 0; j < num; j++)
			{
				lcapar[i][j] = lcapar[i - 1][lcapar[i - 1][j]];
			}
		}
	}
	int lca(int a, int b)//-1
	{
		if (lcapar[LOG - 1][a] != lcapar[LOG - 1][b])return -1;
		if (depth[a] > depth[b])swap(a, b);
		for (int i = LOG - 1; i >= 0; i--)
		{
			if (depth[a] <= depth[b] - (1 << i))
			{
				b = lcapar[i][b];
			}
		}
		if (a == b)return a;
		for (int i = LOG - 1; i >= 0; i--)
		{
			if (lcapar[i][a] != lcapar[i][b])
			{
				a = lcapar[i][a];
				b = lcapar[i][b];
			}
		}
		return par[a];
	}
};
class GRAPH
{
public:
	int num;//_
	vector<int>pat[SIZE];
	vector<int>rev[SIZE];
	vector<int>etype[SIZE];//1: 2:t -1: -2:t [v
	int ord[SIZE];
	int low[SIZE];
	int ordpt;
	bool flag[SIZE];
	bool isroot[SIZE];
	void undirectedadde(int s, int t)//s-t
	{
		pat[s].push_back(t);
		pat[t].push_back(s);
		rev[s].push_back(pat[t].size() - 1);
		rev[t].push_back(pat[s].size() - 1);
		etype[s].push_back(0);
		etype[t].push_back(0);
	}
	void lowdfs(int node)
	{
		if (flag[node])return;
		flag[node] = true;
		ord[node] = ordpt++;
		for (int i = 0; i < pat[node].size(); i++)
		{
			if (!flag[pat[node][i]])
			{
				etype[node][i] = 1;
				etype[pat[node][i]][rev[node][i]] = 2;
				lowdfs(pat[node][i]);
			}
			else
			{
				if (etype[node][i] == 0)
				{
					etype[node][i] = -1;
					etype[pat[node][i]][rev[node][i]] = -2;
				}
			}
		}
	}
	void lowcalc(int node)
	{
		low[node] = ord[node];
		for (int i = 0; i < pat[node].size(); i++)
		{
			if (etype[node][i] == 1)
			{
				lowcalc(pat[node][i]);
				low[node] = min(low[node], low[pat[node][i]]);
			}
			if (etype[node][i] == -1)
			{
				low[node] = min(low[node], ord[pat[node][i]]);
			}
		}
	}
	bool isbridge(int node, int k)//node-pat[node][k]
	{
		if (etype[node][k] <= 0)return false;
		if (etype[node][k] == 2)
		{
			int t = pat[node][k];
			k = rev[node][k];
			node = t;
		}
		if (low[pat[node][k]] > ord[node])return true;
		else return false;
	}
	bool isartic(int node)//node_
	{
		if (isroot[node])
		{
			int cnt = 0;
			for (int i = 0; i < pat[node].size(); i++)if (etype[node][i] == 1)cnt++;
			if (cnt >= 2)return true;
			else return false;
		}
		else
		{
			for (int i = 0; i < pat[node].size(); i++)
			{
				if (etype[node][i] == 1)
				{
					if (low[pat[node][i]] >= ord[node])return true;
				}
			}
			return false;
		}
	}
	int tpt;
	int tot[SIZE];//Otm[h->Vm[h
	FOREST newfor;
	void maketree(int node, int d)
	{
		tot[node] = d;
		for (int i = 0; i < pat[node].size(); i++)
		{
			if (etype[node][i] == 1)
			{
				if (isbridge(node, i))
				{
					tpt++;
					newfor.adde(d, tpt);
					maketree(pat[node][i], tpt);
				}
				else maketree(pat[node][i], d);
			}
		}
	}
	void lowinit(int n)//_
	{
		num = n;
		ordpt = 0;
		fill(flag, flag + SIZE, false);
		for (int i = 0; i < num; i++)
		{
			if (!flag[i])
			{
				isroot[i] = true;
				lowdfs(i);
				lowcalc(i);
			}
			else isroot[i] = false;
		}
		//dAX tpt_
		tpt = 0;
		for (int i = 0; i < num; i++)
		{
			if (isroot[i])
			{
				maketree(i, tpt);
				tpt++;
			}
		}
		//
	}
};
GRAPH gr;
int imos1[SIZE], imos2[SIZE];
void dfs(int node)
{
	for (int i = 0; i < gr.newfor.ko[node].size(); i++)
	{
		dfs(gr.newfor.ko[node][i]);
		imos1[node] += imos1[gr.newfor.ko[node][i]];
		imos2[node] += imos2[gr.newfor.ko[node][i]];
	}
}
int main()
{
	int num, way, query;
	scanf("%d%d%d", &num, &way, &query);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		gr.undirectedadde(za, zb);
	}
	gr.lowinit(num);
	gr.newfor.lcainit(gr.tpt);
	/*for (int i = 0; i < num; i++)
	{
		printf("%d %d\n", i, gr.tot[i]);
	}
	for (int i = 0; i < gr.tpt; i++)
	{
		printf(" %d %d %d\n", i, gr.newfor.depth[i], gr.newfor.lcapar[0][i]);
	}*/
	for (int i = 0; i < query; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		int l = gr.newfor.lca(gr.tot[za], gr.tot[zb]);
		if (l == -1)
		{
			printf("NO\n");
			return 0;
		}
		//printf("%d\n", l);
		imos1[gr.tot[za]]++;
		imos2[gr.tot[zb]]++;
		imos1[l]--;
		imos2[l]--;
	}
	for (int i = 0; i < gr.tpt; i++)
	{
		if (gr.newfor.isroot[i])dfs(i);
	}
	for (int i = 0; i < gr.tpt; i++)
	{
		if (imos1[i] > 0 && imos2[i]>0)
		{
			printf("No\n");
			return 0;
		}
	}
	printf("Yes\n");
}