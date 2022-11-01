#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9'){ if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int T = read();
	while (T--) {
		int n = read(), m = read();
		printf("%d\n", min({ n, m, (n + m) / 3 }));
	}
	return 0;
}