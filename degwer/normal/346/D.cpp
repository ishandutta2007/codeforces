#include<stdio.h>
#include<vector>
#include<algorithm>
#include<deque>
using namespace std;
typedef pair<int, int>pii;
vector<int>pat[1000000];
vector<int>rpat[1000000];
int dist[1000000];
int out[1000000];
bool flag[1000000];
int main()
{
	int num, way;
	scanf("%d%d", &num, &way);
	for (int i = 0; i < way; i++)
	{
		int za, zb;
		scanf("%d%d", &za, &zb);
		za--, zb--;
		pat[za].push_back(zb);
		rpat[zb].push_back(za);
		out[za]++;
	}
	int st, go;
	scanf("%d%d", &st, &go);
	st--, go--;
	deque<pii>deq;
	deq.push_back(make_pair(go, 0));
	dist[go] = 0;
	fill(dist, dist + num, -1);
	for (;;)
	{
		if (deq.empty())break;
		pii z = deq.front();
		deq.pop_front();
		if (flag[z.first])continue;
		flag[z.first] = true;
		dist[z.first] = z.second;
		for (int i = 0; i < rpat[z.first].size(); i++)
		{
			out[rpat[z.first][i]]--;
			if (out[rpat[z.first][i]] == 0)deq.push_front(make_pair(rpat[z.first][i], z.second));
			else deq.push_back(make_pair(rpat[z.first][i], z.second + 1));
		}
	}
	printf("%d\n", dist[st]);
}