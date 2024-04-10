#include<stdio.h>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<ll, ll>pii;
vector<pii>pat[100000];
ll dist[100000];
bool flag[100000];
#define INF 1000000000000000000LL
ll ans[100000];
ll pp[100000];
int main()
{
	int num, way, tr;
	scanf("%d%d%d", &num, &way, &tr);
	for (int i = 0; i < way; i++)
	{
		int za, zb, zc;
		scanf("%d%d%d", &za, &zb, &zc);
		za--, zb--;
		pat[za].push_back(make_pair(zb, zc));
		pat[zb].push_back(make_pair(za, zc));
	}
	fill(pp, pp + num, INF);
	vector<pii>vec;
	for (int i = 0; i < tr; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--;
		pp[za] = min(pp[za], (ll)zb);
	}
	for (int i = 1; i < num; i++)if (pp[i] < INF)pat[0].push_back(make_pair(i, pp[i])), vec.push_back(make_pair(i, pp[i]));
	fill(dist, dist + num, INF);
	priority_queue<pii>que;
	que.push(make_pair(0, 0));
	dist[0] = 0;
	for (;;)
	{
		if (que.empty())break;
		pii z = que.top();
		que.pop();
		if (flag[z.second])continue;
		flag[z.second] = true;
		for (int i = 0; i < pat[z.second].size(); i++)
		{
			if (dist[pat[z.second][i].first] > -z.first + pat[z.second][i].second)
			{
				dist[pat[z.second][i].first] = -z.first + pat[z.second][i].second;
				que.push(make_pair(-dist[pat[z.second][i].first], pat[z.second][i].first));
			}
		}
	}
	for (int i = 1; i < num; i++)
	{
		ll now = INF;
		for (int j = 0; j < pat[i].size(); j++)now = min(now, dist[pat[i][j].first] + pat[i][j].second);
		ans[i] = now;
	}
	int r = 0;
	for (int i = 0; i < vec.size(); i++)
	{
		if (ans[vec[i].first] > vec[i].second)r++;
	}
	printf("%d\n", tr - r);
}