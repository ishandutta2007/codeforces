#include <bits/stdc++.h>
using namespace std;
const int MN = 3e3 + 5;
int main () {
	int n; scanf ("%d",&n);
	vector<int> a(n+1), b(n+1); long long base = 0;
	for (int i = 1; i <= n; i++) scanf ("%d",&a[i]);
	for (int i = 1; i <= n; i++) scanf ("%d",&b[i]), base += (long long)a[i] * b[i];
	long long ret = base;
	for (int c = 1; c <= n; c++) {
		long long att = base;
		for (int i = 1; c + i <= n && c - i >= 1; i++) {
			int l = c - i, r = c + i;
			att -= (long long)a[l] * b[l] + (long long)a[r] * b[r];
			att += (long long)a[l] * b[r] + (long long)a[r] * b[l];
			ret = max(ret,att);
		}
	}
	for (int c = 1; c < n; c++) {
		long long att = base;
		for (int i = 0; c - i >= 1 && c + i + 1 <= n; i++) {
			int l = c - i, r = c + i + 1;
			att -= (long long)a[l] * b[l] + (long long)a[r] * b[r];
			att += (long long)a[l] * b[r] + (long long)a[r] * b[l];
			ret = max(ret,att);
		}
	}
	printf ("%lld\n",ret);
	return 0;
}