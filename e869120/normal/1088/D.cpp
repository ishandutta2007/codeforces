#include <iostream>
using namespace std;

const int digit = 30;
long long a, b, p, q; int state = 0;

int Debug = 1;

long long ask(long long v1, long long v2) {
	cout << "? " << v1 << " " << v2 << endl;

	if (Debug == 1) {
		int u; cin >> u;
		return u;
	}
	if (Debug == 2) {
		long long x1 = (v1 ^ p), x2 = (v2 ^ q);
		if (x1 > x2) return 1;
		if (x1 == x2) return 0;
		return -1;
	}
}

int main() {
	if (Debug == 2) {
		cin >> p >> q;
	}
	long long E1 = 0, E2 = 0;
	for (int i = digit - 1; i >= 0; i--) {
		while (true) {
			if (state == 0) {
				long long v = ask(E1, E2);
				if (v >= 0) state = 1;
				else state = 2;
			}
			else if (state == 1) {
				// a >= b
				long long v = ask(E1 + (1LL << i), E2 + (1LL << i));
				if (v < 0) { state = 0; a += (1LL << i); E1 += (1LL << i); break; }
				
				long long w = ask(E1 + (1LL << i), E2);
				if (w >= 0) { state = 1; break; }
				else { state = 1; a += (1LL << i); b += (1LL << i); E1 += (1LL << i); E2 += (1LL << i); break; }
			}
			else if (state == 2) {
				// a < b
				long long v = ask(E1 + (1LL << i), E2 + (1LL << i));
				if (v > 0) { state = 0; b += (1LL << i); E2 += (1LL << i); break; }

				long long w = ask(E1, E2 + (1LL << i));
				if (w < 0) { state = 2; break; }
				else { state = 2; a += (1LL << i); b += (1LL << i); E1 += (1LL << i); E2 += (1LL << i); break; }
			}
		}
	}
	cout << "! " << a << " " << b << endl;
	return 0;
}