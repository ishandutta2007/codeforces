#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define SIZE 200
#define INF 1000000
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
typedef pair<pii, int>pi3;
class gomoryhutree
{
public:
	vector<int>now[SIZE];
	vector<pi3>calc(vector<pi3>ed, int num)//((s,t),cap)SGomory-Hu treeW
	{
		for (int i = 0; i < num; i++)now[0].push_back(i);
		int pt = 1;
		vector<pi3>ret;
		for (int i = 0; i < num; i++)
		{
			for (;;)
			{
				if (now[i].size() == 1)break;
				bool x[SIZE];
				fill(x, x + num, false);
				for (int j = 0; j < now[i].size(); j++)x[now[i][j]] = true;
				maxflow gr;
				for (int j = 0; j < ed.size(); j++)gr.adde(ed[j].first.first, ed[j].first.second, ed[j].second), gr.adde(ed[j].first.second, ed[j].first.first, ed[j].second);
				for (int j = 0; j < pt; j++)if (i != j)for (int k = 0; k < now[j].size() - 1; k++)gr.adde(now[j][k], now[j][k + 1], INF), gr.adde(now[j][k + 1], now[j][k], INF);
				for (int j = 0; j < ret.size(); j++)if (ret[j].first.first != i&&ret[j].first.second != i)gr.adde(now[ret[j].first.first][0], now[ret[j].first.second][0], INF), gr.adde(now[ret[j].first.second][0], now[ret[j].first.first][0], INF);
				vector<int>cut = gr.getcut(now[i][0], now[i][1], num);
				vector<int>n1, n2;
				for (int j = 0; j < now[i].size(); j++)
				{
					if (cut[now[i][j]])n1.push_back(now[i][j]);
					else n2.push_back(now[i][j]);
				}
				for (int j = 0; j < ret.size(); j++)
				{
					if (ret[j].first.second == i)swap(ret[j].first.first, ret[j].first.second);
					if (ret[j].first.first == i&&cut[now[ret[j].first.second][0]] == 0)ret[j].first.first = pt;
				}
				ret.push_back(make_pair(make_pair(i, pt), gr.flow));
				now[i] = n1, now[pt++] = n2;
			}
		}
		for (int i = 0; i < ret.size(); i++)ret[i].first.first = now[ret[i].first.first][0], ret[i].first.second = now[ret[i].first.second][0];
		return ret;
	}
};
gomoryhutree gom;
class unionfind
{
public:
	int par[SIZE];
	int ran[SIZE];
	int ren[SIZE];
	void init()
	{
		for (int i = 0; i<SIZE; i++)
		{
			par[i] = i;
			ran[i] = 0;
			ren[i] = 1;
		}
	}
	int find(int a)
	{
		if (a == par[a])return a;
		else return par[a] = find(par[a]);
	}
	void unite(int a, int b)
	{
		a = find(a);
		b = find(b);
		if (a == b)return;
		if (ran[a]>ran[b])
		{
			par[b] = a;
			ren[a] += ren[b];
		}
		else
		{
			par[a] = b;
			ren[b] += ren[a];
		}
		if (ran[a] == ran[b])ran[b]++;
	}
};
unionfind uf;
vector<int>calc(vector<int>vec, vector<pi3>ed)
{
	if (vec.size() == 1)return vec;
	int mini = INF, rr;
	for (int i = 0; i < ed.size(); i++)if (ed[i].second < mini)mini = ed[i].second, rr = i;
	uf.init();
	for (int i = 0; i < ed.size(); i++)if (rr != i)uf.unite(ed[i].first.first, ed[i].first.second);
	vector<int>v1, v2;
	vector<pi3>e1, e2;
	for (int i = 0; i < vec.size(); i++)
	{
		if (uf.find(vec[i]) == uf.find(ed[rr].first.first))v1.push_back(vec[i]);
		else v2.push_back(vec[i]);
	}
	for (int i = 0; i < ed.size(); i++)
	{
		if (rr == i)continue;
		if (uf.find(ed[i].first.first) == uf.find(ed[rr].first.first))e1.push_back(ed[i]);
		else e2.push_back(ed[i]);
	}
	vector<int>r1 = calc(v1, e1), r2 = calc(v2, e2);
	for (int i = 0; i < r2.size(); i++)r1.push_back(r2[i]);
	return r1;
}
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	vector<pi3>ed;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		ed.push_back(make_pair(make_pair(za, zb), zc));
	}
	vector<pi3>vec = gom.calc(ed, num);
	int sum = 0;
	for (int i = 0; i < num - 1; i++)sum += vec[i].second;
	printf("%d\n", sum);
	vector<int>v;
	for (int i = 0; i < num; i++)v.push_back(i);
	vector<int>ret = calc(v, vec);
	for (int i = 0; i < ret.size(); i++)
	{
		if (i != 0)printf(" ");
		printf("%d", ret[i] + 1);
	}
	printf("\n");
}