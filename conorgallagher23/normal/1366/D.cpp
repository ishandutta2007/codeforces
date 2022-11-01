#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 5e5 + 5, M = 1e7 + 5;

int n, p[M], mn[M], ans1[N], ans2[N];
bool np[M];

void sieve(int l) {
	int cnt = 0;
	for (int i = 2; i <= l; i++) {
		if (!np[i]) p[++cnt] = mn[i] = i;
		for (int j = 1; j <= cnt && i * p[j] <= l; j++) {
			mn[i * p[j]] = p[j], np[i * p[j]] = true;
			if (i % p[j] == 0) break;
		}
	}
}

int main() {
	sieve(1e7);
	n = read();
	for (int i = 1; i <= n; i++) {
		int x = read();
		if (!np[x]) ans1[i] = ans2[i] = -1;
		else {
			int tmp = mn[x], now = 1;
			while (x % tmp == 0) { x /= tmp; now *= tmp; }
			if (x == 1) ans1[i] = ans2[i] = -1;
			else { ans1[i] = x; ans2[i] = now; }
		}
	}
	for (int i = 1; i <= n; i++) printf("%d%c", ans1[i], " \n" [i == n]);
	for (int i = 1; i <= n; i++) printf("%d%c", ans2[i], " \n" [i == n]);
	return 0;
}