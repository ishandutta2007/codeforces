#include <bits/stdc++.h>

using namespace std;

const int N = 3e5 + 7;
const int MOD = 1e9 + 7;

int n, x[N];

void add(int &a, int b) {
	if ((a += b) >= MOD) a -= MOD;
	if (a < 0) a += MOD;
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x[i]);
	}
	sort(x, x + n);
	int ss = 0, s = 0, ans = 0;
	for (int i = n - 1; i >= 0; i--) {
		add(ans, ss);
		add(ans, -1LL * x[i] * s % MOD);
		add(s, s);
		add(ss, ss);
		add(ss, x[i]);
		add(s, 1);
	}
	cout << ans << endl;
	return 0;
}