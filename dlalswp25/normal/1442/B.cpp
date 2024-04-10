#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, K;
int A[202020];
int B[202020];
int pos[202020];
int bpos[202020];

struct DSU {
	int p[202020];

	void init() {
		for(int i = 0; i <= N + 1; i++) p[i] = i;
	}

	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		if(a != b) p[a] = b;
	}
}ufl, ufr;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			pos[A[i]] = i;
			bpos[i] = 0;
		}
		for(int i = 1; i <= K; i++) {
			scanf("%d", &B[i]);
			B[i] = pos[B[i]];
			bpos[B[i]] = i;
		}

		ll ans = 1;

		ufl.init(); ufr.init();
		for(int i = 1; i <= K; i++) {
			int l = ufl.par(B[i] - 1);
			int r = ufr.par(B[i] + 1);
			int c = 0;
			if(l && bpos[l] < i) c++;
			if(r <= N && bpos[r] < i) c++;
			int x;

			// printf("l r %d %d\n", l, r);

			// printf("%d %d\n", i, c);

			if(c == 0) ans = 0;
			else if(c == 1) {
				if(l && bpos[l] < i) x = l;
				else x = r;
			}
			else {
				ans = ans * 2 % MOD;
				x = l;
			}

			if(c) {
				l = ufl.par(x - 1);
				r = ufr.par(x + 1);
				ufl.unite(x, l);
				ufr.unite(x, r);
			}
		}
		printf("%lld\n", ans);
	}
	return 0;
}