#include <iostream>
#include <vector>
#include <queue>
#include <functional>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N;
pair<long long, long long> A[1 << 18];
vector<pair<long long, long long>> V;
priority_queue<pair<long long, int>, vector<pair<long long, int>>, less<pair<long long, int>>> Q;

long long solve(vector<pair<long long, long long>> S) {
	for (int i = 1; i < S.size(); i++) S[i].first -= S[0].first;
	S[0].first = 0;

	int cx = 0; long long ret = 0;
	for (int i = 0; i < S.size(); i++) {
		while (cx < S.size() && S[cx].first <= i) { Q.push(make_pair(S[cx].second, cx)); cx++; }
		long long v = Q.top().second; Q.pop();
		ret += 1LL * (1LL * i - S[v].first) * S[v].second;
	}
	return ret;
}

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i].first);
	for (int i = 0; i < N; i++) scanf("%lld", &A[i].second);
	sort(A, A + N);

	long long ans = 0;
	for (int i = 0; i < N; i++) {
		V.push_back(make_pair(A[i].first, A[i].second));
		if (i == N - 1 || V[0].first + (long long)(V.size()) <= A[i + 1].first) {
			ans += solve(V);
			V.clear();
		}
	}
	cout << ans << endl;
	return 0;
}