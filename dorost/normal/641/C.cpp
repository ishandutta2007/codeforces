/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 1012345;
int a[N];

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n, q;
	cin >> n >> q;
	int x = 0, y = 0, z = 0, sum = 0;
	for (int i = 0; i < q; i++) {
		int a;
		cin >> a;
		if (a == 1) {
			int b;
			cin >> b;
			x += b;
			z += b;
			y += b;
			x %= n;
			y %= n;
			z %= n;
		} else {
			if (y % 2 == 0) {
				z++;
				y--;
			} else {
				z--;
				y++;
			}
			x %= n;
			y %= n;
			z %= n;
		}
	}
	for (int i = 0; i < n; i++) {
		a[(i + ((i) % 2 == 0 ? z : y) + n) % n] = i + 1;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << ' ';
	}
	cout << '\n';
}