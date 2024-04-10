#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <string>
#include <string.h>
#include <vector>
#include <stack>
#include <queue>
#include <deque>
#include <set>
#include <map>
#include <assert.h>
#include <algorithm>
#include <iomanip>
#include <time.h>
#include <math.h>
#include <bitset>

#pragma comment(linker, "/STACK:256000000")

using namespace std;

typedef long long int ll;
typedef long double ld;

const int INF = 1000 * 1000 * 1000 + 21;
const ll LLINF = (1ll << 60) + 5;
const int MOD = 1000 * 1000 * 1000 + 7;

const int MAX_N = 1005;

int n;
pair<string, int> fr;
vector<int> g[MAX_N];
map<pair<string, int>, int> ids;
map<int, pair<string, int>> rev;
char buf[55];
int cnt_id = 0;
int dist[MAX_N];
bool used[MAX_N];
bool used2[MAX_N];
queue<int> cc;

int get_id(pair<string, int> &now)
{
	if (ids.find(now) == ids.end()) 
	{
		ids[now] = cnt_id++;
		rev[cnt_id - 1] = now;
	}

	return ids[now];
}

map<string, int> have;
vector<int> order;

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif

	scanf("%d", &n);

	for (int i = 0; i < n; ++i)
	{
		pair<string, int> now;
		
		int x;
		scanf("%s %d", buf, &x);
		now = make_pair(string(buf), x);
		
		if (i == 0) fr = now;
		int cur = get_id(now);

		int len;
		scanf("%d", &len);
		for (int i = 0; i < len; ++i)
		{
			scanf("%s %d", buf, &x);
			now = make_pair(string(buf), x);
			g[cur].push_back(get_id(now));
		}
	}
	
	for (int i = 0; i < n; ++i) dist[i] = INF;

	dist[0] = 0;
	cc.push(0);

/*	while (!cc.empty())
	{
		int v = cc.front();
		cc.pop();

		for (int i = 0; i < (int)g[v].size(); ++i)
		{
			int to = g[v][i];
			if (dist[to] > dist[v] + 1)
			{
				dist[to] = dist[v] + 1;
				cc.push(to);
			}
		}
	}
*/	
	used[0] = true;
	
	while (true)
	{
		int to = -1;

		for (int i = 0; i < n; ++i)
		{
			if (used[i] && !used2[i] &&
				(to == -1 || dist[to] > dist[i] ||
				 (dist[to] == dist[i] && rev[to].second < rev[i].second)))
			{
				to = i;
			}
		}

		if (to == -1 || dist[to] == INF) break;
		used2[to] = true;
		if (have.find(rev[to].first) != have.end()) continue;
		have[rev[to].first] = rev[to].second;

		for (int i = 0; i < (int)g[to].size(); ++i)
		{
			int to_to = g[to][i];
			used[to_to] = true;
			dist[to_to] = min(dist[to_to], dist[to] + 1);		
		}
	}

	have.erase(fr.first);
	printf("%d\n", (int)have.size());	
	for (auto it = have.begin(); it != have.end(); ++it)
	{
		printf("%s %d\n", it->first.c_str(), it->second);
	}

	return 0;
}