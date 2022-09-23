#include <bits/stdc++.h>

using namespace std;

int N, M;
int nxt[101010];
int in[101010];
bool chk[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= N; i++) nxt[i] = in[i] = 0;
		for(int i = 1; i <= M; i++) {
			int x, y; scanf("%d%d", &x, &y);
			if(x == y) continue;
			nxt[x] = y;
			in[y]++;
		}
		for(int i = 1; i <= N; i++) chk[i] = false;
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			if(in[i] || chk[i]) continue;
			int x = i;
			int cnt = 0;
			while(1) {
				cnt++; chk[x] = true;
				x = nxt[x];
				if(!x) break;
			}
			ans += cnt - 1;
		}
		for(int i = 1; i <= N; i++) {
			if(!in[i] || chk[i]) continue;
			int r = i, x = i;
			int cnt = 0;
			while(1) {
				cnt++; chk[x] = true;
				x = nxt[x];
				if(x == r) break;
			}
			ans += cnt + 1;
		}
		printf("%d\n", ans);
	}
	return 0;
}