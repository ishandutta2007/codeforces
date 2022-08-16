/* cerberus97 - Hanit Banga */

// #pragma comment(linker, /STACK:36777216)
#pragma GCC optimize("O3")


#include <iostream>
#include <iomanip>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

#define pb push_back
#define fast_cin() ios_base::sync_with_stdio(false); cin.tie(NULL)

typedef long long ll;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;

const int N = 1e5 + 10, M = 5e6 + 1, D = 55;

// Attribution: https://github.com/radoslav11/Coding-Library/blob/master/graph/scc.cpp
vector<int> G[M];
int st[M], st_pos = 0;
int low[M], disc[M], comp[M];
int dfs_time;
bool in_stack[M];
int nxt = 1;

void dfs()
{
	int u = st[st_pos];
	low[u] = dfs_time;
	disc[u] = dfs_time++;

	in_stack[u] = true;
	
	for (int i = 0; i < G[u].size(); ++i)
	{
		int v = G[u][i];
		if(!disc[v])
		{
			st[++st_pos] = v;
			dfs();
			if (low[v] < low[u]) {
				low[u] = low[v];
			}
		}
		else if(in_stack[v] and disc[v] < low[u]) {
			low[u] = disc[v];
		}
	}

	if(low[u] == disc[u])
	{
		while(st[st_pos] != u)
		{
			comp[st[st_pos]] = nxt;
			in_stack[st[st_pos]] = false;
			--st_pos;
		}

		comp[u] = nxt++;
		in_stack[u] = false;
		--st_pos;
	}
}

void tarjan()
{
	dfs_time = 1;
	st[++st_pos] = 0;
	dfs();
}

vector<int> g[M];
bool *seen = in_stack;
int dp[M];
char s[D];

int solve(int u);

int main() {
	fast_cin();
	int n, m, d;
	cin >> n >> m >> d;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		for (int j = 0; j < d; ++j) {
			G[u * d + j].pb(v * d + (j + 1) % d);
		}
	}
	tarjan();
	for (int i = 0; i < n; ++i) {
		cin >> s;
		int u = i * d;
		for (int j = 0; j < d; ++j, ++u) {
			if (s[j] == '1') {
				int v = comp[u];
				if (!seen[v]) {
					++dp[v];
					seen[v] = true;
				}
			}
		}
		u = i * d;
		for (int j = 0; j < d; ++j, ++u) {
			seen[comp[u]] = false;
		}
	}
	for (int i = 0; i < d * n; ++i) {
		for (auto &j : G[i]) {
			if (comp[j] != comp[i]) {
				g[comp[i]].pb(comp[j]);
			}
		}
	}
	cout << solve(comp[0]) << endl;
}

int solve(int u) {
	seen[u] = true;
	int best = 0;
	for (auto &v : g[u]) {
		int cand = (seen[v] ? dp[v] : solve(v));
		if (cand > best) {
			best = cand;
		}
	}
	dp[u] += best;
	return dp[u];
}