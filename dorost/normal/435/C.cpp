/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012;
int a[N];
char ch[N][N];

void solve() {
	int n;
	cin >> n;
	int sum = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		sum += (i % 2 == 0 ? a[i] : -a[i]);
		a[i] = sum;
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			ch[i][j] = ' ';
		}
	}
	int x = *min_element(a + 1, a + n + 1);
	for (int i = 0; i <= n; i++)
		a[i] -= x;
	a[0] = -x;
	int c = 0, w = 0, mxc = 0, mxw = 0;
	for (int i = 1; i < n + 1; i++) {
		if (a[i] > a[i - 1]) {
			c = a[i - 1] + 1;
			for (int j = 0; j < a[i] - a[i - 1]; j++) {
				ch[c][w] = '\\';
				mxc = max(mxc, c);
				mxw = max(mxw, w);
				c++, w++;
			}
		}else {
			c = a[i - 1];
			for (int j = 0; j < a[i - 1] - a[i]; j++) {
				ch[c][w] = '/';
				mxc = max(mxc, c);
				mxw = max(mxw, w);
				c--, w++;
			}
		}
	}
	for (int i = 1; i <= mxc; i++) {
		for (int j = 0; j <= mxw; j++)
			cout << ch[i][j];
		cout << '\n';
	}
}

int32_t main() {
	int t = 1;
//	cin >> t;
	while (t--) {
		solve();
	}
}