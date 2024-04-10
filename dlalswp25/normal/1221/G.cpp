#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N, M;
vector<int> adj[50];

ll ans = 0;

int A[1050505];
int D[1050505];

ll no[50];
bool chk[50];

int c[50];
bool bi = true;

void precalc(int st, int now, int ed, ll idx) {
	if(now >= ed) {
		A[idx >> st] = 1;
		return;
	}

	if(!(no[now] & idx)) {
		precalc(st, now + 1, ed, idx | (1LL << now));
	}
	precalc(st, now + 1, ed, idx);
}

void dp() {
	for(int i = 0; i < (1 << (N / 2)); i++) D[i] = A[i];
	for(int i = 0; i < N / 2; i++) {
		for(int j = 0; j < (1 << (N / 2)); j++) {
			if(j & (1LL << i)) D[j] += D[j - (1LL << i)];
		}
	}
}

void dfs(int now) {
	chk[now] = true;
	for(int i : adj[now]) {
		if(chk[i]) continue;
		dfs(i);
	}
}

void color(int now) {
	for(int i : adj[now]) {
		if(c[i]) {
			if(c[i] == c[now]) bi = false;
			continue;
		}
		c[i] = 3 - c[now];
		color(i);
	}
}

int main() {
	scanf("%d%d", &N, &M);
	for(int i = 1; i <= M; i++) {
		int a, b; scanf("%d%d", &a, &b);
		adj[a - 1].push_back(b - 1);
		adj[b - 1].push_back(a - 1);
		no[a - 1] |= (1LL << (b - 1));
		no[b - 1] |= (1LL << (a - 1));
	}

	precalc(0, 0, N / 2, 0);
	//for(int i = 0; i < 10; i++) printf("%d ", A[i]); puts("");
	dp();

	for(int i = 0; i < 1050505; i++) A[i] = 0;
	precalc(N / 2, N / 2, N, 0);
	
	ll ret = 0;
	for(ll i = 0; i < (1LL << (N - N / 2)); i++) {
		if(A[i]) {
			int idx = 0;
			for(int j = 0; j < N / 2; j++) {
				if(!((i << (N / 2)) & no[j])) idx |= (1LL << j);
			}
			ret += D[idx];
		}
	}

	ans += 2 * ret;
	ret = 0;

	int com = 0;
	for(int i = 0; i < N; i++) {
		if(!chk[i]) { com++; dfs(i); }
	}

	ans += (1LL << com);

	int com1 = 0;
	for(int i = 0; i < N; i++) {
		if(adj[i].size() == 0) com1++;
	}
	ans -= (1LL << (com1 + 1));

	for(int i = 0; i < N; i++) {
		if(!c[i]) { c[i] = 1; color(i); }
	}
	if(bi) ans -= (1LL << com);

	if(!M) ans += (1LL << N);

	printf("%lld\n", (1LL << N) - ans);

	return 0;
}