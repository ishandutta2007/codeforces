#include <bits/stdc++.h>

using namespace std;

const int MOD = 998244353;

int N;
int A[1010][505];
int cnt[505][505];
vector<int> V[505][505];
int chk[1010];

int p[1010];
int other[1010];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int a, int b) {
	a = par(a); b = par(b);
	p[a] = b;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				V[i][j].clear();
				cnt[i][j] = 0;
			}
		}
		for(int i = 1; i <= 2 * N; i++) chk[i] = 0;

		for(int i = 1; i <= 2 * N; i++) {
			for(int j = 1; j <= N; j++) {
				scanf("%d", &A[i][j]);
				V[j][A[i][j]].push_back(i);
				cnt[j][A[i][j]]++;
			}
		}

		while(1) {
			int x = 0, y = 0;
			for(int i = 1; i <= N; i++) {
				if(x) break;
				for(int j = 1; j <= N; j++) {
					if(cnt[i][j] == 1) {
						x = i; y = j; break;
					}
				}
			}
			if(!x) break;

			int t = 0;
			for(int i : V[x][y]) {
				if(!chk[i]) { t = i; break; }
			}
			if(!t) return 0;
			chk[t] = 1;
			V[x][y].clear();

			for(int i = 1; i <= N; i++) {
				if(i == x) continue;
				for(int j : V[i][A[t][i]]) {
					if(j == t) continue;
					if(!chk[j]) {
						chk[j] = -1;
						for(int k = 1; k <= N; k++) {
							cnt[k][A[j][k]]--;
						}
					}
				}
				V[i][A[t][i]].clear();
				cnt[i][A[t][i]] = 0;
			}

			cnt[x][y] = 0;
		}

		for(int i = 1; i <= 2 * N; i++) {
			if(chk[i]) p[i] = 0;
			else p[i] = i;
		}

		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(cnt[i][j] != 2) continue;
				vector<int> tmp;
				for(int k : V[i][j]) {
					if(!chk[k]) tmp.push_back(k);
				}
				V[i][j] = tmp;
			}
		}

		for(int i = 1; i <= N; i++) {
			if(cnt[1][i] != 2) continue;
			other[V[1][i][0]] = V[1][i][1];
			other[V[1][i][1]] = V[1][i][0];
		}

		for(int i = 2; i <= N; i++) {
			for(int j = 1; j <= N; j++) {
				if(cnt[i][j] != 2) continue;
				unite(V[i][j][0], other[V[i][j][1]]);
				unite(V[i][j][1], other[V[i][j][0]]);
			}
		}

		int ans = 1;
		for(int i = 1; i <= 2 * N; i++) {
			if(chk[i]) continue;
			if(p[i] == i) {
				if(chk[par(other[i])]) continue;
				else {
					ans = ans * 2 % MOD;
					chk[i] = 1;
				}
			}
		}
		for(int i = 1; i <= 2 * N; i++) {
			if(chk[i]) continue;
			if(chk[par(i)]) chk[i] = true;
		}

		printf("%d\n", ans);
		for(int i = 1; i <= 2 * N; i++) {
			if(chk[i] == 1) printf("%d ", i);
		}
		puts("");
	}
	return 0;
}