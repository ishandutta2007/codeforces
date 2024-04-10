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

const int MAX_N = 200 * 1000 + 5;

int n, m;
vector<pair<int, int>> graph[MAX_N];
int color[MAX_N];
bool used[MAX_N];
pair<int, int> edges[MAX_N];
vector<vector<int>> comp;
stack<int> now;
int tin[MAX_N];
int up[MAX_N];
int timer = 0;

vector<int> v_in;
vector<int> graph2[MAX_N];

void dfs(int v, int p)
{
	up[v] = tin[v] = timer++;
	used[v] = true;
	int to;
	for (int i = 0; i < graph[v].size(); ++i)
	{
		to = graph[v][i].first;
		if (graph[v][i].second == p) continue;
		if (used[to])
		{
			if (tin[v] > tin[to])
				now.push(graph[v][i].second);
			up[v] = min(tin[to], up[v]);
		}
		else
		{
			int last;
			if (!now.empty())
				last = now.top();
			else
				last = -1;
			now.push(graph[v][i].second);
			dfs(to, graph[v][i].second);
			
			up[v] = min(up[v], up[to]);
			if (up[to] >= tin[v])
			{
				vector<int> nn;
				while (!now.empty() && now.top() != last)
				{
					nn.push_back(now.top());
					now.pop();
				}
				comp.push_back(nn);
			}
		}
	}
}

vector<int> ans;
vector<int> st;
bool dfs_cy(int v, int p)
{
	st.push_back(v);
	used[v] = true;
	for (int i = 0; i < graph2[v].size(); ++i)
	{
		int to = graph2[v][i];
		if (!used[to])
		{
			if (dfs_cy(to, v))
				return true;
		}
		else if (to != p)
		{
			while (st.back() != to)
				ans.push_back(st.back()), st.pop_back();
			ans.push_back(to);
			st.clear();
			return true;
		}
	}
	
	st.pop_back();
	return false;
}

bool in_cyc[MAX_N];
vector<int> gg;
int nextt = -1;

bool dfs_a(int v, int fr)
{
//	cout << gg.size() << endl;
	gg.push_back(v);
	used[v] = true;
//	cout << v << " " << endl;
	for (int i = 0; i < graph2[v].size(); ++i)
	{
		int to = graph2[v][i];
		if (to == fr) continue;
		if (used[to])
		{
			if (in_cyc[to])
			{
				nextt = to;
				return true;
			}
		}
		else
		{
			if (dfs_a(to, fr))
				return true;
		}
	}

	gg.pop_back();
	return false;
}

void check(int pt)
{
	if (comp[pt].size() <= 1) return;
	for (int i = 0; i < comp[pt].size(); ++i)
	{
		v_in.push_back(edges[comp[pt][i]].first), v_in.push_back(edges[comp[pt][i]].second);
		graph2[edges[comp[pt][i]].first].push_back(edges[comp[pt][i]].second);
		graph2[edges[comp[pt][i]].second].push_back(edges[comp[pt][i]].first);
		
		//cout << edges[comp[pt][i]].first << " " << edges[comp[pt][i]].second << "\n";
	}
	sort(v_in.begin(), v_in.end());
	v_in.resize(unique(v_in.begin(), v_in.end()) - v_in.begin());
	gg.clear();	
	for (int i = 0; i < v_in.size(); ++i)
		used[v_in[i]] = in_cyc[v_in[i]] = false;
	
	ans.clear();
	gg.clear();
	st.clear();
	dfs_cy(v_in[0], -1);
	
	for (int i = 0; i < v_in.size(); ++i)
		used[v_in[i]] = false;
	
//	for (int i = 0; i < ans.size(); ++i)
//		cout << ans[i] << " " << endl;

	for (int i = 0; i < ans.size(); ++i)
		used[ans[i]] = in_cyc[ans[i]] = true;
	
	for (int i = 0; i < ans.size(); ++i)
	{
		for (int j = 0; j < graph2[ans[i]].size(); ++j)
		{
			int to = graph2[ans[i]][j];
	//		cout << ans[i] << "  " << to << endl;
			if (!used[to] || (to != ans[(i - 1 + ans.size()) % ans.size()] && ans[(i + 1) % ans.size()] != to))
			{
//			cout << "!" << to << endl;
				if (!used[to])
					dfs_a(to, ans[i]);
				else
					nextt = to;
				int p = 0;
				for (int pp = 0; pp < ans.size(); ++pp)
					if (ans[pp] == nextt) p = pp;
				if (i > p) swap(i, p), reverse(gg.begin(), gg.end());
				
				printf("YES\n");
				printf("%d ", (int)gg.size() + 2);
				printf("%d ", ans[i] + 1);
				for (int i = 0; i < gg.size(); ++i)
					printf("%d ", gg[i] + 1);
				printf("%d\n", ans[p] + 1);
				
				printf("%d ", p - i + 1);
				for (int j = i; j <= p; ++j)
					printf("%d ", ans[j] + 1);
				printf("\n");
				printf("%d ", (int)ans.size() - p + i + 1);
				for (int j = i; j >= 0; --j)
					printf("%d ", ans[j] + 1);
				for (int i = (int)ans.size() - 1; i >= p; --i)
					printf("%d ", ans[i] + 1);
				
				printf("\n");

				exit(0);
			}
		}
	}

	for (int i = 0; i < v_in.size(); ++i)
		graph2[v_in[i]].clear();
	v_in.clear();
}

int main()
{
#ifdef CH_EGOR
	freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#else
	//freopen("", "r", stdin);
	//freopen("", "w", stdout);
#endif 	

	scanf("%d%d", &n, &m);
	
	int v1, v2;
	for (int i = 0; i < m; ++i)
	{
		scanf("%d%d", &v1, &v2);
		--v1, --v2;
		edges[i] = {v1, v2};
		graph[v1].push_back({v2, i});
		graph[v2].push_back({v1, i});
	}
	
	memset(used, 0, sizeof(used));
	for (int i = 0; i < n; ++i)
	{
		if (!used[i])
			dfs(i, -1);
	}
	
//	for (int i = 0; i < comp.size(); ++i)
	{
//		for (int j = 0; j < comp[i].size(); ++j)
		{
//			printf("%d ", comp[i][j]);
		}
//		printf("\n");
	}

	for (int i = 0; i < comp.size(); ++i)
		check(i);
	
	printf("NO\n");

	return 0;
}