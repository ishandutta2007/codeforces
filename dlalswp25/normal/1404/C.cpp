#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, Q;
int A[303030];
int C[303030];

vector<pii> qs[303030];
int ans[303030];
vector<int> v[303030];

struct FWT {
	int T[303030];

	void upd(int x, int v) {
		for(int i = x; i <= N + 1; i += i&-i) T[i] += v;
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt1, fwt2;

int main() {
	scanf("%d%d", &N, &Q);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	for(int i = 1; i <= N; i++) {
		if(A[i] > i) { C[i] = 0; fwt1.upd(1, 1); continue; }
		int l = 0, r = i - 1;
		while(l <= r) {
			int m = l + r >> 1;
			if(fwt1.get(m + 1) >= A[i]) r = m - 1;
			else l = m + 1;
		}

		C[i] = l;
		fwt1.upd(l + 1, 1);
	}

	// for(int i = 1; i <= N; i++) printf("%d ", C[i]); puts("");

	for(int i = 1; i <= Q; i++) {
		int x, y; scanf("%d%d", &x, &y);
		qs[x].emplace_back(N - y, i);
	}

	for(int i = 1; i <= N; i++) v[C[i]].push_back(i);

	for(int i = 0; i <= N; i++) {
		for(int j : v[i]) { fwt2.upd(j, 1); }
		for(pii j : qs[i]) {
			ans[j.second] = j.first - fwt2.get(j.first);
		}
	}

	for(int i = 1; i <= Q; i++) printf("%d\n", ans[i]);

	return 0;
}