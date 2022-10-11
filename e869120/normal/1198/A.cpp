#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, I, A[1 << 19], cnt[1 << 19];
vector<long long> X;

int main() {
	scanf("%lld%lld", &N, &I);
	for (int i = 0; i < N; i++) {
		scanf("%lld", &A[i]);
		X.push_back(A[i]);
	}
	sort(X.begin(), X.end());
	X.erase(unique(X.begin(), X.end()), X.end());

	for (int i = 0; i < N; i++) A[i] = (lower_bound(X.begin(), X.end(), A[i]) - X.begin()) + 1;
	for (int i = 0; i < N; i++) cnt[A[i]]++;
	for (int i = 1; i <= N + 1; i++) cnt[i] += cnt[i - 1];

	long long E = (I * 8LL) / N;
	long long F = N; if (E < 50LL) F = min(F, (1LL << E));

	long long ans = (1LL << 60);
	for (int i = 0; i <= N - F; i++) {
		long long v1 = cnt[i], v2 = (cnt[N + 1] - cnt[i + F]);
		ans = min(ans, v1 + v2);
	}
	cout << ans << endl;
	return 0;
}