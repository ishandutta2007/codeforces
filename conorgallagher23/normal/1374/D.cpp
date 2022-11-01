#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

inline int read() {
	char c = getchar(); int x = 0, f = 1;
	while (c < '0' || c > '9') { if (c == '-') f = -1; c = getchar(); }
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return x * f;
}

map<int, int> cnt;

int main() {
	int T = read();
	while (T--) {
		int n = read(), k = read();
		int ans = 0, pos;
		for (int i = 1; i <= n; i++) {
			int x = read();
			if (x % k == 0) continue;
			x = k - x % k; cnt[x]++;
			if (cnt[x] > ans) ans = cnt[x], pos = x;
			else if (cnt[x] == ans) pos = max(pos, x);
		}
		if (ans) printf("%lld\n", (ll)(ans - 1) * k + pos + 1);
		else puts("0");
		cnt.clear();
	}
	return 0;
}