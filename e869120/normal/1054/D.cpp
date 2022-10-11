#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 18], B[1 << 18], ans;
map<long long, long long>Map; vector<long long>vec;

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) { scanf("%lld", &A[i]); B[i] = A[i]; }
	for (int i = 1; i <= N; i++) B[i] ^= B[i - 1];
	for (int i = 0; i <= N; i++) Map[B[i]]++;
	for (int i = 0; i <= N; i++) { if (B[i] < (1LL << (K - 1))) vec.push_back(B[i]); else vec.push_back((1LL << K) - 1LL - B[i]); }
	sort(vec.begin(), vec.end());
	vec.erase(unique(vec.begin(), vec.end()), vec.end());

	ans = N * (N + 1LL) / 2LL;
	for (int i = 0; i < vec.size(); i++) {
		long long P = Map[vec[i]] + Map[(1LL << K) - 1LL - vec[i]];
		long long B1 = P / 2LL;
		long long B2 = P - B1;
		ans -= B1 * (B1 - 1LL) / 2LL;
		ans -= B2 * (B2 - 1LL) / 2LL;
	}
	cout << ans << endl;
	return 0;
}