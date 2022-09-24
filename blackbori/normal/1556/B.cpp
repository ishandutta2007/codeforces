#include <bits/stdc++.h>

using namespace std;
using ll = long long;

int A[101010], B[101010];

void tc() {
	int n, i, a, b, x, y;
	ll s, s1, s2;
	cin >> n;
	a = b = 0;
	for (i = 1; i <= n; i++) {
		cin >> A[i]; A[i] &= 1;
		if (A[i]) B[a++] = b;
		else b++;
	}
	if (a + a - 1 > n || b + b - 1 > n) {
		cout << "-1\n";
		return;
	}
	if (n & 1) {
		x = y = s = 0;
		for (i = 1; i <= n; i++) {
			if ((i & 1) ^ (a < b)) {
				s += abs(B[x++] - y);
			}
			else y++;
		}
	}
	else {
		x = y = s1 = 0;
		for (i = 1; i <= n; i++) {
			if (i & 1) s1 += abs(B[x++] - y);
			else y++;
		}
		x = y = s2 = 0;
		for (i = 1; i <= n; i++) {
			if (~i & 1) s2 += abs(B[x++] - y);
			else y++;
		}
		s = min(s1, s2);
	}
	cout << s << "\n";
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t = 1;

	cin >> t;

	for (; t--; ) {
		tc();
	}

	return 0;
}