#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <iostream>
#include <vector>
#include <string>

using namespace std;

const int N = 2e5 + 7;
const int M = 33;

int m, n, start[M], finish[M], source;
vector<string> s;
string all;
vector<pair<int, int> > adj[N];

void add_edge(int a, int b, int t) {
	//if (t >= 1 && t <= 2) {
	//	printf("adding %d %d %d\n", a, b, t);
	//}
	adj[a].push_back({b, t});
}

int z[N];
void build_z(const string &s) {
	int n = s.size();
	z[0] = n;
	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		z[i] = i > r ? 0 : min(z[i - l], r - i + 1);
		while (i + z[i] < n && s[i + z[i]] == s[z[i]]) {
			z[i]++;
		}
		if (i + z[i] - 1 > r) {
			r = i + z[i] - 1;
			l = i;
		}
	}
}

int visit[N], tag;

int gfrom, gto;

int low[N], dfn[N], color[N], cnt[N];
vector<int> stack;
int in_stack[N], tot, tot_color;

bool tarjan(int u) {
	low[u] = dfn[u] = ++tot;
	stack.push_back(u);
	in_stack[u] = 1;
	for (auto p : adj[u]) {
		if (p.second < gfrom || p.second > gto) continue;
		int v = p.first;
		if (!dfn[v]) {
			tarjan(v);
			low[u] = min(low[u], low[v]);
		} else if (in_stack[v]) {
			low[u] = min(low[u], dfn[v]);
		}
	}
	if (low[u] == dfn[u]) {
		tot_color++;
		while (true) {
			int v = stack.back();
			stack.pop_back();
			color[v] = tot_color;
			cnt[tot_color]++;
			in_stack[v] = false;
			if (u == v) break;
		}
	}
	return false;
}

int test(int from, int to) {
	gfrom = from, gto = to;
	for (int i = 0; i <= source; i ++) {
		low[i] = dfn[i] = color[i] = 0;
		cnt[i] = in_stack[i] = 0;
	}
	tot_color = 0;
	tot = 0;
	stack.clear();
	for (int i = 0; i <= source; i++) {
		if (dfn[i]) continue;
		if (i == source || (i >= start[from] && i < finish[to])) {
			tarjan(i);
		}
	}
	for (int i = 0; i <= source; i++) {
		for (int j = from; j <= to; j++) {
			if (i > start[j] && i < finish[j]) {
				if (cnt[color[i]] > 1) return true;
				for (auto p : adj[i]) {
					if (p.second < from || p.second > to) continue;
					if (p.first == i) return true;
				}
			}
		}
	}
	return false;
}

int main() {
	n = 0;
	scanf("%d", &m);
	for (int i = 0; i < m; i++) {
		static char buffer[N];
		//if (i == 0) 
		scanf("%s", buffer);
		s.push_back(buffer);
		start[i] = all.size();
		for (auto c : s.back()) {
			all += c;
		}
		finish[i] = all.size();
	}
	source = all.size();
	for (int i = 0; i < m; i++) {
		string cur;
		for (auto c : s[i]) {
			cur += c;
		}
		int from = cur.size();
		cur += '#';
		add_edge(source, start[i], i);
		for (int j = 0; j < m; j++) {
			cur.resize(from + 1);
			for (auto c : s[j]) {
				cur += c;
			}
			build_z(cur);
			for (int k = 0; k < s[j].size(); k++) {
				int x = s[i].size();
				int y = s[j].size() - k;
				if (z[from + k + 1] == min(x, y)) {
					int zl = z[from + k + 1];
					//cout << s[j].substr(k, zl) << " xx " << s[i].substr(0, zl) << endl;
					if (x == y) {
						add_edge(start[j] + k, source, i);
					} else if (x > y) {
						add_edge(start[j] + k, start[i] + y, i);
					} else {
						add_edge(start[j] + k, start[j] + k + x, i);
					}
				}
			}
		}
	}
	int r = 0, ans = 0;
	for (int i = 0; i < m; i++) {
		while (r < m && !test(i, r)) {
			r++;
		}
		//cout << "i, r = " << i << " " << r << endl;
		ans += r - i;
	}
	printf("%d\n", ans);
	return 0;
}