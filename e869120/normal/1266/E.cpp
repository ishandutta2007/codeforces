#include <iostream>
#include <map>
#include <queue>
#include <cmath>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[1 << 18];
long long Q, X[1 << 18], Y[1 << 18], Z[1 << 18];
long long R[1 << 18];
map<pair<int, int>, int> Map;

int main() {
	scanf("%lld", &N);
	for (int i = 1; i <= N; i++) scanf("%lld", &A[i]);
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) scanf("%lld%lld%lld", &X[i], &Y[i], &Z[i]);

	long long sum = 0, cnt = 0;
	for (int i = 1; i <= N; i++) sum += A[i];

	for (int i = 1; i <= Q; i++) {
		if (Map[make_pair(X[i], Y[i])] >= 1) {
			int idx = Map[make_pair(X[i], Y[i])];
			if (R[idx] <= A[idx]) cnt--;
			R[idx]--;
			Map[make_pair(X[i], Y[i])] = 0;
		}
		if (Z[i] >= 1) {
			int idx = Z[i];
			Map[make_pair(X[i], Y[i])] = Z[i];
			R[idx]++;
			if (R[idx] <= A[idx]) cnt++;
		}
		printf("%lld\n", sum - cnt);
	}
	return 0;
}