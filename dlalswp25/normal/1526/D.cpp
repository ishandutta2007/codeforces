#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
char A[101010];
int B[101010];
vector<int> V[5];
int X[130];
char Y[5];
int P[5];
int ans[5];

struct FWT {
	int T[101010];

	void init() {
		for(int i = 1; i <= N; i++) T[i] = 0;
	}
	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}
	int get(int x) {
		int ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
	int query(int l, int r) {
		if(r < l) return 0;
		return get(r) - get(l - 1);
	}
}fwt;

ll count_inversions() {
	fwt.init();
	ll ret = 0;
	for(int i = 1; i <= N; i++) {
		ret += fwt.query(B[i] + 1, N);
		fwt.upd(B[i], 1);
	}
	return ret;
}

int main() {
	X['A'] = 0; X['N'] = 1; X['O'] = 2; X['T'] = 3;
	Y[0] = 'A'; Y[1] = 'N'; Y[2] = 'O'; Y[3] = 'T';

	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		for(int i = 0; i < 4; i++) V[i].clear();
		for(int i = 1; i <= N; i++) {
			V[X[A[i]]].push_back(i);
		}
		for(int i = 0; i < 4; i++) P[i] = i;

		ll mx = -1;
		do {
			int idx = 1;
			for(int i = 0; i < 4; i++) {
				for(int j : V[P[i]]) B[idx++] = j;
			}
			ll t = count_inversions();
			if(t > mx) {
				mx = t;
				for(int i = 0; i < 4; i++) ans[i] = P[i];
			}
		} while(next_permutation(P, P + 4));

		for(int i = 0; i < 4; i++) {
			for(int j = 0; j < V[ans[i]].size(); j++) printf("%c", Y[ans[i]]);
		}
		puts("");
	}
	return 0;
}