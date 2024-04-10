#include <bits/stdc++.h>
using namespace std;
 
const int maxn = 1000005, p = 998244353;
 
int n;
int a[maxn];
vector<int> G[maxn];
 
int ans; bool flg;
 
int dfs(int x, int fa, int k) {
	int tot = G[x].size();
	for (int y : G[x]) if (y != fa) tot -= dfs(y, x, k);
	if (tot % k && (tot - 1) % k) flg = 0;
	if (tot % k == 0) {
		ans = __gcd(ans, tot);
		return 1;
	}
	else {
		ans = __gcd(ans, tot - 1);
		return 0;
	}
}
 
int main() {
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) a[i] = 0, G[i].clear();
		for (int i = 1; i < n; i++) {
			int u, v; scanf("%d%d", &u, &v);
			G[u].push_back(v);
			G[v].push_back(u);
		}
 
		int X = n - 1;
		for (int i = 2; i * i <= X; i++) if (X % i == 0) {
			flg = 1; ans = 0;
			dfs(1, 0, i);
			if (flg) a[ans] = 1;
			while (X % i == 0) X /= i;
		}
 
		if (X != 1) {
			flg = 1;
			ans = 0;
			dfs(1, 0, X);
			if (flg) a[ans] = 1;
		}
 
		a[1] = 1;
		for (int i = 1; i <= n - 1; i++) a[1] = (a[1] + a[1]) % p;
		for (int i = 2; i <= n; i++) a[1] = (a[1] - a[i] + p) % p;
 
		for (int i = 1; i <= n; i++) printf("%d ", a[i]); printf("\n");
	}
}