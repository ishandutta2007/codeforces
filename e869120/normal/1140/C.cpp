#include <iostream>
#include <queue>
#include <functional>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, T[1 << 19], B[1 << 19], sum, maxn;
vector<pair<long long, long long>>vec;
priority_queue<long long, vector<long long>, greater<long long>>Q;

int main() {
	scanf("%lld%lld", &N, &K);
	for (int i = 1; i <= N; i++) { scanf("%lld%lld", &T[i], &B[i]); vec.push_back(make_pair(B[i], T[i])); }
	sort(vec.begin(), vec.end());
	reverse(vec.begin(), vec.end());

	for (int i = 0; i < N; i++) {
		Q.push(vec[i].second); sum += vec[i].second;
		while (Q.size() > K) { sum -= Q.top(); Q.pop(); }
		maxn = max(maxn, sum*vec[i].first);
	}
	cout << maxn << endl;
	return 0;
}