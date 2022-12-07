#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>
#include <iostream>
#include <cassert>

const int N = 4e5 + 7;
typedef std::vector<std::pair<int, int> > EdgeList;

int father[N];
EdgeList edges;

int find(int x) {
	return father[x] == x ? x : father[x] = find(father[x]);
}

int n, m;
int s, t, ds, dt;

bool rel_st(std::pair<int, int> p) {
	return (p.first == s || p.first == t ||
		p.second == s || p.second == t);
}

EdgeList solve(EdgeList edges) {
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	EdgeList ret;
	for (int i = 0; i < edges.size(); i++) {
		int u = edges[i].first, v = edges[i].second;
		if (find(u) != find(v)) {
			father[find(u)] = find(v);
			ret.push_back({u, v});
		}
	}
	return ret;
}

bool to_s[N], to_t[N];
int s2who[N], t2who[N];

void get_info(int s, bool to[], int to_who[], EdgeList edges) {
	std::fill(to + 1, to + n + 1, false);
	for (auto e : edges) {
		if (e.second == s) std::swap(e.first, e.second);
		if (e.first == s) {
			int v = e.second;
			to[find(v)] = true;
			to_who[find(v)] = v;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		edges.push_back({u, v});
	}
	scanf("%d %d %d %d", &s, &t, &ds, &dt);
	std::vector<std::pair<int, int> > bak = edges;
	edges.clear();
	for (auto p : bak) {
		if (!rel_st(p)) {
			edges.push_back(p);
		}
	}
	for (auto p : bak) {
		if (rel_st(p)) {
			edges.push_back(p);
		}
	}
	auto vec = solve(edges);
	if (vec.size() < n - 1) {
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		father[i] = i;
	}
	EdgeList ans;
	for (auto choosed : vec) {
		if (!rel_st(choosed)) {
			int u = choosed.first;
			int v = choosed.second;
			father[find(u)] = father[find(v)];
			ans.push_back(choosed);
		}
	}
	get_info(s, to_s, s2who, edges);
	get_info(t, to_t, t2who, edges);
	for (int i = 1; i <= n; i++) {
		if (i != s && i != t && i == find(i)) {
			assert(to_s[i] || to_t[i]);
			if (to_s[i] && !to_t[i]) {
				ds--;
				father[i] = s;
				ans.push_back({s, s2who[i]});
			} else if (to_t[i] && !to_s[i]) {
				dt--;
				father[i] = t;
				ans.push_back({t, t2who[i]});
			}
		}
	}
	int extras = -1, extrat = -1;
	for (int i = 1; i <= n; i++) {
		if (i != s && i != t && i == find(i)) {
			if (to_s[i] && to_t[i]) {
				if (ds > dt) {
					ds--;
					ans.push_back({s, s2who[i]});
					extrat = t2who[i];
				} else {
					dt--;
					ans.push_back({t, t2who[i]});
					extras = s2who[i];
				}
			}
		}
	}
	if (extras == -1 && extrat == -1) {
		ans.push_back({s, t});
		ds--;
		dt--;
	} else if ((ds >= dt && extras != -1) || extrat == -1) {
		ans.push_back({s, extras});
		ds--;
	} else if ((dt >= ds && extrat != -1) || extras == -1) {
		ans.push_back({t, extrat});
		dt--;
	}
	if (ds < 0 || dt < 0 || ans.size() < n - 1) {
		puts("No");
		return 0;
	} else {
		puts("Yes");
		for (auto a : ans) {
			printf("%d %d\n", a.first, a.second);
		}
	}
}