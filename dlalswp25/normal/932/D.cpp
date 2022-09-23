#include <stdio.h>
#include <algorithm>

using namespace std;

int mx[400005][20];
long long sum[400005][20];
int depth[400005];
int nxt[400005][20];
int par[400005][20];
int len[400005];

int main() {
	int last = 0;
	int Q; scanf("%d", &Q);
	long long R, W, X;
	depth[1] = 1;
	int cnt = 1;
	for(int i = 0; i <= 19; i++) sum[0][i] = ((1LL) << 62);
	for(int i = 1; i <= 19; i++) sum[1][i] = ((1LL) << 62);
	par[1][0] = 0;
	len[1] = 1;

	for(int z = 0; z < Q; z++) {
		int t; scanf("%d", &t);
		long long p, q; scanf("%lld %lld", &p, &q);
		if(t == 1) {
			R = p ^ last, W = q ^ last; cnt++;

			depth[cnt] = depth[R] + 1;
			par[cnt][0] = R;
			for(int i = 1; i <= 19; i++) {
				par[cnt][i] = par[par[cnt][i - 1]][i - 1];
			}
			int now = R;
			for(int i = 19; i >= 0; i--) {
				if(depth[now] < (1 << i)) continue;
				if(mx[now][i] < W) now = par[now][i];
			}
			nxt[cnt][0] = now;
			len[cnt] = len[now] + 1;

			for(int i = 1; i <= 19; i++) {
				nxt[cnt][i] = nxt[nxt[cnt][i - 1]][i - 1];
			}

			mx[cnt][0] = W;
			for(int i = 1; i <= 19; i++) {
				if(depth[cnt] < (1 << i)) mx[cnt][i] = 1000000005;
				else mx[cnt][i] = max(mx[cnt][i - 1], mx[par[cnt][i - 1]][i - 1]);
			}

			sum[cnt][0] = W;
			for(int i = 1; i <= 19; i++) {
				if(len[cnt] < (1 << i)) sum[cnt][i] = ((1LL) << 62); 
				else sum[cnt][i] = sum[cnt][i - 1] + sum[nxt[cnt][i - 1]][i - 1]; 
			}
		}
		else {
			R = p ^ last, X = q ^ last;
			int ans = 0;
			int now = R;
			for(int i = 19; i >= 0; i--) {
				if(sum[now][i] > X) continue;
				ans += (1 << i); X -= sum[now][i];
				now = nxt[now][i];
			}
			printf("%d\n", ans);
			last = ans;
		}
	}
	return 0;
}