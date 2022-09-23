#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;
const int base = 1048576;

int T[4 * 1010101];
int L[505];
int R[505];

ll D[505][505];
int C[1010101];
int N, M;

int bef[505];
vector<int> loc[505];

void maketree() {
	for(int i = 1; i <= M; i++) T[base + i - 1] = C[i];
	for(int i = base - 1; i >= 1; i--) T[i] = min(T[i * 2], T[i * 2 + 1]);
}

int query(int s, int e) {
	int l = base + s, r = base + e;
	l--; r--;

	int ret = N + 1;
	while(l <= r) {
		if(l & 1) { ret = min(ret, T[l]); l++; }
		if(!(r & 1)) { ret = min(ret, T[r]); r--; }
		l >>= 1; r >>= 1;
	}
	return ret;
}

ll f(int l, int r) {
	if(R[r] == L[l]) return 1;
	if(L[l] > R[r]) return 1;
	if(D[l][r] != -1) return D[l][r];
	//printf("%d %d\n", l, r);

	int m = query(L[l], R[r]);

	ll t = 1;
	for(int i = 1; i < loc[m].size(); i++) {
		if(loc[m][i] - loc[m][i - 1] == 1) continue;
		t = t * f(C[loc[m][i - 1] + 1], C[loc[m][i] - 1]) % MOD;
	}

	// printf("%d %d %lld ioewfjowejfjawjwe\n", l, r, t);
	// printf("%d\n", m);

	ll sl = 0, sr = 0;

	int lidx = loc[m][0] - 1;

	if(lidx < L[l]) sl = 1;
	else {
		while(1) {
			if(lidx >= L[l]) sl = (sl + f(C[lidx + 1], C[loc[m][0] - 1]) * f(l, C[lidx])) % MOD;
			else sl = (sl + f(C[lidx + 1], C[loc[m][0] - 1])) % MOD;
			if(lidx < L[l]) break;
			lidx = L[C[lidx]] - 1;
		}
	}

	int ridx = loc[m].back() + 1;
	if(ridx > R[r]) sr = 1;
	else {
		while(1) {
			if(ridx <= R[r]) sr = (sr + f(C[loc[m].back() + 1], C[ridx - 1]) * f(C[ridx], r)) % MOD;
			else sr = (sr + f(C[loc[m].back() + 1], C[ridx - 1])) % MOD;
			if(ridx > R[r]) break;
			ridx = R[C[ridx]] + 1;
		}
	}

	return D[l][r] = t * sl % MOD * sr % MOD;
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= N; i++) { L[i] = M + 1; R[i] = 0; }
	C[M + 1] = N + 1;
	L[N + 1] = R[N + 1] = N + 1;

	for(int i = 1; i <= M; i++) {
		scanf("%d", &C[i]);
		L[C[i]] = min(L[C[i]], i);
		R[C[i]] = max(R[C[i]], i);
		loc[C[i]].push_back(i);
	}

	maketree();

	for(int i = 1; i <= M; i++) {
		if(bef[C[i]] && query(bef[C[i]] + 1, i - 1) < C[i]) { puts("0"); return 0; }
		bef[C[i]] = i;
	}

	for(int i = 1; i <= N; i++) {
		for(int j = 1; j <= N; j++) {
			D[i][j] = -1;
		}
	}

	printf("%lld\n", f(C[1], C[M]));

	return 0;
}