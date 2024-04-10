#include <iostream>
#include <queue>
#include <functional>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, T, S, maxn = -1, maxid = -1; vector<pair<long long, int>> X[1 << 18];
priority_queue<long long, vector<long long>, less<long long>>Q;

int main() {
	cin >> N >> T;
	for (int i = 1; i <= N; i++) {
		long long a1, a2; scanf("%lld%lld", &a1, &a2);
		X[a1].push_back(make_pair(a2, i));
	}
	for (int i = 1; i <= N; i++) sort(X[i].begin(), X[i].end());

	long long cnt = 0, sum = 0;
	for (int i = N; i >= 1; i--) {
		for (int j = 0; j < X[i].size(); j++) {
			Q.push(X[i][j].first); cnt++; sum += X[i][j].first;
		}
		while (cnt > i || sum > T) {
			long long B = Q.top(); Q.pop();
			cnt--; sum -= B;
		}
		if (maxn < cnt) {
			maxn = cnt; maxid = i;
		}
	}

	vector<int>vec; vector<pair<long long, int>>vec2;
	for (int i = maxid; i <= N; i++) {
		for (int j = 0; j < X[i].size(); j++) vec2.push_back(X[i][j]);
	}
	sort(vec2.begin(), vec2.end());

	printf("%lld\n", maxn);
	printf("%lld\n", maxn);
	for (int i = 0; i < maxn; i++) { if (i) printf(" "); printf("%d", vec2[i].second); }
	printf("\n");
	return 0;
}