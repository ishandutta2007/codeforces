/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 105, M = 45;
int fib[M], cnt[M];
int a[N];
int is[M];

bool valid () {
	bool ans = (is[1] == 2);
	int x = 1;
	for (int i = 2; i < M; i++) {
		if (is[i] != x) {
			x = 0;
		}
		ans &= (is[i] == x);
	}
	return ans;
}

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < M; i++)
		is[i] = 0, cnt[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int cntall = 0;
	for (int i = 0; i < n; i++) {
		while (a[i]) {
			int f = (upper_bound(fib, fib + M, a[i])) - fib - 1;
			if (a[i] == fib[f] && f >= 3 && f % 2 == 1) {
				cnt[f]++;
			}
			a[i] -= fib[f];
			is[f]++;
			cntall++;
		}
	}
	if (cntall == 1 && is[1] == 1) {
		cout << "YES\n";
		return;
	}
	bool ans = valid();
	for (int i = 0; i < M; i++) {
		if (cnt[i]) {
			is[i]--;
			for (int j = i - 1; j >= 0; j -= 2) 
				is[max(j, 1)]++;
			ans |= valid();
			is[i]++;
			for (int j = i - 1; j >= 0; j -= 2) 
				is[max(j, 1)]--;
		}
	}
	cout << (ans ? "YES" : "NO") << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	fib[0] = fib[1] = 1;
	for (int i = 2; i < M; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}