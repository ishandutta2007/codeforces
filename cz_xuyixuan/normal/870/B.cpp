#include<bits/stdc++.h>
using namespace std;
#define MAXN	100005
#define INF	1e9
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int n, k, a[MAXN];
int scc[MAXN], nxt[MAXN];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	if (k == 1) {
		int ans = INF;
		for (int i = 1; i <= n; i++)
			ans = min(ans, a[i]);
		cout << ans << endl;
		return 0;
	}
	if (k >= 3) {
		int ans = -INF;
		for (int i = 1; i <= n; i++)
			ans = max(ans, a[i]);
		cout << ans << endl;
		return 0;
	}
	int ans = max(a[1], a[n]);
	scc[1] = a[1];
	for (int i = 2; i <= n; i++) {
		scc[i] = min(scc[i - 1], a[i]);
		if (scc[i] == a[i]) ans = max(ans, a[i]);
	}
	nxt[n] = a[n];
	for (int i = n - 1; i >= 1; i--) {
		nxt[i] = min(nxt[i + 1], a[i]);
		if (nxt[i] == a[i]) ans = max(ans, a[i]);
	}
	cout << ans << endl;
	return 0;
}