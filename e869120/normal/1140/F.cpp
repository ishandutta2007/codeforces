#include <iostream>
#include <vector>
#include <tuple>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int MAX_N = (1 << 20);
const int MAX_Z = 320000;

// ------------------------------- Union Find Tree -----------------------------

long long par[MAX_N], rank_[MAX_N], v1[MAX_N], v2[MAX_N], sum;
vector<tuple<int, int, int>>vec[MAX_N];

void init() {
	for (int i = 0; i < MAX_N; i++) {
		par[i] = -1;
		rank_[i] = 0;
		if (i <= MAX_Z) { v1[i] = 1; v2[i] = 0; }
		else { v1[i] = 0; v2[i] = 1; }
	}
	sum = 0;
}

int root(int pos) {
	if (par[pos] == -1) return pos;
	return root(par[pos]);
}

void unite(int ty, int u, int v) {
	u = root(u);
	v = root(v);
	if (u == v) return;

	if (rank_[u] < rank_[v]) {
		sum -= v1[u] * v2[u];
		sum -= v1[v] * v2[v];
		sum += (v1[u] + v1[v]) * (v2[u] + v2[v]);
		vec[ty].push_back(make_tuple(1, u, par[u])); par[u] = v;
		vec[ty].push_back(make_tuple(2, v, rank_[v])); rank_[v] = max(rank_[v], rank_[u] + 1);
		vec[ty].push_back(make_tuple(3, v, v1[v])); v1[v] = v1[u] + v1[v];
		vec[ty].push_back(make_tuple(3, u, v1[u])); v1[u] = 0;
		vec[ty].push_back(make_tuple(4, v, v2[v])); v2[v] = v2[u] + v2[v];
		vec[ty].push_back(make_tuple(4, u, v2[u])); v2[u] = 0;
	}
	else {
		sum -= v1[u] * v2[u];
		sum -= v1[v] * v2[v];
		sum += (v1[u] + v1[v]) * (v2[u] + v2[v]);
		vec[ty].push_back(make_tuple(1, v, par[v])); par[v] = u;
		vec[ty].push_back(make_tuple(2, u, rank_[u])); rank_[u] = max(rank_[u], rank_[v] + 1);

		long long s1 = v1[u] + v1[v], s2 = v2[u] + v2[v];
		vec[ty].push_back(make_tuple(3, v, v1[v])); v1[v] = 0;
		vec[ty].push_back(make_tuple(3, u, v1[u])); v1[u] = s1;
		vec[ty].push_back(make_tuple(4, v, v2[v])); v2[v] = 0;
		vec[ty].push_back(make_tuple(4, u, v2[u])); v2[u] = s2;
	}
}

bool same(int u, int v) {
	if (root(u) == root(v)) return true;
	return false;
}

void rollback(int ty) {
	reverse(vec[ty].begin(), vec[ty].end());

	for (int i = 0; i < vec[ty].size(); i++) {
		if (get<0>(vec[ty][i]) == 1) par[get<1>(vec[ty][i])] = get<2>(vec[ty][i]);
		if (get<0>(vec[ty][i]) == 2) rank_[get<1>(vec[ty][i])] = get<2>(vec[ty][i]);
		if (get<0>(vec[ty][i]) == 3) v1[get<1>(vec[ty][i])] = get<2>(vec[ty][i]);
		if (get<0>(vec[ty][i]) == 4) v2[get<1>(vec[ty][i])] = get<2>(vec[ty][i]);
	}
	vec[ty].clear();
}

// ------------------------------------ Segment Tree ----------------------------------

vector<pair<int, int>> dat[MAX_N]; int size_; long long Answer[1 << 20];

void inits(int n) {
	size_ = 1;
	while (size_ <= n) size_ *= 2;
}

void add_(int l, int r, int a, int b, pair<int, int>x, int u) {
	if (l <= a && b <= r) { dat[u].push_back(x); return; }
	if (r <= a || b <= l) return;

	add_(l, r, a, (a + b) >> 1, x, u * 2);
	add_(l, r, (a + b) >> 1, b, x, u * 2 + 1);
}

void add(int l, int r, pair<int, int>x) {
	add_(l, r, 0, size_, x, 1);
}

void query(int u, long long sums) {
	sum = sums;
	// --------------- Add Part ------------------
	for (int i = 0; i < dat[u].size(); i++) {
		unite(u, dat[u][i].first, dat[u][i].second);
	}

	long long CurrentSum = sum;
	if (u >= size_) {
		Answer[u - size_] = sum;
	}
	else {
		query(u * 2, CurrentSum);
		query(u * 2 + 1, CurrentSum);
	}

	rollback(u);
	sum = sums;
}

// -------------------------------------------- Main Part ----------------------------------------

long long Q, X[1 << 19], Y[1 << 19];
map<pair<long long, long long>, int>Map;

int main() {
	scanf("%lld", &Q); init(); inits(Q + 2);

	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &X[i], &Y[i]);
		if (Map[make_pair(X[i], Y[i])] == 0) Map[make_pair(X[i], Y[i])] = i;
		else {
			add(Map[make_pair(X[i], Y[i])], i, make_pair(X[i], Y[i] + MAX_Z));
			Map[make_pair(X[i], Y[i])] = 0;
		}
	}
	for (int i = 1; i <= Q; i++) {
		if (Map[make_pair(X[i], Y[i])] >= 1) {
			add(Map[make_pair(X[i], Y[i])], Q + 1, make_pair(X[i], Y[i] + MAX_Z));
			Map[make_pair(X[i], Y[i])] = 0;
		}
	}

	query(1, 0);

	for (int i = 1; i <= Q; i++) {
		if (i >= 2) printf(" ");
		printf("%lld", Answer[i]);
	}
	printf("\n");
	return 0;
}