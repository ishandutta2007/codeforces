/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 102;
int a[N], b[N], c[N], p[N];

void solve() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> a[i], p[i] = -1;
	for (int i = 0; i < n; i++)
		cin >> b[i];
	for (int i = 0; i < n; i++)
		cin >> c[i];
	for (int i = 0; i < n - 1; i++) {
		if (i == 0) 
			p[i] = a[i];
		else 
			if (a[i] != p[i - 1])
				p[i] = a[i];
			else if (b[i] != p[i - 1])
				p[i] = b[i];
			else
				p[i] = c[i];
	}
	if (a[n - 1] != p[0] && a[n - 1] != p[n - 2])
		p[n - 1] = a[n - 1];
	else if (b[n - 1] != p[0] && b[n - 1] != p[n - 2])
		p[n - 1] = b[n - 1];
	else
		p[n - 1] = c[n - 1];
	for (int i = 0; i < n; i++)
		cout << p[i] << ' ';
	cout << '\n';
}

int32_t main() {
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}