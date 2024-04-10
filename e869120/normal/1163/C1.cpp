#include <iostream>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

struct Fraction {
	long long px, py;
};

bool operator==(const Fraction &a1, const Fraction &a2) {
	if (a1.px * a2.py == a1.py * a2.px) return true;
	return false;
}
bool operator<(const Fraction &a1, const Fraction &a2) {
	if (a1.px * a2.py < a1.py * a2.px) return true;
	return false;
}
bool operator>(const Fraction &a1, const Fraction &a2) {
	if (a1.px * a2.py > a1.py * a2.px) return true;
	return false;
}

Fraction yakubun(Fraction A) {
	if (A.px < 0) { A.px *= -1; A.py *= -1; }
	if (A.px == 0) return Fraction{ 0LL, 1LL };
	if (A.py == 0) return Fraction{ 1LL, 0LL };

	long long E = gcd(A.px, A.py);
	A.px /= E;
	A.py /= E;
	return A;
}

long long N, X[1009], Y[1009]; map<Fraction, int>Map; map<tuple<int, int, int>, int>Map2;

int main() {
	cin >> N;
	for (int i = 0; i < N; i++) cin >> X[i] >> Y[i];

	long long cnt = 0;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			long long A = X[j] - X[i];
			long long B = Y[j] - Y[i]; B *= -1; if (A < 0) { A *= -1; B *= -1; }

			if (A == 0) B = 1;
			if (B == 0) A = 1;

			long long C = -1LL * (B * X[i] + A * Y[i]);
			long long G = gcd(A, gcd(B, C)); G = abs(G);
			A /= G; B /= G; C /= G;

			if (Map2[make_tuple(A, B, C)] == 1) continue;
			Map2[make_tuple(A, B, C)] = 1;

			Fraction E = Fraction{ X[j] - X[i], Y[j] - Y[i] };
			E = yakubun(E);
			Map[E]++; cnt++;
		}
	}
	long long ans = cnt;
	ans = ans * (ans - 1LL) / 2LL;
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			Fraction E = Fraction{ X[j] - X[i], Y[j] - Y[i] };
			E = yakubun(E);
			long long F = Map[E];
			ans -= F * (F - 1LL) / 2LL;
			Map[E] = 1;
		}
	}
	cout << ans << endl;
	return 0;
}