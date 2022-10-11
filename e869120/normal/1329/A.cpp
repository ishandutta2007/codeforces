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

long long N, M;
long long S[1 << 18];
long long L[1 << 18];
long long R[1 << 18];

int main() {
	// 
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= M; i++) scanf("%lld", &S[i]);
	R[M + 1] = N + 1;
	for (int i = 1; i <= M; i++) L[i] = i;
	for (int i = M; i >= 1; i--) R[i] = R[i + 1] - S[i];

	// 
	for (int i = 1; i <= M; i++) {
		if (L[i] + S[i] - 1 > N) { cout << "-1" << endl; return 0; }
	}
	if (R[1] >= 2) {
		cout << "-1" << endl;
		return 0;
	}

	// 
	for (int i = 1; i <= M; i++) {
		if (i >= 2) cout << " ";
		cout << max(L[i], R[i]);
	}
	cout << endl;
	return 0;
}