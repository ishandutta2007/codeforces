#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, x, m; scanf("%d%d%d", &n, &x, &m);

		int s = x, e = x;

		for(int i = 1; i <= m; i++) {
			int l, r; scanf("%d%d", &l, &r);
			if(r < s || e < l) continue;
			s = min(s, l);
			e = max(e, r);
		}
		printf("%d\n", e - s + 1);
	}
	return 0;
}