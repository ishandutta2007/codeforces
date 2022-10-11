#include <iostream>
#include <algorithm>
using namespace std;

int n, a[10009], Debug = 0;

int ask(int p) {
	if (Debug == 0) { int z; cin >> z; return z; }
	return a[p];
}

int search(int p) {
	cout << "? " << p << endl; int z1 = ask(p);
	cout << "? " << p + n / 2 << endl; int z2 = ask(p + n / 2);
	return z1 - z2;
}

int main() {
	cin >> n; if (Debug == 1) { for (int i = 1; i <= n; i++) cin >> a[i]; }
	if (n % 4 == 2) { cout << "! -1" << endl; return 0; }

	int E1 = search(1), E2 = search(n / 2), Z = 1;
	if (E1 > E2) Z = -1;
	if (E1 == 0) { cout << "! " << 1 << endl; return 0; }
	if (E2 == 0) { cout << "! " << n / 2 << endl; return 0; }

	int L = 1, R = (n / 2), M, minx = (n / 2);
	for (int i = 0; i < 27; i++) {
		M = (L + R) / 2;
		int p = search(M) * Z;
		if (p < 0) { L = M; }
		else { R = M; minx = min(minx, M); }
	}
	cout << "! " << minx << endl;
	return 0;
}