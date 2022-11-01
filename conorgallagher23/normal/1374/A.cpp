#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

int main() {
	int T = read();
	while (T--) {
		int x = read(), y = read(), n = read();
		int tmp = n / x, ans;
		if (tmp * x + y <= n) ans = tmp * x + y;
		else ans = (tmp - 1) * x + y;
		printf("%d\n", ans); 
	} 
	return 0;
}