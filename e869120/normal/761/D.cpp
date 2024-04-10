#include<iostream>
#include<algorithm>
using namespace std;
long long n, l, r, s = -2.1e9, a[100000], p[100000], b[100000], J[100000];
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) { cin >> a[i]; }
	for (int i = 0; i < n; i++) { cin >> p[i]; p[i] = n - p[i]; J[p[i]] = i; }
	for (int i = 0; i < n; i++) {
		long long F2 = a[J[i]] - l; if (F2 <= s) { cout << "-1" << endl; return 0; }
		b[J[i]] = max(s + 1, a[J[i]] - r); s = b[J[i]]; b[J[i]] = a[J[i]] - b[J[i]];
	}
	for (int i = 0; i < n; i++) { if (i)cout << ' '; cout << b[i]; }cout << endl;
	return 0;
}