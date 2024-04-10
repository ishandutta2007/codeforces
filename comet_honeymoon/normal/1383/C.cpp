#include <bits/stdc++.h>
using namespace std;

int n;
char s[100005], t[100005];
int fa[20];
int find(int x) { return fa[x] == x ? x : fa[x] = find(fa[x]); }
int G[20];
int sG[1 << 20];
int f[1 << 20];
void solve() {
	scanf("%d\n%s\n%s", &n, s + 1, t + 1);
	for (int c = 0; c < 20; c++) G[c] = 1 << c, fa[c] = c;
	for (int i = 1; i <= n; i++) {
		fa[find(s[i] - 'a')] = find(t[i] - 'a');
		G[s[i] - 'a'] |= (1 << (t[i] - 'a'));
	}
	sG[0] = 0;
	for (int i = 0; i < 20; i++)
	for (int s = 0; s < 1 << i; s++)
		sG[s | (1 << i)] = sG[s] | G[i];

	memset(f, 0, sizeof(f));
	f[0] = 1;
	int ans = 0;
	for (int s = 0; s < 1 << 20; s++) if (f[s]) {
		ans = max(ans, __builtin_popcount(s));
		for (int u = 0; u < 20; u++) if (!((sG[s] >> u) & 1))
			f[s | (1 << u)] = 1;
	}
	ans = 20 - ans;
	for (int c = 0; c < 20; c++) ans += fa[c] != c;
	printf("%d\n", ans);
}

int main() {
	int T;
	scanf("%d", &T);
	while (T--) solve();
}