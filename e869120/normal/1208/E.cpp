#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

class RangeMax {
public:
	vector<long long> dat;
	int size_ = 1;

	void init(int sz) {
		while (size_ <= sz) size_ *= 2;
		dat.resize(size_ * 2, 0LL);
	}
	void update(int pos, long long x) {
		pos += size_; dat[pos] = x;
		while (pos >= 2) {
			pos >>= 1;
			dat[pos] = max(dat[pos * 2], dat[pos * 2 + 1]);
		}
	}
	long long query_(int l, int r, int a, int b, int u) {
		if (l <= a && b <= r) return dat[u];
		if (r <= a || b <= l) return -(1 << 30);
		int v1 = query_(l, r, a, (a + b) >> 1, u * 2);
		int v2 = query_(l, r, (a + b) >> 1, b, u * 2 + 1);
		return max(v1, v2);
	}
	long long query(int l, int r) {
		return query_(l, r, 0, size_, 1);
	}
};

long long N, W;
long long ans[1 << 20], ans2[1 << 20];

int main() {
	scanf("%lld%lld", &N, &W);

	for (int i = 1; i <= N; i++) {
		// 
		long long l, t; vector<long long>e;
		scanf("%lld", &l); e.resize(l, 0);
		for (int j = 0; j < l; j++) scanf("%lld", &e[j]);

		// 
		RangeMax Z; Z.init(l + 2); long long maxn = 0;
		for (int j = 0; j < e.size(); j++) { Z.update(j + 1, e[j]); maxn = max(maxn, e[j]); }

		int c1 = l, c2 = W - 1 - l;
		if (c1 <= c2) {
			long long v = Z.query(1, l + 1);
			ans[c1] += maxn; ans[c2 + 1] -= maxn;
			for (int j = 1; j <= c1 - 1; j++) ans2[j] += 1LL * Z.query(0, j + 1);
			for (int j = c2 + 1; j <= W; j++) ans2[j] += 1LL * Z.query(l - (W - j), l + 2);
		}
		else {
			for (int j = 1; j <= W; j++) {
				int v1 = max(0LL, l - (W - j)), v2 = min(1LL * j + 1LL, 1LL * l + 2LL);
				ans2[j] += 1LL * Z.query(v1, v2);
			}
		}
	}
	for (int i = 1; i <= W + 1; i++) ans[i] += ans[i - 1];
	for (int i = 1; i <= W + 1; i++) ans2[i] += ans[i];
	for (int i = 1; i <= W; i++) { if (i >= 2) printf(" "); printf("%lld", ans2[i]); } printf("\n");
	return 0;
}