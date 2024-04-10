#include <bits/stdc++.h>

int a, b, c;
bool f[100000010];
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> a >> b >> c; c *= 5;
	f[0] = 1;
	int ans = a;
	for (int i = 1; i <= a; ++i) {
		if (i >= b) f[i] |= f[i - b];
		if (i >= c) f[i] |= f[i - c];
		if (f[i]) ans = std::min(ans, a - i);
	}
	std::cout << ans << std::endl;
	return 0;
}