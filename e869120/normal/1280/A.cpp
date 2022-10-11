#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long mod = 1000000007;
int T, X; string S;

long long solve() {
	long long rem = S.size();
	for (int i = 1; i <= X; i++) {
		int L = (long long)S.size() - i; long long rep = (S[i - 1] - '0' - 1);
		rem += rep * (rem - 1LL * i);
		rem = (rem + mod * mod) % mod;

		long long remaining = X - (long long)S.size();
		for (int j = 0; j < min(remaining, rep * L); j++) {
			S += S[i + j % L];
		}
	}
	return rem;
}

int main() {
	scanf("%d", &T);
	for (int i = 1; i <= T; i++) {
		cin >> X >> S;
		cout << solve() << endl;
	}
	return 0;
}