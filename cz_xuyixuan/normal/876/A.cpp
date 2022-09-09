#include<bits/stdc++.h>
using namespace std;
#define MAXN	5005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
int main() {
	int n, a, b, c, ans = 0, pos = 1;
	read(n), read(a), read(b), read(c);
	for (int i = 2; i <= n; i++) {
		if (pos == 1) {
			if (a <= b) ans += a, pos = 2;
			else ans += b, pos = 3;
		} else if (pos == 2) {
			if (a <= c) ans += a, pos = 1;
			else ans += c, pos = 3;
		} else {
			if (c <= b) ans += c, pos = 2;
			else ans += b, pos = 1;
		}
	}
	cout << ans << endl;
	return 0;
}