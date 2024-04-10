/* 	* In the name of GOD 
	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 101234;
int a[N], nx[N], lx[N], nm[N], lm[N], nm2[N], lm2[N];

int32_t main() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	a[n] = -1;
	for (int i = 0; i < n; i++) {
		int x = i;
		i++;
		while (a[i] >= a[i - 1]) {
			i++;
		}
		i--;
		for (int j = x; j <= i; j++) {
			nx[j] = j - x + 1;
		}
//		cout << x << ' ' << i << '\n';
	}
	for (int i = n - 1; i >= 0; i--) {
		int x = i;
		i--;
		while (i >= 0 && a[i] >= a[i + 1]) {
			i--;
		}
		if (a[i] >= a[i + 1])
			i--;
		i++;
		for (int j = i; j <= x; j++) {
			lx[j] = x - j + 1;
		}
//		cout << x << ' ' << i << '\n';
	}
	int mx = 0;
	for (int i = n - 1; i >= 0; i--) {
		mx = max(mx, nx[i]);
		nm2[i] = mx;
	}
	mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, nx[i]);
		nm[i] = mx;
	}
	mx = 0;
	for (int i = 0; i < n; i++) {
		mx = max(mx, lx[i]);
		lm2[i] = mx;
	}
	mx = 0;
	for (int i = n - 1; i >= 0; i--) {
		mx = max(mx, lx[i]);
		lm[i] = mx;
	}
	int ans = 0;
	for (int i = 1; i < n - 1; i++) {
//		cout << nx[i] << ' ' << lx[i] << '\n';
		if (lx[i] == nx[i] && a[i] >= a[i - 1] && a[i] >= a[i + 1] && nx[i] > nm[i - 1] && nx[i] > lm[i + 1] && nx[i] > nm2[i + 1] && nx[i] > lm2[i - 1] && nx[i] % 2 == 1) 
			ans++;
	}
	cout << ans << '\n';
}