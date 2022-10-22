/* 	* In the name of GOD 
 	* Thanks God */
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 301234;
int pre0[N], n, k, a[N];

bool check(int l, int r) {
	if (pre0[r] - (l ? pre0[l - 1] : 0) <= k)
		return true;
	return false;
}

int bs (int k) {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (!check(k, mid)) { 
			r = mid;
		} else {
			l = mid + 1;  
		}
	}
	return l;
}

int32_t main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> a[i];
	for (int i = 0; i < n; i++) {
		pre0[i] = (i ? pre0[i - 1] : 0) + (a[i] == 0);
	}
	int mx = 0;
	pair <int, int> an;
	for (int i = 0; i < n; i++) {
		int x = bs(i);
		if (x - i > mx) {
			mx = x - i;
			an = {i, x};
		}
	}
	cout << mx << '\n';
	for (int i = 0; i < n; i++) {
		if (i >= an.F && i < an.S)
			cout << 1 << ' ';
		else
			cout << a[i] << ' ';
	}

}