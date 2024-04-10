#include <bits/stdc++.h>

using namespace std;

int N, Q;

struct BIT {
	int T[101010];
	int C[101010];

	void add(int x) {
		if(C[x]) { C[x]++; return; }
		for(int i = x; i <= N; i += i&-i) T[i]++;
		C[x] = 1;
	}

	void ers(int x) {
		if(C[x] > 1) { C[x]--; return; }
		for(int i = x; i <= N; i += i&-i) T[i]--;
		C[x] = 0;
	}

	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}

	int query(int l, int r) {
		return get(r) - get(l - 1);
	}
}fwtx, fwty;

int main() {
	scanf("%d%d", &N, &Q);
	while(Q--) {
		int t, x1, y1; scanf("%d%d%d", &t, &x1, &y1);
		if(t == 1) {
			fwtx.add(x1); fwty.add(y1);
		}
		else if(t == 2) {
			fwtx.ers(x1); fwty.ers(y1);
		}
		else {
			int x2, y2; scanf("%d%d", &x2, &y2);
			puts(fwtx.query(x1, x2) == x2 - x1 + 1 || fwty.query(y1, y2) == y2 - y1 + 1 ? "Yes" : "No");
		}
	}
	return 0;
}