#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;

pii op[2200000];
int CNT;
int M(int A, int B) {
	if (A && B) { op[++CNT] = pii(A, B); return CNT; }
	return A + B;
}

struct block {
	int n;
	int val[512];
	vector<int> f;
	block () {}
	block (int tval[], int tn) {
		n = tn;
		if (n == 1) {
			val[0] = tval[0];
			f.push_back(tval[0]);
			return;
		}
		int mid = n / 2;
		block L(tval, mid), R(tval + mid, n - mid);
		merge(L.val, L.val + L.n, R.val, R.val + R.n, val);
		f.resize(n * (n + 1) / 2);
		for (int r = 0; r < n; r++)
		for (int l = 0; l <= r; l++)
			f[l + (r + 1) * r / 2] = M(L.query(val[l], val[r]), R.query(val[l], val[r]));
	}
	int query(int L, int R) const {
		L = lower_bound(val, val + n, L) - val;
		R = upper_bound(val, val + n, R) - val - 1;
		return L <= R ? f[L + (R + 1) * R / 2] : 0;
	}
};

int n, cntB;
int pos[4100], ans[66000];
block s[512];

int main() {
	int q;

	scanf("%d%d", &n, &q);
	cntB = ((n - 1) >> 8) + 1;
	CNT = n;

	for (int i = 1; i <= n; i++) {
		int x; scanf("%d", &x);
		pos[x] = i;
	}
	for (int i = 0; i < cntB; i++) {
		int L = (i << 8) + 1, R = min((i + 1) << 8, n);
		int lis[512]; memset(lis, 0, sizeof(lis));
		for (int j = L; j <= R; j++) lis[j - L] = pos[j];
		s[i] = block(lis, R - L + 1);
	}

	for (int i = 1; i <= q; i++) {
		int l, r; scanf("%d%d", &l, &r);
		for (int j = 0; j < cntB; j++)
			ans[i] = M(ans[i], s[j].query(l, r));
	}

	printf("%d\n", CNT);
	for (int i = n + 1; i <= CNT; i++) printf("%d %d\n", op[i].first, op[i].second);
	for (int i = 1; i <= q; i++) printf("%d ", ans[i]);
}