#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int b, p, f; scanf("%d%d%d", &b, &p, &f);
		int h, c; scanf("%d%d", &h, &c);

		int ans = 0;
		if(h > c) {
			int q = min(b / 2, p);
			b -= 2 * q;
			p -= q;
			ans += h * q;

			q = min(b / 2, f);
			ans += c * q;
		}
		else {
			int q = min(b / 2, f);
			b -= 2 * q;
			f -= q;
			ans += c * q;

			q = min(b / 2, p);
			ans += h * q;
		}
		printf("%d\n", ans);
	}
	return 0;
}