#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
 
const int maxn = 2009;
int w[maxn][maxn], vis[maxn], n, k;
LL dis[maxn], mn, best = 1LL << 62;;
 
int main() {
	scanf("%d", &n);
	for (int i=1; i<=n; i++)
		for (int j=i+1; j<=n; j++) {
			scanf("%d", &w[i][j]);
			w[j][i] = w[i][j];
			best = min(best, 1LL * w[i][j]);
		}
	for (int i=1; i<=n; i++) {
		mn = 1LL << 62;
		for (int j=1; j<=n; j++) {
			w[i][j] -= best;
			if (i != j) mn = min(mn, (1LL * w[i][j]) << 1);
		}
		dis[i] = mn;
	}
	for (int i=1; i<=n; i++) {
		k = 0;
		for (int j=1; j<=n; j++)
			if (!vis[j] && (!k || dis[j] < dis[k])) k = j;
		vis[k] = 1;
		for (int j=1; j<=n; j++)
			if (!vis[j]) dis[j] = min(dis[j], dis[k] + w[k][j]);
	}
	for (int i=1; i<=n; i++) printf("%lld\n", dis[i] + (n-1) * best);
	return 0;
}