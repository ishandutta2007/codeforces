#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long T;
long long N, S, L[1 << 18], R[1 << 18];

bool solve(long long val) {
	long long rem = S;
	for (int i = 1; i <= N; i++) rem -= L[i];

	vector<long long> V;
	for (int i = 1; i <= N; i++) {
		if (R[i] < val) continue;
		V.push_back(max(0LL, val - L[i]));
	}
	sort(V.begin(), V.end());
	if (V.size() < ((N + 1) / 2)) return false;

	for (int i = 0; i < (N + 1) / 2; i++) {
		rem -= V[i];
	}
	if (rem < 0) return false;
	return true;
}

int main() {
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld%lld", &N, &S);
		for (int j = 1; j <= N; j++) scanf("%lld%lld", &L[j], &R[j]);

		long long cl = 0, cr = (1LL << 30), cm, maxn = 0;
		for (int j = 1; j <= 36; j++) {
			cm = (cl + cr) / 2;
			if (solve(cm) == true) { maxn = max(maxn, cm); cl = cm; }
			else { cr = cm; }
		}
		printf("%lld\n", maxn);
	}
	return 0;
}