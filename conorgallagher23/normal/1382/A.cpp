#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 1005;

bool vis[N];

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read(); int ans = -1;
		for (int i = 0; i < N; i++) vis[i] = false;
		for (int i = 1; i <= n; i++) {
			int x = read(); vis[x] = true;
		}
		for (int i = 1; i <= m; i++) {
			int x = read(); if (vis[x]) ans = x;
		}
		if (ans != -1) puts("YES"), printf("1 %d\n", ans); else puts("NO");
	}
	return 0;
}