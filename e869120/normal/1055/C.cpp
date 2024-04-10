#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long L[2], R[2], T[2], S[2];

int main() {
	cin >> L[0] >> R[0] >> T[0] >> L[1] >> R[1] >> T[1];
	S[0] = R[0] - L[0] + 1;
	S[1] = R[1] - L[1] + 1;
	if (S[0] > S[1]) { swap(L[0], L[1]); swap(R[0], R[1]); swap(T[0], T[1]); swap(S[0], S[1]); }

	long long E = gcd(T[0], T[1]);
	long long F = L[0] - L[1]; F += 2000000000LL * E; F %= E;
	long long G1 = min(S[1] - F, S[0]);
	long long G2 = S[0] + (F - E);
	cout << max({ 0LL, G1, G2 }) << endl;
	return 0;
}