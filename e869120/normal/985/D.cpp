#include <iostream>
#include <algorithm>
using namespace std;

long long N, H;

long long sankaku(long long L, long long R) {
	return R*(R + 1) / 2 - (L - 1)*L / 2;
}

long long solve(long long P) {
	if (P <= H) {
		return sankaku(1, P);
	}
	if ((P - H) % 2 == 1) {
		return sankaku(H, H + (P - H) / 2) + sankaku(1, H + (P - H) / 2);
	}
	else {
		return sankaku(H, H + (P - H) / 2) + sankaku(1, H + (P - H) / 2 - 1);
	}
}

int main() {
	cin >> N >> H;
	long long L = 1, R = (1LL << 31), M, maxn = (1LL << 60);
	for (int i = 0; i < 80; i++) {
		M = (L + R) / 2;
		long long s = solve(M);
		if (s < N) { L = M; }
		else { maxn = min(maxn, M); R = M; }
	}
	cout << maxn << endl;
	return 0;
}