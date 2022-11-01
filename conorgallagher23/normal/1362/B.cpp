#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

const int N = 1055;

int n, a[N], b[N];

bool check(int t) {
	for (int i = 1; i <= n; i++) b[i] = a[i] ^ t;
	sort(b + 1, b + n + 1);
	for (int i = 1; i <= n; i++)
		if (a[i] != b[i]) return false;
	return true;
}

int main() {
	int T = read();
	while (T--) {
		n = read();
		for (int i = 1; i <= n; i++) a[i] = read();
		sort(a + 1, a + n + 1);
		bool flag = false;
		for (int i = 1; i < 1024; i++)
			if (check(i)) {
				flag = true;
				printf("%d\n", i);
				break;
			}
		if (!flag) printf("-1\n");
	}
	return 0;
}