#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
typedef pair<int, int> pii;

const int INF = 2020202020;

int N;
int X[1010];
int Y[1010];

vector<pii> V[1010];
vector<pii> H[1010];

vector<int> xs, ys;
bool chk[1010];

struct DSU {
	int p[1010];
	int n, com;

	void init(int _n) {
		n = com = _n;
		for(int i = 1; i <= n; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		if(a == b) return;
		p[a] = b;
		com--;
	}
	
	int count() {
		return com;
	}
}uf;

void comv(vector<int>& v) {
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
}

int get_idx(vector<int>& v, int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

bool solve(int dst) {
	// printf("dst = %d\n", dst);
	uf.init(N);

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < H[i].size(); j++) {
			if(H[i][j].first - H[i][j - 1].first <= dst) uf.unite(H[i][j - 1].second, H[i][j].second);
		}
		for(int j = 1; j < V[i].size(); j++) {
			if(V[i][j].first - V[i][j - 1].first <= dst) uf.unite(V[i][j - 1].second, V[i][j].second);
		}
	}

	int c = uf.count();
	if(c > 4) return false;
	if(c == 1) return true;

	auto f = [&](int x, int y) {
		int u = 0, d = 0, l = 0, r = 0;
		auto it = lower_bound(xs.begin(), xs.end(), x);
		if(*it == x) {
			int xi = it - xs.begin() + 1;
			auto it2 = lower_bound(V[xi].begin(), V[xi].end(), pii(y, 0));
			if(it2 != V[xi].end()) u = it2 -> second;
			if(it2 != V[xi].begin()) d = (--it2) -> second;
		}

		it = lower_bound(ys.begin(), ys.end(), y);
		if(*it == y) {
			int yi = it - ys.begin() + 1;
			auto it2 = lower_bound(H[yi].begin(), H[yi].end(), pii(x, 0));
			if(it2 != H[yi].end()) r = it2 -> second;
			if(it2 != H[yi].begin()) l = (--it2) -> second;
		}

		if(u && Y[u] - y > dst) u = 0;
		if(d && y - Y[d] > dst) d = 0;
		if(r && X[r] - x > dst) r = 0;
		if(l && x - X[l] > dst) l = 0;

		if(u) u = uf.par(u);
		if(d) d = uf.par(d);
		if(r) r = uf.par(r);
		if(l) l = uf.par(l);

		set<int> S;
		for(int i : {u, d, r, l}) {
			if(i) S.insert(i);
		}
		if(S.size() >= c) return true;
		return false;
	};

	for(int i = 0; i < xs.size(); i++) {
		for(int j = 0; j < ys.size(); j++) {
			if(f(xs[i], ys[j])) return true;
		}
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j < H[i].size(); j++) {
			int x1 = H[i][j - 1].first, x2 = H[i][j].first;
			if(x2 - x1 <= dst || x2 - x1 > 2 * dst) continue;
			int y = ys[i - 1], x = (x1 + x2) / 2;
			if(f(x, y)) return true;
		}
		for(int j = 1; j < V[i].size(); j++) {
			int y1 = V[i][j - 1].first, y2 = V[i][j].first;
			if(y2 - y1 <= dst || y2 - y1 > 2 * dst) continue;
			int x = xs[i - 1], y = (y1 + y2) / 2;
			if(f(x, y)) return true;
		}
	}
	return false;
}

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d%d", &X[i], &Y[i]);
		xs.push_back(X[i]);
		ys.push_back(Y[i]);
	}

	comv(xs); comv(ys);

	for(int i = 1; i <= N; i++) {
		H[get_idx(ys, Y[i])].emplace_back(X[i], i);
		V[get_idx(xs, X[i])].emplace_back(Y[i], i);
	}

	for(int i = 1; i <= N; i++) {
		sort(H[i].begin(), H[i].end());
		sort(V[i].begin(), V[i].end());
	}

	int l = 1, r = INF;
	while(l <= r) {
		ll m = (ll)l + r >> 1;
		if(solve(m)) r = m - 1;
		else l = m + 1;
	}
	printf("%d\n", l > INF ? -1 : l);

	return 0;
}