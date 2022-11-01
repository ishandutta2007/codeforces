#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <iostream>
using namespace std;

const int N = 1e5 + 10;

int a[N], b[N], ocurr[N];
int n, m;

bool solve(int a[], int p) {
	//cout << "p = " << p << endl;
	fill(ocurr, ocurr + n + 1, 0);
	for(int i = 1; i <= p; i++) {
		ocurr[a[i]]++;
	}
	for(int i = 1; i <= (m + 1) / 2; i++) {
		//cout << "go " << i << endl;
		int pos = m - i + 1;
		if (i > p) {
			if (a[i] != a[pos]) {
				return false;
			}
		} else if (pos > p) {
			if (ocurr[a[pos]] == 0) {
				return false;
			}
			ocurr[a[pos]]--;
		} else {
		}
	}
	int odd = 0;
	for(int i = 1; i <= n; i++) {
		if (ocurr[i] % 2) {
			odd++;
		}
	}
	if (odd > 1) {
		return false;
	} else {
		return true;
	}
}

int main() {
	scanf("%d", &n);
	for(int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		ocurr[a[i]] ^= 1;
	}
	{
		int l = 1, r = n, cnt = 0;
		for(; l <= r && a[l] == a[r]; l++, r--);
		for(int i = 1; i <= n; i++) {
			if (ocurr[i]) {
				cnt++;
			}
		}
		if (cnt != n % 2) {
			cout << 0 << endl;
			return 0;
		}
		if (l > r) {
			cout << 1LL * (n + 1) * n / 2 << endl;
			return 0;
		}
		m = 0;
		for(int i = l; i <= r; i++) {
			b[++m] = a[i];
		}
	}

	int pref = 0, suff = 0, l, r;
	l = 1, r = m;
	while(l < r) {
		int mid = (l + r) >> 1;
		if (solve(b, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	pref = l;
	reverse(b + 1, b + m + 1);
	l = 1, r = m;
	while(l < r) {
		int mid = (l + r) >> 1;
		if (solve(b, mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	suff = l;
	//cout << suff << " " << pref << endl;
	int t = (n - m) / 2;
	cout << 1LL * (t + 1) * (t + 1 + m - pref + m - suff) << endl;
	return 0;
}