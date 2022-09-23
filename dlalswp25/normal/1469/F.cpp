#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const int MX = 1000000;

int N, K;
ll A[202020];

struct FWT {
	int T[1010101] = {0, };

	void init() {
		for(int i = 1; i <= MX; i++) T[i] = 0;
	}

	void upd(int x, int v) {
		for(int i = x; i <= MX; i += i&-i) T[i] += v;
	}
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	void upd(int l, int r, int v) {
		// printf("%d %d %d\n", l, r, v);
		if(r < l) return;
		upd(l, v);
		upd(r + 1, -v);
	}
}fwt;

bool solve(int x) {
	if(!x) return false;
	fwt.init();

	int add = A[1];
	add = min(add, 2 * x - 1);
	int tot = add - 1;

	if(add & 1) fwt.upd(2, (add - 1) / 2 + 1, 2);
	else {
		fwt.upd(2, add / 2, 2);
		fwt.upd(add / 2 + 1, add / 2 + 1, 1);
	}

	if(tot >= K) return true;

	// printf("%d\n", x);

	int p = 2;
	int i = 2;
	while(p < x - 1 && i <= N) {
		if(!fwt.get(p)) { p++; continue; }
		add = A[i];
		add = min(add, 2 * (x - p - 1) + 1);
		tot += add - 2;

		fwt.upd(p, p, -1);
		if(add & 1) fwt.upd(p + 2, p + 1 + add / 2, 2);
		else {
			fwt.upd(p + 2, p + 1 + (add - 1) / 2, 2);
			fwt.upd(p + 1 + add / 2, p + 1 + add / 2, 1);
		}
		if(tot >= K) return true;
		i++;
	}
	return tot >= K;
}

int main() {
	scanf("%d%d", &N, &K);
	for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);
	ll s = 1;
	for(int i = 1; i <= N; i++) s += A[i] - 2;
	if(s < K) { puts("-1"); return 0; }

	int l = 0, r = MX;
	while(l <= r) {
		int m = l + r >> 1;
		if(solve(m)) r = m - 1;
		else l = m + 1;
	}
	printf("%d\n", l);

	return 0;
}