#include <bits/stdc++.h>

using namespace std;

int Q;
int N;
int p[505050];
int rt[505050];
int ans[505050];

int par(int x) {
	if(x == p[x]) return x;
	return p[x] = par(p[x]);
}

int main() {
	scanf("%d", &Q);
	while(Q--) {
		int t, x; scanf("%d%d", &t, &x);
		if(t == 1) {
			N++;
			if(!rt[x]) {
				rt[x] = N;
				p[N] = N;
			}
			else {
				p[N] = rt[x];
			}
		}
		else {
			int y; scanf("%d", &y);
			if(x == y) continue;
			if(!rt[y]) rt[y] = rt[x];
			else p[rt[x]] = rt[y];
			rt[x] = 0;
		}
	}

	for(int i = 1; i <= 500000; i++) {
		if(rt[i]) ans[rt[i]] = i;
	}
	for(int i = 1; i <= N; i++) {
		int t = par(i);
		if(t != i) ans[i] = ans[t];
	}
	for(int i = 1; i <= N; i++) printf("%d ", ans[i]); puts("");
	return 0;
}