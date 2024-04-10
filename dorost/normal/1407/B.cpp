/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1023;
int a[N];
bool mark[N];

void solve() {
	int n;
	cin >> n;
	int an = -1, mx = 0;
	for (int i = 0; i <= n + 10; i++)
		mark[i] = 0;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (a[i] > mx) {
			mx = a[i];
			an = i;
		}
	}
	cout << mx << ' ';
	mark[an] = 1;
	int b = mx;
	for (int i = 0; i < n - 1; i++) {
		int an1 = -1, mx = 0;
		for (int j = 0; j < n; j++) {
			if (mark[j])
				continue;
			int d = __gcd(b, a[j]);
			if (d > mx) {
				mx = d;
				an1 = j;
			}
		}
		cout << a[an1] << ' ';
		mark[an1] = 1;
		b = __gcd(b, a[an1]);
	}
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}