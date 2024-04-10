#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

struct Node {
	// y = ax + b
	long long a, b;
};

class LiChaoTree {
public:
	vector<Node> dat; vector<int>g; int size_ = 1;

	void init(vector<int>x) {
		if (x.size() == 0) x.push_back(0);

		while (size_ < x.size()) size_ *= 2;
		while (x.size() < size_) x.push_back(x[x.size() - 1] + 1);
		g = x;
		dat.resize(size_ * 2, Node{ 0LL, (1LL << 60) });
	}
	void add(long long a, long long b) {
		int cx = 1, l = 0, r = size_;
		Node E = Node{ a, b };
		while (true) {
			int mid = (l + r) >> 1;
			long long c1 = E.a * g[mid] + E.b;
			long long c2 = dat[cx].a * g[mid] + dat[cx].b;
			if (c1 < c2) swap(dat[cx], E);

			if (r - l == 1) break;

			if (dat[cx].a < E.a) { cx = cx * 2; r = mid; }
			else { cx = cx * 2 + 1; l = mid; }
		}
	}

	long long getmin(long long pos) {
		int pos1 = lower_bound(g.begin(), g.end(), pos) - g.begin();
		pos1 += size_;

		long long minx = dat[pos1].a * pos + dat[pos1].b;
		while (pos1 >= 2) {
			pos1 >>= 1;
			minx = min(minx, dat[pos1].a * pos + dat[pos1].b);
		}
		return minx;
	}
};

const int MAX_N = (1 << 18);
LiChaoTree G[MAX_N]; vector<int> H[MAX_N], J;

long long N, A[MAX_N], B[MAX_N], ans[MAX_N], SIZE_ = 1; vector<int> Z[MAX_N];
int cl[MAX_N], cr[MAX_N], cnts; bool used[MAX_N];

void dfs(int pos) {
	used[pos] = true; cnts++; cl[pos] = cnts;
	for (int i = 0; i < Z[pos].size(); i++) {
		if (used[Z[pos][i]] == true) continue;
		dfs(Z[pos][i]);
	}
	cr[pos] = cnts;
	J.push_back(pos);
}

void adds(int l, int r, int x, int a, int b, int u) {
	if (l <= a && b <= r) { H[u].push_back(x); return; }
	if (r <= a || b <= l) return;
	adds(l, r, x, a, (a + b) >> 1, u * 2);
	adds(l, r, x, (a + b) >> 1, b, u * 2 + 1);
	H[u].push_back(x);
}

long long getans(int l, int r, long long x, int a, int b, int u) {
	if (l <= a && b <= r) {
		long long e = G[u].getmin(x);
		return e;
	}
	if (r <= a || b <= l) return (1LL << 60);
	long long v1 = getans(l, r, x, a, (a + b) >> 1, u * 2);
	long long v2 = getans(l, r, x, (a + b) >> 1, b, u * 2 + 1);
	return min(v1, v2);
}

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	for (int i = 1; i <= N; i++) scanf("%lld", &B[i]);
	for (int i = 1; i <= N - 1; i++) { int p1, p2; scanf("%d%d", &p1, &p2); Z[p1].push_back(p2); Z[p2].push_back(p1); }
	while (SIZE_ <= N) SIZE_ *= 2;

	dfs(1);
	for (int i = 1; i <= N; i++) {
		adds(cl[i], cr[i] + 1, A[i], 0, SIZE_, 1);
	}
	for (int i = 1; i < SIZE_ * 2; i++) {
		sort(H[i].begin(), H[i].end());
		H[i].erase(unique(H[i].begin(), H[i].end()), H[i].end());
		G[i].init(H[i]);
	}

	for (int pos : J) {
		if (Z[pos].size() == 1 && pos != 1) { ans[pos] = 0; }
		else {
			ans[pos] = getans(cl[pos], cr[pos] + 1, A[pos], 0, SIZE_, 1);
		}
		int pos1 = cl[pos] + SIZE_;
		G[pos1].add(B[pos], ans[pos]);
		while (pos1 >= 2) {
			pos1 >>= 1;
			G[pos1].add(B[pos], ans[pos]);
		}
	}
	for (int i = 1; i <= N; i++) printf("%lld\n", ans[i]);
	return 0;
}