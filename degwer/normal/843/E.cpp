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
	vector<int>sus[SIZE];
	bool flag[SIZE];
	int dist[SIZE];
	int now[SIZE], ind[SIZE];
	int idx[SIZE];
	int flow;
	int gd;
	void adde(int s, int t, int cp, int id)//d s->tecp
	{
		pat[s].push_back(t);
		pat[t].push_back(s);
		cap[s].push_back(cp);
		cap[t].push_back(0);
		rev[s].push_back(pat[t].size() - 1);
		rev[t].push_back(pat[s].size() - 1);
		sus[s].push_back(id);
		sus[t].push_back(-1);
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
maxflow gr1,gr2;
int acap[2000],aflow[2000];
int main()
{
	int num,way,st,go;
	scanf("%d%d%d%d",&num,&way,&st,&go);
	st--,go--;
	for(int i=0;i<way;i++)
	{
		int za,zb,zc;
		scanf("%d%d%d",&za,&zb,&zc);
		za--,zb--;
		if(zc==0)gr1.adde(za,zb,INF,-1);
		else
		{
			gr1.adde(zb,za,INF,-1);
			gr1.adde(za,zb,1,i);
			gr2.adde(za,zb,INF,i);
			gr2.adde(num,zb,1,-1);
			gr2.adde(za,num+1,1,-1);
		}
	}
	vector<int>iss=gr1.getcut(st,go,num);
	gr2.dinic(num,num+1,num+2);
	printf("%d\n",gr1.flow);
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<gr2.pat[i].size();j++)
		{
			if(gr2.sus[i][j]!=-1)
			{
				aflow[gr2.sus[i][j]]=1+INF-gr2.cap[i][j];
				acap[gr2.sus[i][j]]=aflow[gr2.sus[i][j]]+1;
			}
		}
	}
	for(int i=0;i<num;i++)
	{
		for(int j=0;j<gr1.pat[i].size();j++)
		{
			if(gr1.sus[i][j]!=-1)
			{
				if(iss[i]==1&&iss[gr1.pat[i][j]]==0)
				{
					acap[gr1.sus[i][j]]--;
				}
			}
		}
	}
	for(int i=0;i<way;i++)printf("%d %d\n",aflow[i],max(1,acap[i]));
}