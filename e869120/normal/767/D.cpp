#include <iostream>
#include <algorithm>
#include <vector>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, K, A[1000009], B[1000009], cnt[2000009];
vector<pair<long long, long long>>vec;

int main() {
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); A[i] = min(A[i], 2000000LL); }
	for (int i = 0; i < M; i++) { scanf("%lld", &B[i]); B[i] = min(B[i], 2000000LL); vec.push_back(make_pair(B[i], i)); }
	sort(vec.begin(), vec.end(), greater<pair<long long, long long>>());

	long long L = 0, R = M + 1, MI, maxn = -1;
	for (int i = 0; i < 24; i++) {
		MI = (L + R) / 2;
		for (int j = 0; j < 2000009; j++) cnt[j] = 0;
		for (int j = 0; j < N; j++) cnt[A[j]]++;
		for (int j = 0; j < min(M, MI); j++) cnt[vec[j].first]++;

		long long ans = 0; bool OK = true;
		for (int j = 0; j < 2000009; j++) {
			ans += cnt[j];
			if (ans > K*(j + 1)) { OK = false; break; }
		}
		if (OK == true) { maxn = max(maxn, MI); L = MI; }
		else { R = MI; }
	}
	cout << maxn << endl; vector<long long>G;
	for (int i = 0; i < maxn; i++) G.push_back(vec[i].second + 1);
	sort(G.begin(), G.end());
	for (int i = 0; i < maxn; i++) {
		if (i) cout << " "; cout << G[i];
	}
	if (maxn >= 1) cout << endl;
	return 0;
}