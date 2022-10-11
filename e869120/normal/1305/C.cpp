#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#pragma warning (disable: 4996)
using namespace std;

long long N, M, A[1 << 18];

int main() {
	scanf("%lld%lld", &N, &M);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	
	if (N > M) {
		cout << "0" << endl;
	}
	else {
		long long ret = 1;
		for (int i = 0; i < N; i++) {
			for (int j = i + 1; j < N; j++) {
				ret *= 1LL * abs(A[i] - A[j]);
				ret %= M;
			}
		}
		cout << ret << endl;
	}
	return 0;
}