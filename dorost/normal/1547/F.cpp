/* 	* In the name of GOD  */

#include "bits/stdc++.h"

using namespace std;

typedef long long ll;
typedef long double ld;
#define F first
#define S second
const int N = 201234;
int a[N], n;
int *st2;

int getMid(int s, int e) {
	return s + (e -s)/2;
}

int getSumUtil(int *st, int ss, int se, int qs, int qe, int si) {
	if (qs <= ss && qe >= se)
		return st[si];
	if (se < qs || ss > qe)
		return 0;
	int mid = getMid(ss, se);
	return __gcd(getSumUtil(st, ss, mid, qs, qe, 2*si+1) ,getSumUtil(st, mid+1, se, qs, qe, 2*si+2));
}

int getSum(int *st, int n, int qs, int qe) {
	return getSumUtil(st, 0, n-1, qs, qe, 0);
}

int constructSTUtil(int arr[], int ss, int se, int *st, int si) {
	if (ss == se) {
		st[si] = arr[ss];
		return arr[ss];
	}
	int mid = getMid(ss, se);
	st[si] = __gcd(constructSTUtil(arr, ss, mid, st, si*2+1), constructSTUtil(arr, mid+1, se, st, si*2+2));
	return st[si];
}

int *constructST(int arr[], int n) {
	int x = (int)(ceil(log2(n)));
	int max_size = 2*(int)pow(2, x) - 1;
	int *st = new int[max_size];
	constructSTUtil(arr, 0, n-1, st, 0);
	return st;
}

bool check(int x) {
	x++;
	int b = getSum(st2, n, 0, x - 1);
	for (int i = 1; i < n; i++) {
		int c = getSum(st2, n, i, min(n - 1, i + x - 1));
		if (i + x - 1 >= n) {
			c = __gcd(c, getSum(st2, n, 0, (i + x - 1) % n));
		}
		if (c != b)
			return false;
	}
	return true;
}

int bs() {
	int l = 0, r = n;
	while (l < r) {
		int mid = (l + r) / 2;
		if (check(mid)) {
			r = mid;
		} else {
			l = mid + 1;
		}
	}
	return l;
}

void solve() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	st2 = constructST(a, n);
	cout << bs() << '\n';
}

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t = 1;
	cin >> t;
	while (t--) {
		solve();
	}
}