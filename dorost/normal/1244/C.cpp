/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
#define int long long
const int N = 101234;
int a[N];

int32_t main() {
	int n, p, w, d;
	cin >> n >> p >> w >> d;
	for (int i = 0; i < N; i++)
		a[i] = -1;
	for (int i = 0; i < w; i++) {
		int x = (d * i) % w;
		if (a[x] == -1) {
			a[x] = i;
		}
	}
	if (a[p % w] == -1) {
		cout << -1;
		return 0;
	}
	int y = p - a[p % w] * d;
	if (y < 0 || y % w || y / w + a[p % w] > n) {
		cout << -1;
		return 0;
	}
	cout << y / w << ' ' << a[p % w] << ' ' << n - y / w - a[p % w];
}