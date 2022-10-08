/**
 * Sergey Kopeliovich (burunduk30@gmail.com)
 */

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for (int i = 0; i < (int)(n); i++)

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0);

	int n, k, l, m;
	cin >> n >> k >> l, m = n * k;
	vector<int> a(m);
	forn(i, m) cin >> a[i];
	sort(a.begin(), a.end());
	int p = 0;
	while (p < m && a[p] - a[0] <= l)
		p++;
	if (p < n) {
		puts("0");
		return 0;
	}
	long long sum = 0;
	forn(i, n) 
		sum += a[min(p - (n - i), k * i)];
	cout << sum << endl;
}