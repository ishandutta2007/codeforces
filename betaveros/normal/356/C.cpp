#include <iostream>
#include <algorithm>
#include <cstring>
#define debug(code) ((void)0)
using namespace std;

int h[5];
int total = 0;
int n;

int abs(int x) { return x < 0 ? -x : x; }

int moves(int ac[], int bc[]) {
	int a[5], b[5];
	for (int i = 0; i < 5; i++) { a[i] = ac[i]; b[i] = bc[i]; }
	debug(cout << "b:" << b[3] << "," << b[4] << endl);
	int ret = 0;
	int ai = 4;
	int bi = 4;
	while (ai > 0 && bi > 0) {
		int m = min(a[ai], b[bi]);
		a[ai] -= m;
		b[bi] -= m;
		ret += m * abs(ai - bi);
		if (a[ai] == 0) ai--;
		if (b[bi] == 0) bi--;
	}
	while (ai > 0) {
		ret += ai * a[ai];
		// a[ai] = 0;
		ai--;
	}
	while (bi > 0) {
		ret += bi * b[bi];
		// b[bi] = 0;
		bi--;
	}
	debug(cout << "moves ret " << ret / 2 << endl);
	return ret / 2;
}

int answer() {
	int f[5]; // final histogram
	memset(f, 0, sizeof(f));
	int tt = total;
	// Assign compartments needed by remainder
	while (tt % 3 != 0) {
		tt -= 4;
		f[4]++;
	}
	while (tt % 4 != 0) {
		tt -= 3;
		f[3]++;
	}
	if (tt < 0) return -1;

	int dozens = tt / 12;
	int d4s = 0;
	if (h[4] > f[4]) {
		d4s = (h[4] - f[4]) / 3;
		f[4] += d4s * 3;
	}
	f[3] += (dozens - d4s) * 4;
	int m = moves(h, f);

	if (f[3] >= 4) {
		f[3] -= 4;
		f[4] += 3;
		m = min(m, moves(h, f));
	}
	return m;
}

int main() {
	cin >> n;
	memset(h, 0, sizeof(h));
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		h[x]++;
		total += x;
	}
	cout << answer() << endl;
}