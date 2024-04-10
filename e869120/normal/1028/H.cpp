#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

class RangeMinimumQuery {
public:
	vector<int> dat; int size_ = 1;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, (1 << 30));
	}
	void update(int pos, int x) {
		pos += size_; dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = min(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	int query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return (1 << 30);
		int v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		int v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return min(v1, v2);
	}
	int query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

int N, Q, A[1 << 18], E[15][1 << 18], P[8][5100000];
vector<int> G[1 << 18], prime;
RangeMinimumQuery Z[15];

void init() {
	for (int i = 2; i <= 5000; i++) {
		bool flag = false;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) flag = true;
		}
		if (flag == false) prime.push_back(i);
	}
}

int query(int cl, int cr) {
	for (int i = 0; i <= 14; i++) {
		int Y = Z[i].query(cl, cr + 1);
		if (Y <= cr) return i;
	}
	return 1000000007;
}

int main() {
	scanf("%d%d", &N, &Q); init();
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]); int cx = A[i];
		for (int j = 0; j < prime.size(); j++) {
			if (cx%prime[j] != 0) continue;
			int v = 0; while (cx%prime[j] == 0) { cx /= prime[j]; v ^= 1; }
			if (v == 1) G[i].push_back(prime[j]);
		}
		if (cx >= 2) G[i].push_back(cx);
	}
	for (int i = 0; i <= 7; i++) { for (int j = 0; j <= 5032107; j++) P[i][j] = N + 1; }
	for (int i = 0; i <= 14; i++) { for (int j = 1; j <= N; j++) E[i][j] = N + 1; }
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < (1 << G[i].size()); j++) {
			int v = 1, cp = 0; for (int k = 0; k < G[i].size(); k++) { if ((j & (1 << k)) != 0) { v *= G[i][k]; cp++; } }
			for (int k = cp; k <= 7; k++) {
				int num = (int)G[i].size() + k - cp * 2;
				E[num][i] = min(E[num][i], P[k][v]);
			}
		}
		for (int j = 0; j < (1 << G[i].size()); j++) {
			int v = 1; for (int k = 0; k < G[i].size(); k++) { if ((j & (1 << k)) != 0) v *= G[i][k]; }
			P[G[i].size()][v] = i;
		}
	}

	for (int i = 0; i <= 14; i++) {
		Z[i].init(N + 2);
		for (int j = 1; j <= N; j++) Z[i].update(j, E[i][j]);
	}

	for (int i = 1; i <= Q; i++) {
		int cl, cr; scanf("%d%d", &cl, &cr);
		printf("%d\n", query(cl, cr));
	}
	return 0;
}