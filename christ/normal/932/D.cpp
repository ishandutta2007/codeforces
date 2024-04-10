#include <bits/stdc++.h>
using namespace std;
const int MN = 4e5 + 5, LOG = 20;
int p[MN][LOG], p2[MN][LOG], mx[MN][LOG], w[MN]; long long sum[MN][LOG];
int main () {
	int q;
	scanf ("%d",&q);
	long long last = 0; int cnt = 1;
	while (q--) {
		int t; long long pp, qq;
		scanf ("%d %lld %lld",&t,&pp,&qq);
		pp ^= last; qq ^= last;
		if (t == 1) {
			++cnt;
			p[cnt][0] = pp; mx[cnt][0] = w[pp]; w[cnt] = (int)qq;
			for (int j = 1; j < LOG; j++) {
				p[cnt][j] = p[p[cnt][j-1]][j-1];
				mx[cnt][j] = max(mx[cnt][j-1],mx[p[cnt][j-1]][j-1]);
			}
			int cur = cnt;
			for (int j = LOG-1; j >= 0; j--) {
				if (p[cur][j] && mx[cur][j] < qq) {
					cur = p[cur][j];
				}
			}
			p2[cnt][0] = p[cur][0]; sum[cnt][0] = w[cnt];
			for (int j = 1; j < LOG; j++) {
				p2[cnt][j] = p2[p2[cnt][j-1]][j-1];
				sum[cnt][j] = sum[cnt][j-1] + sum[p2[cnt][j-1]][j-1];
			}
		} else {
			long long sofar = 0;
			int cur = pp, ret = 0;
			for (int j = LOG - 1; j >= 0; j--) {
				if (p2[cur][j] && sofar + sum[cur][j] <= qq)
					sofar += sum[cur][j], cur = p2[cur][j], ret += 1<<j;
			}
			if (sofar + w[cur] <= qq) {
				++ret;
				sofar += w[cur];
			}
			printf ("%lld\n",last = ret);
		}
	}
	return 0;
}