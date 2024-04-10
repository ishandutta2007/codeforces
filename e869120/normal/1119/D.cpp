#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, Q, A[1 << 17], L[1 << 17], R[1 << 17], ans[1 << 17]; vector<pair<long long, int>>vec;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	sort(A, A + N);
	for (int i = 0; i < N - 1; i++) vec.push_back(make_pair(A[i + 1] - A[i], 0));

	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) {
		scanf("%lld%lld", &L[i], &R[i]);
		vec.push_back(make_pair(R[i] - L[i] + 1, i));
	}
	sort(vec.begin(), vec.end());

	long long t = 0, dep = N, sum = 0;
	for (int i = 0; i < vec.size(); i++) {
		if (vec[i].second == 0) {
			sum += (vec[i].first - t) * dep; dep--;
			t = vec[i].first;
		}
		else {
			ans[vec[i].second] = sum + (vec[i].first - t) * dep;
		}
	}
	for (int i = 1; i <= Q; i++) { if (i >= 2) printf(" "); printf("%lld", ans[i]); }
	printf("\n");
	return 0;
}