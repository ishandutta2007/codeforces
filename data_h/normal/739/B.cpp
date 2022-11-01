#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
#include <cassert>
#include <cstring>
#include <string>

using namespace std;

const int N = 2e5 + 7;

int n, m, size[N], a[N];
vector<pair<int, int> > adj[N];
vector<long long> values;
long long dep[N];

void traverse(int u) {
	size[u] = 1;
	values.push_back(dep[u] - a[u]);
	for (auto e : adj[u]) {
		int v = e.first, cost = e.second;
		dep[v] = dep[u] + cost;
		traverse(v);
		size[u] += size[v];
	}
}

inline int lowbit(int x) {
	return x & -x;
}

vector<pair<int, int> > record;

int h[N];
void insert(int pos, int v) {
	for (int i = pos + 1; i <= values.size(); i += lowbit(i)) {
		h[i] += v;
	}
}

int ask(int pos) {
	int ret = 0;
	for (int i = pos + 1; i; i -= lowbit(i)) {
		ret += h[i];
	}
	return ret;
}

void clear() {
	while (record.size()) {
		insert(record.back().first, -record.back().second);
		record.pop_back();
	}
}

int ans[N];

void go(int u) {
	int pos = lower_bound(values.begin(), values.end(), dep[u] - a[u]) - values.begin();
	record.push_back(make_pair(pos, 1));
	insert(pos, 1);
	for (auto e : adj[u]) {
		int v = e.first;
		go(v);
	}
}

void dfs(int u) {
	int max_son = -1;
	for (auto e : adj[u]) {
		int v = e.first;
		if (max_son == -1 || size[v] > size[max_son]) {
			max_son = v;
		}
	}
	for (auto e : adj[u]) {
		int v = e.first;
		if (v != max_son) {
			dfs(v);
			clear();
		}
	}
	if (max_son != -1) {
		dfs(max_son);
	}
	for (auto e : adj[u]) {
		int v = e.first;
		if (v != max_son) {
			go(v);
		}
	}
	int pos = upper_bound(values.begin(), values.end(), dep[u]) - values.begin() - 1;
	ans[u] = ask(pos);
	pos = lower_bound(values.begin(), values.end(), dep[u] - a[u]) - values.begin();
	record.push_back(make_pair(pos, 1));
	insert(pos, 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 2; i <= n; i++) {
		int parent, pv;
		scanf("%d %d", &parent, &pv);
		adj[parent].push_back(make_pair(i, pv));
	}
	dep[1] = 0;
	traverse(1);
	sort(values.begin(), values.end());
	values.erase(unique(values.begin(), values.end()), values.end());
	dfs(1);
	for (int i = 1; i <= n; i++) {
		printf("%d%c", ans[i], i == n ? '\n' : ' ');
	}
	return 0;
}