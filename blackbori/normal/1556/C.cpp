#include <bits/stdc++.h>

using namespace std;
using ll = long long;

ll A[1010], S[1010];

void tc() {
	ll n, i, l, r, tl, j, a;
	cin >> n; a = 0;
	for (i = 1; i <= n; i++) {
		cin >> A[i];
		if (i & 1) S[i] = S[i - 1] + A[i];
		else S[i] = S[i - 1] - A[i];
		if (~i & 1) {
			r = S[i - 1] - 1; l = S[i];
			for (j = i - 2; j >= 0 && l <= r; j -= 2) {
				tl = S[j];
				a += max(0ll, r - max(l, tl) + 1);
				r = min(r, tl);
			}
		}
	}
	cout << a << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);	

	int t = 1;

//	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}