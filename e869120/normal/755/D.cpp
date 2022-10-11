#include<iostream>
#include<algorithm>
using namespace std;
int n, m, bit[6000000];
void add(int r, int p) { while (r <= n) { bit[r] += p; r += r&-r; } }
int sum(int e) { int s = 0; while (e >= 1) { s += bit[e]; e -= e&-e; }return s; }
int sum2(int L, int R) { return sum(R) - sum(L - 1); }
int main() {
	cin >> n >> m; m = min(m, n - m); int s = 1; long long t = 1;
	for (int i = 0; i < n; i++) {
		if (i >= 1)cout << ' ';
		int L = s - (m - 1), R = s + (m - 1); if (L <= 0)L += n; if (R > n)R -= n;
		t++;
		if (L <= R)t += sum2(L, R);
		else { t += sum2(1, R) + sum2(L, n); }
		add(s, 1); s += m; if (s > n)s -= n;
		cout << t;
	}
	cout << endl;
	return 0;
}