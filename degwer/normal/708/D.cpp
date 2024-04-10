#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
#define SIZE 102
typedef long long ll;
#define INF 2000000000000LL
vector<int>pat[SIZE];
vector<ll>cap[SIZE];
vector<ll>cost[SIZE];
vector<int>rev[SIZE];
void adde(int a, int b, ll cp, ll cst)
{
	pat[a].push_back(b);
	pat[b].push_back(a);
	cap[a].push_back(cp);
	cap[b].push_back(0);
	cost[a].push_back(cst);
	cost[b].push_back(-cst);
	rev[a].push_back(pat[b].size() - 1);
	rev[b].push_back(pat[a].size() - 1);
}
ll dist[SIZE];
ll nd[SIZE];
typedef pair<ll, ll>pii;
int frv[SIZE], fre[SIZE];
int nod;
ll mincostflow(int st, int go, ll gen)
{
	ll ret = 0;
	fill(nd, nd + SIZE, 0);
	for (;;)
	{
		if (gen == 0)break;
		priority_queue<pii>que;
		que.push(make_pair(0, st));
		fill(dist, dist + nod, INF);
		for (;;)
		{
			if (que.empty())break;
			pii zan = que.top();
			que.pop();
			if (dist[zan.second]<-zan.first)continue;
			dist[zan.second] = -zan.first;
			for (int i = 0; i<pat[zan.second].size(); i++)
			{
				if (cap[zan.second][i]>0 && dist[pat[zan.second][i]]>dist[zan.second] + cost[zan.second][i] + nd[zan.second] - nd[pat[zan.second][i]])
				{
					dist[pat[zan.second][i]] = dist[zan.second] + cost[zan.second][i] + nd[zan.second] - nd[pat[zan.second][i]];
					frv[pat[zan.second][i]] = zan.second;
					fre[pat[zan.second][i]] = i;
					que.push(make_pair(-dist[pat[zan.second][i]], pat[zan.second][i]));
				}
			}
		}
		//if (dist[go] == INF)return -1;
		for (int i = 0; i<nod; i++)nd[i] += dist[i];
		ll fl = gen;
		int now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			now = frv[now];
			fl = min(fl, cap[now][t]);
		}
		gen -= fl;
		ret += fl*nd[go];
		now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			int nx = now;
			now = frv[now];
			cap[now][t] -= fl;
			cap[nx][rev[now][t]] += fl;
		}
	}
	return ret;
}
int deg[102];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	nod = num + 2;
	int ans = 0;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		za++;
		zb++;
		deg[za] -= zd;
		deg[zb] += zd;
		if (zc >= zd)
		{
			adde(zb, za, zc - zd, 1);
			adde(zb, za, INF, 2);
			adde(za, zb, zd, 1);
		}
		else
		{
			adde(zb, za, INF, 2);
			adde(za, zb, zd - zc, 0);
			adde(za, zb, zc, 1);
			ans += zd - zc;
		}
	}
	ll s1 = 0;
	for (int i = 2; i <= num + 1; i++)
	{
		if (deg[i] > 0)adde(i, 1, deg[i], 0), s1 += deg[i];
		else adde(0, i, -deg[i], 0);
	}
	adde(1, 0, INF, 0);
	adde(2, num + 1, INF, 0);
	ll r = mincostflow(0, 1, s1);
	printf("%I64d\n", ans + r);
}