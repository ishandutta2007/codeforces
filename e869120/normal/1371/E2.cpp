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

long long N, P, A[1 << 18];
long long BASE;
long long R[1 << 18];
bool used[1 << 18];

int main() {
	// 
	scanf("%lld%lld", &N, &P);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	sort(A, A + N);

	// 
	BASE = A[N - 1] - N;
	for (int i = 0; i < N; i++) BASE = max(BASE, A[i] - 1LL * i);

	for (int i = 0; i <= (A[N - 1] - BASE); i++) {
		int pos1 = lower_bound(A, A + N, BASE + 1LL * i + 1LL) - A;
		R[i] = pos1;
	}
	for (int i = 0; i <= (A[N - 1] - BASE); i++) {
		int ret = i - (R[i] % P); if (ret < 0 || R[i] < P) continue;
		used[ret] = true;
	}
	for (int i = 200000 - P; i >= 0; i--) {
		if (used[i + P] == true) used[i] = true;
	}

	// 
	long long maxV = A[N - 1] - N + P; vector<long long> E;
	for (int i = 0; i <= (maxV - BASE); i++) {
		if (used[i] == false) E.push_back(BASE + i);
	}

	cout << E.size() << endl;
	for (int i = 0; i < E.size(); i++) {
		if (i) printf(" ");
		printf("%lld", E[i]);
	}
	printf("\n");
	return 0;
}