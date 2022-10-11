#include<iostream>
#include<algorithm>
using namespace std;
int n, u, a[300001], b, c[300001], d[300001];
int main() {
	cin >> n >> u;
	for (int i = 1; i <= n; i++) { cin >> a[i]; c[a[i]]++; }
	if (a[u] != 0) { b++; c[a[u]]--; c[0]++; a[u] = 0; }
	if (n == 1) { cout << b << endl; return 0; }

	for (int i = 0; i <= n; i++) { if (c[i] == 0)d[i]++; }
	for (int i = 1; i <= n; i++)d[i] += d[i - 1];
	int minx = 999999999, r = 0;
	for (int i = n; i >= 1; i--) {
		int s = d[i];
		s -= (c[0] - 1); s -= r;
		if (s < 0) { minx = min(minx, (c[0] - 1) + r); }
		else {
			minx = min(minx, d[i]);
		}
		r += c[i];
	}
	cout << minx + b << endl;
	return 0;
}