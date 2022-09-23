#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

const ll MOD = 998244353;

int N, M;
vector<int> adj[1010];
vector<int> rev[1010];
ll A[1010];
int delta[1010];
bool chk[1010];
ll ans;

void run(int t, bool fg) {
	for(int i = 1; i <= N; i++) {
		delta[i] = (A[i] ? -1 : 0);
		for(int j : rev[i]) delta[i] += !!A[j];
	}

	if(!fg) {
		for(int i = 1; i <= N; i++) A[i] = A[i] + (ll)delta[i] * t;
		ans = (ans + 1) % MOD;
		return;
	}

	for(int i = 1; i <= N; i++) {
		if(chk[i]) continue;
		A[i] = (A[i] + MOD + (ll)delta[i] * t) % MOD;
		if(!A[i]) A[i] = MOD;
	}
	ans = (ans + t) % MOD;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) scanf("%lld", &A[i]);
		for(int i = 1; i <= N; i++) {
			adj[i].clear();
			rev[i].clear();
			chk[i] = false;
		}
		ans = 0;
		for(int i = 1; i <= M; i++) {
			int a, b; scanf("%d%d", &a, &b);
			adj[a].push_back(b);
			rev[b].push_back(a);
		}

		for(int k = 1; k <= N; k++) {
			for(int i = 1; i <= N; i++) {
				if(chk[i] || A[i]) continue;
				chk[i] = true;
				for(int j : rev[i]) {
					if(!chk[j]) chk[i] = false;
				}
			}
		}

		while(1) {
			while(1) {
				for(int i = 1; i <= N; i++) {
					if(chk[i] || A[i]) continue;
					chk[i] = true;
					for(int j : rev[i]) {
						if(!chk[j]) chk[i] = false;
					}
				}
				bool ok = true;
				for(int i = 1; i <= N; i++) if(!chk[i] && !A[i]) ok = false;
				if(ok) break;
				run(1, false);
			}

			bool fin = true;
			for(int i = 1; i <= N; i++) if(!chk[i]) fin = false;
			if(fin) break;

			ll t = 1010101010;
			vector<int> tmp;
			for(int i = 1; i <= N; i++) {
				if(chk[i]) continue;
				bool ok = true;
				for(int j : rev[i]) if(!chk[j]) ok = false;
				if(!ok) continue;
				if(t > A[i]) {
					tmp.clear();
					tmp.push_back(i);
					t = A[i];
				}
				else if(t == A[i]) tmp.push_back(i);
			}
			run(t, true);
			for(int i : tmp) { A[i] = 0; chk[i] = true; }
		}

		printf("%lld\n", ans);
	}
	return 0;
}