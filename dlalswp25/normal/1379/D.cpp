#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int A[202020];
vector<int> v;
int N, H, M, K, X;

pii B[202020];
int C[202020];

struct NODE {
	int lz;
	int x;

	NODE() : lz(0), x(0) {}
};

struct SEG {
	NODE T[4 * 202020];

	void propa(int idx, int s, int e) {
		T[idx].x += T[idx].lz;
		if(s != e) {
			T[idx << 1].lz += T[idx].lz;
			T[idx << 1 | 1].lz += T[idx].lz;
		}
		T[idx].lz = 0;
	}

	void upd(int idx, int s, int e, int p, int q) {
		propa(idx, s, e);
		if(q < p || q < s || e < p) return;
		if(p <= s && e <= q) {
			T[idx].lz++;
			propa(idx, s, e);
			return;
		}
		int m = s + e >> 1;
		upd(idx << 1, s, m, p, q);
		upd(idx << 1 | 1, m + 1, e, p, q);
		T[idx].x = min(T[idx << 1].x, T[idx << 1 | 1].x);
	}

	int fd(int idx, int s, int e, int x) {
		propa(idx, s, e);
		if(s == e) return s;
		int m = s + e >> 1;
		if(T[idx << 1].x + T[idx << 1].lz == x) return fd(idx << 1, s, m, x);
		return fd(idx << 1 | 1, m + 1, e, x);
	}
}seg;

int vget(int x) {
	return lower_bound(v.begin(), v.end(), x) - v.begin() + 1;
}

int main() {
	scanf("%d%d%d%d", &N, &H, &M, &K);

	for(int i = 1; i <= N; i++) {
		int x; scanf("%*d%d", &x);
		x %= (M / 2);

		C[i] = x;

		int y = x + 1;
		x = x + K;

		if(y < 0) y += M / 2;
		if(y >= M / 2) y -= M / 2;
		if(x < 0) x += M / 2;
		if(x >= M / 2) x -= M / 2;

		B[i] = {y, x};

		v.push_back(y); v.push_back(x);
	}

	if(K == 1) { printf("0 0\n"); return 0; }

	v.push_back(0);

	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());

	// for(int i : v) printf("%d ", i); puts("");

	for(int i = 0; i < v.size(); i++) A[i + 1] = v[i];

	X = v.size();

	for(int i = 1; i <= N; i++) {
		B[i].first = vget(B[i].first);
		B[i].second = vget(B[i].second) - 1;
		if(B[i].second <= 0) B[i].second += X;

		// printf("%d %d\n", B[i].first, B[i].second);

		if(B[i].first <= B[i].second) {
			seg.upd(1, 1, X, B[i].first, B[i].second);
		}
		else {
			seg.upd(1, 1, X, B[i].first, X);
			seg.upd(1, 1, X, 1, B[i].second);
		}
	}

	int ans = seg.T[1].x;
	int tm = A[seg.fd(1, 1, X, ans)];
	printf("%d %d\n", ans, tm);

	for(int i = 1; i <= N; i++) {
		int s = tm - K + 1, e = tm - 1;
		if(s >= M / 2) s -= M / 2;
		if(s < 0) s += M / 2;
		if(e >= M / 2) e -= M / 2;
		if(e < 0) e += M / 2;

		if(s <= e) {
			if(s <= C[i] && C[i] <= e) printf("%d ", i);
		}
		else {
			if(s <= C[i] || C[i] <= e) printf("%d ", i);
		}
	}
	puts("");

	return 0;
}