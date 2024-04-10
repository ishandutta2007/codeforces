#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define SIZE 13000
#define INF 1000000000
typedef pair<int, int>pii;
class maxflow
{
public:
	vector<int>pat[SIZE];
	vector<int>cap[SIZE];
	vector<int>rev[SIZE];
	bool flag[SIZE];
	int dist[SIZE];
	int now[SIZE], ind[SIZE];
	int idx[SIZE];
	int flow;
	int gd;
	void adde(int s, int t, int cp)//d s->tecp
	{
		pat[s].push_back(t);
		pat[t].push_back(s);
		cap[s].push_back(cp);
		cap[t].push_back(0);
		rev[s].push_back(pat[t].size() - 1);
		rev[t].push_back(pat[s].size() - 1);
	}
	void blockflow(int node, int len, int go, int pt)//ubNt[
	{
		if (pt == len)
		{
			if (node != go)return;
			int mini = INF, rr = -1;
			for (int i = 0; i < pt; i++)if (cap[now[i]][ind[i]] < mini)mini = cap[now[i]][ind[i]], rr = i;
			for (int i = 0; i < pt; i++)cap[now[i]][ind[i]] -= mini, cap[pat[now[i]][ind[i]]][rev[now[i]][ind[i]]] += mini;
			flow += mini;//mini==INFLE
			gd = rr;
			return;
		}
		now[pt] = node;
		for (int i = idx[node]; i < pat[node].size(); i++)
		{
			if (dist[pat[node][i]] == dist[node] + 1 && cap[node][i]>0)
			{
				ind[pt] = i;
				blockflow(pat[node][i], len, go, pt + 1);
				if (gd < pt)break;
				else gd = INF;
			}
			idx[node]++;
		}
	}
	void dinic(int st, int go, int num)//dinicASY flowmaxflowl
	{
		flow = 0;
		for (;;)
		{
			queue<pii>que;
			fill(dist, dist + num, INF);
			fill(flag, flag + num, false);
			que.push(make_pair(st, 0));
			for (;;)
			{
				if (que.empty())break;
				pii z = que.front();
				que.pop();
				if (flag[z.first])continue;
				flag[z.first] = true;
				dist[z.first] = z.second;
				for (int i = 0; i < pat[z.first].size(); i++)
				{
					if (dist[pat[z.first][i]]>z.second + 1 && cap[z.first][i] > 0)
					{
						dist[pat[z.first][i]] = z.second + 1;
						que.push(make_pair(pat[z.first][i], z.second + 1));
					}
				}
			}
			if (dist[go] == INF)return;
			gd = INF;
			fill(idx, idx + SIZE, 0);
			blockflow(st, dist[go], go, 0);
		}
	}
	vector<int>getcut(int st, int go, int num)//_imincutst1 0
	{
		dinic(st, go, num);
		vector<int>ret;
		for (int i = 0; i < num; i++)ret.push_back(flag[i]);
		return ret;
	}
};
int ddd[10000];
maxflow gr;
int main()
{
	int num, np, css;
	scanf("%d%d%d", &num, &np, &css);
	int sum = 0;
	for (int i = 0; i < num; i++)scanf("%d", &ddd[i]);
	for (int i = 0; i < num; i++)
	{
		int z;
		scanf("%d", &z);
		if (ddd[i] == 0)gr.adde(0, i + 2, z);
		else gr.adde(i + 2, 1, z);
	}
	for (int i = 0; i < np; i++)
	{
		int zp, zw, zn;
		scanf("%d%d%d", &zp, &zw, &zn);
		sum += zw;
		vector<int>v;
		for (int j = 0; j < zn; j++)
		{
			int z;
			scanf("%d", &z);
			z--;
			v.push_back(z);
		}
		int zf;
		scanf("%d", &zf);
		if (zf)zw += css;
		if (zp == 0)
		{
			gr.adde(0, num + 2 + i, zw);
			for (int j = 0; j < zn; j++)gr.adde(num + 2 + i, v[j] + 2, INF);
		}
		else
		{
			gr.adde(num + 2 + i, 1, zw);
			for (int j = 0; j < zn; j++)gr.adde(v[j] + 2, num + 2 + i, INF);
		}
	}
	gr.dinic(0, 1, num + 2 + np);
	printf("%d\n", sum - gr.flow);
}