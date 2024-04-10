#include <bits/stdc++.h>

using namespace std;

#define x first
#define y second
#define size(a) int((a).size())

typedef pair<int, int> pt;

const int N = 200 * 1000 + 11;

int n;
vector<int> g[N];

int p[N];
int dist[N];

bool bad[N];
int value[N];
pt res[N];
vector<pt> best[N];

void dfs(int v, int par = -1, int d = 0) {
	p[v] = par;
	dist[v] = d;
	for (auto to : g[v]) {
		if (to == par) {
			continue;
		}
		dfs(to, v, d + 1);
	}
}

int getFarthest(int v) {
	dfs(v);
	int res = v;
	for (int i = 0; i < n; ++i) {
		if (bad[i]) {
			continue;
		}
		if (dist[res] < dist[i]) {
			res = i;
		}
	}
	return res;
}

pt get(int v) {
	return { dist[v], value[v] };
}

int getBetter(int v, int u) {
	if (get(v) > get(u)) {
		return v;
	}
	return u;
}

int getBest(int v, int par) {
	int res = v;
	for (auto to : g[v]) {
		if (to == par || bad[to]) {
			continue;
		}
		res = getBetter(res, getBest(to, v));
	}
	return res;
}

pt calc(int v) {
	dfs(v);
	
	vector<int> ch;
	for (auto to : g[v]) {
		if (!bad[to]) {
			ch.push_back(to);
		}
	}
	if (size(ch) == 1) {
		return { v, ch[0] };
	}
	
	vector<int> pref(size(ch));
	vector<int> suf(size(ch));
	vector<int> best(size(ch));
	for (int i = 0; i < size(ch); ++i) {
		int to = ch[i];
		best[i] = pref[i] = suf[i] = getBest(to, v);
	}
	for (int i = 1; i < size(ch); ++i) {
		pref[i] = getBetter(pref[i], pref[i - 1]);
		suf[size(ch) - i - 1] = getBetter(suf[size(ch) - i - 1], suf[size(ch) - i]);
	}
	
	pt ans = { -1, -1 };
	pt res = { 0, 0 };
	for (int i = 0; i < size(ch); ++i) {
		int bst = -1;
		if (i == 0) {
			bst = suf[i + 1];
		} else if (i + 1 == size(ch)) {
			bst = pref[i - 1];
		} else {
			bst = getBetter(pref[i - 1], suf[i + 1]);
		}
		pt curRes = { dist[bst] + dist[best[i]], value[bst] + value[best[i]] };
		if (res < curRes) {
			res = curRes;
			ans = { best[i], bst };
		}
	}
	
	return ans;
}

int main() {
#ifdef _DEBUG
	freopen("input.txt", "r", stdin);
//	freopen("output.txt", "w", stdout);
#endif

	cin >> n;
	for (int i = 0; i < n - 1; ++i) {
		int x, y;
		cin >> x >> y;
		--x, --y;
		g[x].push_back(y);
		g[y].push_back(x);
	}
	
	int root = -1;
	for (int i = 0; i < n; ++i) {
		if (size(g[i]) > 2) {
			root = i;
			dfs(i);
			break;
		}
	}
	
	for (int i = 0; i < n; ++i) {
		if (size(g[i]) != 1) {
			continue;
		}
		int v = i;
		while (size(g[v]) < 3) {
			bad[v] = true;
			v = p[v];
		}
		best[v].push_back({dist[i] - dist[v], i});
	}
	
	for (int i = 0; i < n; ++i) {
		if (size(best[i]) >= 2) {
			sort(best[i].rbegin(), best[i].rend());
			value[i] = best[i][0].first + best[i][1].first;
			res[i] = { best[i][0].second, best[i][1].second };
		}
	}
	
	int u = getFarthest(root);
	int v = getFarthest(u);
	vector<int> path;
	while (v != u) {
		path.push_back(v);
		v = p[v];
	}
	path.push_back(u);
	
	pt ans = calc(path[size(path) / 2]);
	
	printf("%d %d\n", res[ans.x].x + 1, res[ans.y].x + 1);
	printf("%d %d\n", res[ans.x].y + 1, res[ans.y].y + 1);
	
	return 0;
}