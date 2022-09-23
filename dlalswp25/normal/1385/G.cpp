#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

pii pos[202020][2];
int N;

int cnt[404040];
int p[404040];
int chk[404040];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

void unite(int u, int v) {
	u = par(u); v = par(v);
	if(u == v) return;
	cnt[v] += cnt[u];
	p[u] = v;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			pos[i][0] = pos[i][1] = {0, 0};
		}

		bool ok = true;
		for(int i = 0; i < 2; i++) {
			for(int j = 1; j <= N; j++) {
				int x; scanf("%d", &x);
				if(pos[x][0].second) {
					if(pos[x][1].second) ok = false;
					else pos[x][1] = {i, j};
				}
				else pos[x][0] = {i, j};
			}
		}

		if(!ok) {
			puts("-1");
			continue;
		}

		for(int i = 1; i <= 2 * N; i++) {
			p[i] = i;
			cnt[i] = (i % 2 == 0);
		}

		for(int i = 1; i <= N; i++) {
			int x = pos[i][0].second, y = pos[i][1].second;

			if(x == y) continue;
			if(pos[i][0].first == pos[i][1].first) {
				unite(2 * x, 2 * y - 1);
				unite(2 * x - 1, 2 * y);
			}
			else {
				unite(2 * x, 2 * y);
				unite(2 * x - 1, 2 * y - 1);
			}
		}

		for(int i = 1; i <= 2 * N; i++) chk[i] = -1;

		int ans = 0;
		// for(int i = 1; i <= 2 * N; i++) printf("%d ", cnt[i]); puts("");

		for(int i = 1; i <= N; i++) {
			int a = 2 * i - 1, b = 2 * i;
			a = par(a); b = par(b);
			if(chk[a] != -1) continue;
			else {
				if(cnt[a] < cnt[b]) {
					ans += cnt[a];
					chk[a] = 1;
					chk[b] = 0;
				}
				else {
					ans += cnt[b];
					chk[a] = 0;
					chk[b] = 1;
				}
			}
		}

		ok = true;
		for(int i = 1; i <= N; i++) {
			if(p[2 * i] == p[2 * i - 1]) ok = false;
		}
		if(!ok) { puts("-1"); continue; }

		printf("%d\n", ans);
		int c = 0;
		for(int i = 1; i <= N; i++) {
			if(chk[par(2 * i)] == 1) printf("%d ", i);
		}
		puts("");
	}
	return 0;
}