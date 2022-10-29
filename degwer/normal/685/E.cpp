#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int now[1000][1000];
typedef pair<int, int>pii;
typedef pair<pii, pii>pi4;
vector<pi4>dat[200000];
bool ans[200000];
int main()
{
	int num, way, query;
	scanf("%d%d%d", &num, &way, &query);
	vector<pii>vec;
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		zb--;
		vec.push_back(make_pair(za, zb));
	}
	for (int i = 0; i < query; i++)
	{
		int za, zb, zc, zd;
		scanf("%d%d%d%d", &za, &zb, &zc, &zd);
		za--, zb--, zc--, zd--;
		dat[zb].push_back(make_pair(make_pair(zc, zd), make_pair(za, i)));
	}
	for (int i = 0; i < num; i++)for (int j = 0; j < num; j++)now[i][j] = -1;
	for (int i = 0; i < way; i++)
	{
		int s = vec[i].first, t = vec[i].second;
		now[s][t] = now[t][s] = i;
		for (int j = 0; j < num; j++)
		{
			now[s][j] = now[t][j] = max(now[s][j], now[t][j]);
		}
		for (int j = 0; j < dat[i].size(); j++)
		{
			if (now[dat[i][j].first.second][dat[i][j].first.first] >= dat[i][j].second.first)ans[dat[i][j].second.second] = true;
			else ans[dat[i][j].second.second] = false;
		}
	}
	for (int i = 0; i < query; i++)
	{
		if (ans[i])printf("Yes\n");
		else printf("No\n");
	}
}