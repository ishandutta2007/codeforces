#include <iostream>
#include <algorithm>
using namespace std;

long long N, L, a[100009], b[100009], c[100009];

bool solve(int pos) {
	for (int i = 0; i <= N; i++) { b[i] = a[i]; c[i] = 0; }
	int cx = 1; c[0] = pos;
	for (int i = 0; i <= N - 1; i++) {
		cx = max(cx, i + 1);
		while (c[i] >= 1) {
			if (cx - i > L) return false;
			if (c[i] >= b[cx]) { c[cx] += b[cx]; c[i] -= b[cx]; b[cx] = 0; cx++; }
			else { c[cx] += c[i]; b[cx] -= c[i]; c[i] = 0; }
		}
	}
	return true;
}

int main() {
	cin >> N >> L;
	for (int i = 1; i <= N - 1; i++) cin >> a[i]; a[N] = 1200000000;

	long long LL = 0, RR = 1200000000, MM, maxn = -1;
	for (int i = 0; i < 40; i++) {
		MM = (LL + RR) / 2;
		bool T = solve(MM);
		if (T == true) { maxn = max(maxn, MM); LL = MM; }
		else { RR = MM; }
	}
	cout << maxn << endl;
	return 0;
}