#include <bits/stdc++.h>

using namespace std;

const int INF = 1010101010;

int N;
int A[303030];
int D[303030];

struct SEG {
	int base = 262144;
	int T[525252];

	SEG() {
		for(int i = 0; i < 525252; i++) T[i] = INF;
	}

	void upd(int p, int x) {
		p += base;
		T[p] = x;
		while(p > 1) {
			p >>= 1;
			T[p] = min(T[p << 1], T[p << 1 | 1]);
		}
	}

	int get(int p, int q) {
		p += base; q += base;
		int ret = INF;
		while(p <= q) {
			if(p & 1) { ret = min(ret, T[p]); p++; }
			if(~q & 1) { ret = min(ret, T[q]); q--; }
			p >>= 1; q >>= 1;
		}
		return ret;
	}
}segU, segL;

vector<int> U, L;
int usz, lsz;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

	U.push_back(A[1]);
	L.push_back(A[1]);
	segU.upd(0, 0);
	segL.upd(0, 0);
	usz = lsz = 1;

	for(int i = 2; i <= N; i++) {
		// printf("i=%d\n", i);
		// for(int j : U) printf("%d ", j); puts("");
		// for(int j : L) printf("%d ", j); puts("");
		// printf("sz %d %d\n", usz, lsz);

		D[i] = D[i - 1] + 1;

		if(A[i] < A[i - 1]) {
			int t = lower_bound(U.begin(), U.end(), A[i] + 1) - U.begin();
			if(t) t--;
			D[i] = min(D[i], segU.get(t, usz - 1) + 1);
		}

		else {
			int l = 0, r = lsz - 1;
			while(l <= r) {
				int m = l + r >> 1;
				if(L[m] < A[i]) r = m - 1;
				else l = m + 1;
			}
			if(r < 0) r = 0;
			D[i] = min(D[i], segL.get(r, lsz - 1) + 1);
		}

		while(usz) {
			if(U.back() < A[i]) break;
			segU.upd(usz - 1, INF);
			U.pop_back(); usz--;
		}
		segU.upd(usz, D[i]);
		U.push_back(A[i]); usz++;

		while(lsz) {
			if(L.back() > A[i]) break;
			segL.upd(lsz - 1, INF);
			L.pop_back(); lsz--;
		}
		segL.upd(lsz, D[i]);
		L.push_back(A[i]); lsz++;
	}

	// for(int i = 1; i <= N; i++) printf("%d ", D[i]); puts("");
	printf("%d\n", D[N]);

	return 0;
}