#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <cmath>
#include <functional>
#include <tuple>
using namespace std;
#pragma warning (disable: 4996)

long long N, A, B, S, maxn, L[200009];

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

long long sum(long long cl, long long K) {
	long long E = cl / K;
	long long F = E * (E + 1LL) / 2LL;
	F *= K;
	F += ((cl % K) + 1LL) * (E + 1LL);
	return F;
}

int main() {
	cin >> N >> A >> B;
	
	for (int i = 0; i <= 200008; i++) L[i] = (1LL << 30);

	long long cx = 0;
	for (int i = 2; i <= 1000002; i++) {
		if (cx >= B) cx -= B;
		else cx += A;
		maxn = max(maxn, cx);
		if (cx == 0) break;
		L[cx - 1] = i - 1;
	}
	for (int i = 200000; i >= 0; i--) L[i] = min(L[i], L[i + 1]);

	for (int i = 0; i <= maxn - 1; i++) {
		if (i > N) break;
		S += L[i];
	}
	if (maxn <= N) {
		S -= sum(maxn - 1, gcd(A, B));
		S += sum(N, gcd(A, B));
	}
	cout << S << endl;
	return 0;
}