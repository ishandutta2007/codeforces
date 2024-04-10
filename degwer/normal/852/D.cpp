#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
#define SIZE 1300
vector<int>pat[SIZE];
vector<int>cap[SIZE];
vector<int>rev[SIZE];
void adde(int a, int b, int c)
{
	pat[a].push_back(b);
	pat[b].push_back(a);
	cap[a].push_back(c);
	cap[b].push_back(0);
	rev[a].push_back(pat[b].size() - 1);
	rev[b].push_back(pat[a].size() - 1);
}
int frv[SIZE], fre[SIZE];
bool flag[SIZE];
void dfs(int node)
{
	if (flag[node])return;
	flag[node] = true;
	//printf("  %d\n", node);
	for (int i = 0; i<pat[node].size(); i++)
	{
		if (cap[node][i]>0 && (!flag[pat[node][i]]))
		{
			frv[pat[node][i]] = node;
			fre[pat[node][i]] = i;
			dfs(pat[node][i]);
		}
	}
}
int flow=0;
void push(int st, int go)
{
	int mini = 1000000000;
	int now = go;
	for (;;)
	{
		if (now == st)break;
		int t = fre[now];
		now = frv[now];
		mini = min(mini, cap[now][t]);
	}
	flow++;
	now = go;
	for (;;)
	{
		if (now == st)break;
		int t = fre[now];
		int nx = now;
		now = frv[now];
		cap[now][t] -= mini;
		cap[nx][rev[now][t]] += mini;
	}
}
int dist[600][600];
typedef pair<int, int>pii;
typedef pair<int, pii>pi3;
int main()
{
	int num, way, nin, mok;
	scanf("%d%d%d%d", &num, &way, &nin, &mok);
	for (int i = 0; i < nin; i++)
	{
		int z;
		scanf("%d", &z);
		z--;
		adde(1298, z, 1);
	}
	for (int i = 0; i < num; i++)adde(i + num, 1299, 1);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)dist[i][j] = 1000000000 * (i != j);
	for (int i = 0; i < way;i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		dist[za][zb] = min(dist[za][zb], zc);
		dist[zb][za] = min(dist[zb][za], zc);
	}
	vector<pi3>vec;
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)for (int k = 0; k < num; k++)dist[j][k] = min(dist[j][k], dist[j][i] + dist[i][k]);
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)if (dist[i][j] < 1000000000)vec.push_back(make_pair(dist[i][j], make_pair(i, j)));
	sort(vec.begin(), vec.end());
	dfs(1298);
	for (int p = 0; p < vec.size(); p++)
	{
		int s = vec[p].second.first, t = vec[p].second.second;
		//printf("%d %d  %d\n", s, t,vec[p].first);
		adde(s, t + num, 1);
		if (flag[s])flag[s] = false, dfs(s);
		if (flag[1299])
		{
			push(1298, 1299);
			fill(flag, flag + 1300, false);
			dfs(1298);
			//printf("aaa\n");
		}
		if (flow == mok)
		{
			printf("%d\n", vec[p].first);
			return 0;
		}
	}
	printf("-1\n");
}