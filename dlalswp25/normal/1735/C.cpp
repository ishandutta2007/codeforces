#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];
char ans[101010];
int nxt[30];
int indeg[30];

struct DSU {
	int p[30];

	void init(int n) {
		for(int i = 1; i <= n; i++) p[i] = i;
	}
	
	int par(int x) {
		if(x == p[x]) return x;
		return p[x] = par(p[x]);
	}

	void unite(int a, int b) {
		a = par(a); b = par(b);
		p[a] = b;
	}
}uf;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		uf.init(26);
		for(int i = 1; i <= 26; i++) nxt[i] = indeg[i] = 0;

		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			int c = A[i] - 'a' + 1;
			if(!nxt[c]) { 
				for(int j = 1; j <= 26; j++) {
					if(c == j || indeg[j] || uf.par(c) == uf.par(j)) continue;
					nxt[c] = j; indeg[j]++;
					uf.unite(c, j);
					cnt++;
					if(cnt == 25) {
						int x, y;
						for(int k = 1; k <= 26; k++) {
							if(!indeg[k]) x = k;
							if(!nxt[k]) y = k;
						}
						nxt[y] = x;
					}
					break;
				}
			}
			ans[i] = nxt[c] + 'a' - 1;
		}

		ans[N + 1] = 0;
		printf("%s\n", ans + 1);
	}
	return 0;
}