#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
const int MaxN = 300010;

int n, p[MaxN], q[MaxN]; char s[MaxN];

int main() {
	scanf("%s", s + 1);
	n = strlen(s + 1);
	ll ans = 0;
	for (int r = 1, l; r <= n; r++) {
		for (l = max(r - 2, 0); l >= max(r - 10, 1); l--) {
			bool u = true;
			for (int k = l + 2; k <= r; k += 2) {
				int m = l + k >> 1;
				if (s[l] == s[m] && s[m] == s[k]) {
					u = false;
				}
			}
			if (!u) break;
		}
		ans += l;
	}
	cout << ans << endl;
	return 0;
}