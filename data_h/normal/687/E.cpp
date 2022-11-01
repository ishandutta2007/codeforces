#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

const int N = 5e3 + 10;

int n, m;
vector<int> adj[N];

int time_stamp;
int dfn[N], low[N], bel[N];
bool in_stack[N];
vector<int> stack;

vector<vector<int> > blocks;

void tarjan(int x) {
	dfn[x] = low[x] = ++time_stamp;
	in_stack[x] = true;
	stack.push_back(x);

	for (int i = 0; i < adj[x].size(); i++) {
		int y = adj[x][i];
		if (dfn[y] == -1) {
			tarjan(y);
			low[x] = min(low[x], low[y]);
		} else if (in_stack[y]) {
			low[x] = min(low[x], dfn[y]);
		}
	}

	if (low[x] == dfn[x]) {
		vector<int> cur;
		while (true) {
			int v = stack.back();
			stack.pop_back();
			cur.push_back(v);
			bel[v] = blocks.size();
			in_stack[v] = false;
			if (v == x) {
				break;
			}
		}
		blocks.push_back(cur);
	}
}

int dist[N];

int bfs(int s) {
	static vector<int> queue;
	queue.clear();
	fill(dist, dist + n, -1);

	dist[s] = 0;
	queue.push_back(s);
	for (int head = 0; head < queue.size(); head++) {
		int x = queue[head];
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (dist[y] == -1) {
				dist[y] = dist[x] + 1;
				queue.push_back(y);
			}
		}
	}

	int ret = n;

	for (int x = 0; x < n; x++) {
		if (dist[x] != -1) {
			for (int i = 0; i < adj[x].size(); i++) {
				int y = adj[x][i];
				if (y == s) {
					ret = min(ret, dist[x] + 1);
				}
			}
		}
	}

	return ret;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].push_back(v);
	}

	fill(dfn, dfn + n, -1);
	fill(low, low + n, -1);
	fill(in_stack, in_stack + n, false);
	blocks.clear();

	for (int i = 0; i < n; i++) {
		if (dfn[i] == -1) {
			tarjan(i);
		}
	}

	static int out[N];
	fill(out, out + blocks.size(), 0);

	for (int x = 0; x < n; x++) {
		for (int i = 0; i < adj[x].size(); i++) {
			int y = adj[x][i];
			if (bel[y] != bel[x]) {
				out[bel[x]]++;
			}
		}
	}

	//cout << "block size = " << blocks.size() << endl;

	int answer = n;
	for (int i = 0; i < blocks.size(); i++) {
		if (out[i]) {
			continue;
		} else {
			vector<int> cur = blocks[i];
			if (cur.size() == 1) {
				continue;
			}
			int min_cycle = n;
			for (auto x : cur) {
				min_cycle = min(min_cycle, bfs(x));
			}
			answer += 998 * min_cycle + 1;
		}
	}
	printf("%d\n", answer);
	return 0;
}