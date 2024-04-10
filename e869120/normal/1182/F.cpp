#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

const int INF = 250000;

long long extgcd(long long a, long long b, long long &x, long long &y) {
	long long d = a;
	if (b != 0) {
		d = extgcd(b, a % b, y, x);
		y -= (a / b) * x;
	}
	else {
		x = 1; y = 0;
	}
	return d;
}

long long mod_inverse(long long a, long long m) {
	long long x, y;
	extgcd(a, m, x, y);
	return (m + x % m) % m;
}

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long solve(long long a, long long b, long long p, long long q) {
	long long e = gcd(p, q);
	p /= e; q /= e; p %= q; if (p == 0) return a;

	long long minv1 = -1, ret1 = (1LL << 30);
	long long INV = mod_inverse(p, q);
	for (long long i = ((q + 1) / 2); i < (q / 2) + INF; i++) {
		if (i < 0 || i >= q) break;

		long long C = 1LL * i * INV % q;
		long long E = (a / q)*q + C; if (E < a) E += q;
		if (a <= E && E <= b) {
			if ((abs(q - 2LL * i) == ret1 && minv1 > E) || abs(q - 2LL * i) < ret1) { minv1 = E; }
			ret1 = min(ret1, abs(q - 2LL * i));
			break;
		}
	}
	for (long long i = (q / 2); i > (q / 2) - INF; i--) {
		if (i < 0 || i >= q) break;
		long long C = 1LL * i * INV % q;
		long long E = (a / q)*q + C; if (E < a) E += q;
		if (a <= E && E <= b) {
			if ((abs(q - 2LL * i) == ret1 && minv1 > E) || abs(q - 2LL * i) < ret1) { minv1 = E; }
			ret1 = min(ret1, abs(q - 2LL * i));
			break;
		}
	}

	long long minv2 = -1, ret2 = (1LL << 30);
	for (long long i = a; i <= a + INF; i++) {
		if (i > b) break;
		long long E = (1LL * p * i) % q;
		if (abs(q - 2LL * E) < ret2) {
			ret2 = abs(q - 2LL * E);
			minv2 = i;
		}
	}
	
	if (ret1 < ret2 || (ret1 == ret2 && minv1 < minv2)) return minv1;
	return minv2;
}

long long solver(long long a, long long b, long long p, long long q) {
	pair<long long, long long> ret1 = make_pair(1LL << 30, 0);
	for (long long i = a; i <= b; i++) {
		ret1 = min(ret1, make_pair(abs(q - 2LL * (1LL * i * p % q)), i));
	}
	return ret1.second;
}

int main() {
	int Debug = 2;
	if (Debug == 1) {
		for (int i = 1; i <= 10000000; i++) {
			long long A, B, P, Q;
			A = rand() % 20;
			B = rand() % 20; if (A > B) swap(A, B);
			P = rand() % 20 + 1;
			Q = rand() % 20 + 1;
			long long V1 = solve(A, B, P, Q);
			long long V2 = solver(A, B, P, Q);
			
			if (V1 != V2) {
				cout << "Wrong Answer on Test #" << i << endl;
				cout << A << " " << B << " " << P << " " << Q << endl;
				cout << endl;
			}
		}
	}
	if (Debug == 2) {
		long long T, A, B, P, Q; cin >> T;
		for (int i = 1; i <= T; i++) {
			cin >> A >> B >> P >> Q;
			cout << solve(A, B, P, Q) << endl;
		}
	}
	return 0;
}