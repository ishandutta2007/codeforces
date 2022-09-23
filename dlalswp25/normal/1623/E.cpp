#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, K;
char C[202020];
int L[202020];
int R[202020];
int in[202020];
int dfn[202020];
int ed[202020];
int up[202020];
int dep[202020];
int vn[202020];
bool good[202020];
bool chk[202020];
int id;

struct BIT {
	ll T[202020];

	void upd(int x, int v) {
		for(int i = x; i <= N; i += i&-i) T[i] += v;
	}

	void upd(int l, int r, int v) {
		upd(l, v);
		upd(r + 1, -v);
	}

	ll get(int x) {
		ll ret = 0;
		for(int i = x; i; i -= i&-i) ret += T[i];
		return ret;
	}
}fwt;

void dfs(int v, int p) {
	if(!v) return;
	up[v] = p;
	dep[v] = dep[p] + 1;
	dfn[v] = ++id;
	dfs(L[v], v);
	dfs(R[v], v);
	ed[v] = id;
}

void trav(int v) {
	if(!v) return;
	trav(L[v]);
	in[++id] = v;
	trav(R[v]);
}

void print(int v) {
	if(!v) return;
	print(L[v]);
	printf("%c", C[v]);
	if(chk[v]) printf("%c", C[v]);
	print(R[v]);
}

int main() {
	scanf("%d%d", &N, &K);
	scanf("%s", C + 1);
	for(int i = 1; i <= N; i++) scanf("%d%d", &L[i], &R[i]);
	dfs(1, 0);
	for(int i = 1; i <= N; i++) vn[dfn[i]] = i;
	for(int i = 1; i <= N; i++) fwt.upd(i, i, dep[vn[i]]);
	id = 0; trav(1);
	for(int i = N - 1; i >= 1; i--) {
		if(C[in[i]] < C[in[i + 1]]) good[i] = true;
		else if(C[in[i]] == C[in[i + 1]] && good[i + 1]) good[i] = true;
	}

	for(int i = 1; i <= N; i++) {
		int v = in[i];
		if(!chk[v] && !good[i]) {
			fwt.upd(dfn[v], ed[v], 1010101010);
			continue;
		}
		if(good[i]) {
			if(fwt.get(dfn[v]) > K) continue;
			while(v && !chk[v]) {
				K--;
				chk[v] = true;
				fwt.upd(dfn[v], ed[v], -1);
				v = up[v];
			}
		}
	}

	print(1);
	puts("");
	
	return 0;
}