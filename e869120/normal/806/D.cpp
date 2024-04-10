#include <iostream>
#include <algorithm>
#include <vector>
#include <tuple>
#include <queue>
using namespace std;
#pragma warning (disable: 4996)

long long N, A[2009][2009], dist[2009];
vector<tuple<long long, long long, long long>>tup;

int main() {
	scanf("%lld", &N);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) { scanf("%lld", &A[i][j]); A[j][i] = A[i][j]; tup.push_back(make_tuple(A[i][j], i, j)); tup.push_back(make_tuple(A[j][i], j, i)); }
	}
	sort(tup.begin(), tup.end());
	for (int i = 0; i < N; i++) dist[i] = (1LL << 60);

	for (int i = 0; i < tup.size(); i++) {
		long long s1 = get<1>(tup[i]), s2 = get<2>(tup[i]), cost = get<0>(tup[i]);
		if (cost * (N - 1LL) >= dist[s1]) continue;

		dist[s1] = cost * (N - 1LL);

		vector<long long>T(N, (1LL << 60)), vec;
		for (int j = 0; j < N; j++) {
			if (j == s1 || j == s2) continue;
			long long R = max(0LL, A[s1][j] - cost);
			T[j] = min(T[j], dist[s1] + R);
			if (dist[j] > dist[s1] + R) {
				vec.push_back(j);
			}
		}
		for (int pos : vec) {
			long long B = max(0LL, A[s1][pos] - cost);
			for (int j = 0; j < N; j++) {
				if (j == s2 || pos == j) continue;
				long long R = max(0LL, A[pos][j] - cost);
				T[j] = min(T[j], dist[s1] + R + min(R, B));
			}
		}

		queue<int>Q;
		for (int j = 0; j < N; j++) { if (T[j] < dist[j]) Q.push(j); }
		for (int j = 0; j < N; j++) dist[j] = min(dist[j], T[j]);

		while (!Q.empty()) {
			int pos = Q.front(); Q.pop();
			for (int j = 0; j < N; j++) {
				if (j == s2) continue;
				long long R = max(0LL, A[pos][j] - cost);
				if (dist[j] > dist[pos] + R) {
					dist[j] = dist[pos] + R;
					Q.push(j);
				}
			}
		}
		continue;
	}

	for (int i = 0; i < N; i++) printf("%lld\n", dist[i]);
	return 0;
}