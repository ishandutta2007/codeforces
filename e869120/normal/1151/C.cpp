#include <iostream>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007;

long long solve(long long N) {
	long long S1 = 0, S2 = 0;
	for (int i = 0; i <= 60; i++) {
		long long L = (1LL << i), R = (2LL << i) - 1LL;
		if (L > N) break;
		if (R <= N) {
			if (i % 2 == 0) S1 += (R - L + 1);
			if (i % 2 == 1) S2 += (R - L + 1);
		}
		else {
			if (i % 2 == 0) S1 += (N - L + 1);
			else S2 += (N - L + 1);
			break;
		}
	}
	S1 %= mod; S2 %= mod;
	long long V1 = S1 * S1;
	long long V2 = S2 * S2; V2 += S2;
	return (V1 + V2) % mod;
}

int main() {
	long long cl, cr;
	cin >> cl >> cr;
	cout << (solve(cr) - solve(cl - 1) + mod) % mod << endl;
	return 0;
}