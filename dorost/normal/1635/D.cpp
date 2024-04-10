/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234, M = 1000 * 1000 * 1000 + 7;
int a[N];
vector <bool> b[N];
bool f[N];
int fib[N], ps[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie();
	cout.tie();
	fib[0] = 1;
	fib[1] = 1;
	ps[0] = 1;
	ps[1] = 2;
	for (int i = 2; i < N; i++) {
		fib[i] = fib[i - 1] + fib[i - 2];
		if (fib[i] >= M)
			fib[i] -= M;
		ps[i] = ps[i - 1] + fib[i];
		if (ps[i] >= M)
			ps[i] -= M;
	}
	int n, p;
	cin >> n >> p;
	for (int i = 0; i < n; i++) 
		cin >> a[i];
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		int x = a[i];
		while (x) {
			b[i].push_back(x % 2);
			x /= 2;
		}
		reverse(b[i].begin(), b[i].end());
	}
	for (int i = 0; i < n; i++) {
		if (f[i])
			continue;
		int y = 0;
		for (int j = 0; j < (int)b[i].size() - 1; j++) {
			if (f[i])
				break;
			y *= 2;
			y += b[i][j];
			int k2 = lower_bound(a, a + n, y) - a;
			bool k = true;
			if (k2 == n || a[k2] != y)
				k = false;
			if (k) {
				int x = 0;
				bool h = true;
				for (int k = j + 1; k < b[i].size(); k++) {
					if (b[i][k] == 0)
						x++;
					else {
						if (x % 2) {
							h = false;
							break;
						}
						x = 0;
					}
				}
				h &= (x % 2 == 0);
				if (h) {
					f[i] = true;
				}
			}
		}
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (!f[i]) {
			int s = b[i].size();
			if (s > p)
				continue;
			ans += ps[p - s];
			if (ans >= M)
				ans -= M;
		}
	}
	cout << ans;
}