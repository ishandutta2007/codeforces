/*  * In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 5012345;
int a[N], ps[N], f[N];

void solve() {
	int r, l;
	cin >> r >> l;
	cout << ps[r] - ps[l] << ' ';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	f[1] = true;
	a[1] = 0;
	for (int i = 2; i < N; i++) {
		if (f[i])
			continue;
		for (int j = i; j < N; j += i) {
			if (j != i)
				f[j] = true;
			int x = j, s = 0;
			while (x % i == 0)
				x /= i, s++;
			a[j] += s;
		}
	}
	ps[0] = a[0];
	for (int i = 1; i < N; i++) {
		ps[i] = ps[i - 1] + a[i];
	}
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}