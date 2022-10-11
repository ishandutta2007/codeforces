#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
long long n, k, c[200099], t[200009], ret;
void solve() {
	for (int i = 0; i <= 200097; i++) {
		if (c[i] >= 0)c[i + 1] += c[i] / 2;
		else c[i + 1] += (c[i] - 1) / 2;
		c[i] %= 2; c[i] = abs(c[i]);
	}
}
int main() {
	cin >> n >> k;
	for (int i = 0; i <= n; i++) {
		cin >> t[i]; c[i] = t[i];
	}
	solve();
	if (c[200098] <= -1) {
		for (int i = 0; i <= n; i++)t[i] *= -1;
		for (int i = 0; i <= 200098; i++)c[i] = 0;
		for (int i = 0; i <= n; i++)c[i] = t[i];
		solve();
	}
	int L = 0; for (int i = 0; i <= 200098; i++) { if (c[i] == 0)L = i; else break; }L++; L = min(L, (int)n);
	int R = 0; for (int i = 200098; i >= 0; i--) { if (c[i] == 0)R = i; else break; }R--; L = min(L, R);
	for (int i = L; i >= 0; i--) {
		if (R - i >= 40)continue;
		long long C = 0;
		for (int j = i; j <= R; j++) { C += (1LL << (j - i))*c[j]; }C *= -1;
		if (abs(t[i] + C) <= k && (i != n || (t[i] + C) != 0))ret++;
	}
	cout << ret << endl;
	return 0;
}