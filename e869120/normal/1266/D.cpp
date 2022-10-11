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

int N, M;
int A[1 << 19], B[1 << 19], C[1 << 19];
long long deg[1 << 19];

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%d%d%d", &A[i], &B[i], &C[i]);
		deg[A[i]] += 1LL * C[i];
		deg[B[i]] -= 1LL * C[i];
	}

	vector<pair<long long, int>> V1;
	vector<pair<long long, int>> V2;
	for (int i = 1; i <= N; i++) {
		if (deg[i] >= 1) V1.push_back(make_pair(deg[i], i));
		if (deg[i] <= -1) V2.push_back(make_pair(deg[i], i));
	}

	int c1 = 0; vector<tuple<int, int, long long>>tup;
	for (int i = 0; i < V1.size(); i++) {
		while (V1[i].first > 0) {
			if (V1[i].first > -V2[c1].first) { 
				if (V2[c1].first < 0) tup.push_back(make_tuple(V1[i].second, V2[c1].second, -V2[c1].first));
				V1[i].first += V2[c1].first; V2[c1].first = 0; c1++;
			}
			else {
				tup.push_back(make_tuple(V1[i].second, V2[c1].second, V1[i].first));
				V2[c1].first += V1[i].first; V1[i].first = 0;
			}
		}
	}
	sort(tup.begin(), tup.end());

	printf("%d\n", (int)tup.size());
	for (int i = 0; i < tup.size(); i++) printf("%d %d %lld\n", get<0>(tup[i]), get<1>(tup[i]), get<2>(tup[i]));
	return 0;
}