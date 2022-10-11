#include <iostream>
#include <vector>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

long long T;
long long N, P[1 << 18], M[1 << 18];
vector<long long> E[1 << 18];

long long solve() {
	for (int i = 0; i <= N; i++) E[i].clear();
	for (int i = 1; i <= N; i++) E[M[i]].push_back(i);

	priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> Q;
	for (int i = N - 1; i >= 0; i--) {
		for (int j = 0; j < E[i].size(); j++) Q.push(make_pair(P[E[i][j]], E[i][j]));
		while (Q.size() > (N - i)) Q.pop();
	}

	long long ret = 0;
	for (int i = 1; i <= N; i++) ret += P[i];
	while (!Q.empty()) {
		ret -= Q.top().first;
		Q.pop();
	}
	return ret;
}

int main() {
	scanf("%lld", &T);
	for (int i = 1; i <= T; i++) {
		scanf("%lld", &N);
		for (int j = 1; j <= N; j++) scanf("%lld%lld", &M[j], &P[j]);
		printf("%lld\n", solve());
	}
	return 0;
}