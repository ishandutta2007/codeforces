#include<stdio.h>
#include<vector>
#include<algorithm>
#include<math.h>
#include<stdlib.h>
using namespace std;
#define SIZE 50
vector<int>pat[SIZE];
vector<int>cap[SIZE];
vector<int>rev[SIZE];
//vector<bool>ise[SIZE];
//vector<bool>isvl[SIZE];
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
int nod;
int gen;
int maxflow(int st, int go)
{
	int ret = 0;
	for (;;)
	{
		fill(flag, flag + nod, false);
		dfs(st);
		if (!flag[go])return ret;
		int mini = 1000000000;
		int now = go;
		for (;;)
		{
			if (now == st)break;
			int t = fre[now];
			now = frv[now];
			mini = min(mini, cap[now][t]);
		}
		ret += mini;
		if (ret > gen)return ret;
		//flow++;
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
}
typedef pair<int, int>pii;
typedef pair<pii, int>pi3;
typedef long double ld;
int main()
{
	int num, way;
	scanf("%d%d%d", &num, &way, &gen);
	nod = num;
	vector<pi3>vec;
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--;
		zb--;
		vec.push_back(make_pair(make_pair(za, zb), zc));
	}
	ld beg = 0.0, end = 10000000000.0;
	for (int p = 0; p < 120; p++)
	{
		ld med = (beg + end) / 2.0;
		for (int i = 0; i < num; i++)
		{
			pat[i].clear();
			cap[i].clear();
			rev[i].clear();
		}
		for (int i = 0; i < vec.size(); i++)
		{
			adde(vec[i].first.first, vec[i].first.second, int(min(ld(gen),ld(floor(ld(vec[i].second)/(ld(med)/ld(gen)))))));
		}
		int t = maxflow(0, num - 1);
		if (t >= gen)beg = med;
		else end = med;
	}
	printf("%lf\n", double(beg));
}