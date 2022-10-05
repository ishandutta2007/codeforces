#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=int(b); i++)
using namespace std;

long long f[1<<10][1<<10], ans;
int n, m, K, u[100], v[100], x, tmp;

int main() {
	scanf("%d%d%d", &n, &m, &K);
	rep (i, 1, m) {
		scanf("%d%d", &u[i], &v[i]);
		u[i+m] = --v[i]; v[i+m] = --u[i];
	}
	rep (i, 1, 2*m) 
		if (!u[i]) f[1<<v[i]|1][1<<v[i]|1] = 1;
	rep (i, 1, (1<<n)-1)
		for (int j=i; j; j=(j-1)&i) if (f[i][j]) {
			rep (k, 1, 2*m) if ((i>>u[k]&1) && !(i>>v[k]&1) && (j&(~(1<<u[k])))<(1<<v[k])) 
				f[i|(1<<v[k])][(j&(~(1<<u[k])))|(1<<v[k])] += f[i][j];
			// printf("%d %d  %lld\n", i, j, f[i][j]);
		}
	rep (i, 1, (1<<n)-1) {
		tmp = 0; x = i;
		while (x) { tmp += x&1; x >>= 1; }
		if (tmp ^ K) continue;
		ans += f[(1<<n)-1][i];
	}
	printf("%lld\n", ans);
	return 0;
}