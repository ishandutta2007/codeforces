/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N];

void solve() {
	int n;
	cin >> n;
	cout << (n - 1) / 2 << '\n';
	for (int i = 0; i < n; i++)
		cin >> a[i];
	sort(a, a + n);
	int x = 0, y = n - 1;
	for (int i = 0; i < n; i++) {
		if (i % 2 == 0) {
			cout << a[y] << ' ';
			y--;
		}else{
			cout << a[x] << ' ';
			x++;
		}
	}
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	solve();
}