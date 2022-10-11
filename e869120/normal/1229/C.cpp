#include <iostream>
#include <vector>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, Q;
long long A[1 << 18], B[1 << 18], G[1 << 18], X[1 << 18];
long long s1[1 << 18], s2[1 << 18];
vector<int> I[1 << 18];
map<int, bool> Map[1 << 18];

long long LastUpdate[1 << 18];
bool used[1 << 18];

int main() {
	//  1: 
	scanf("%lld%lld", &N, &M);
	for (int i = 1; i <= M; i++) {
		scanf("%lld%lld", &A[i], &B[i]);
		I[A[i]].push_back(B[i]); Map[A[i]][B[i]] = 1;
		I[B[i]].push_back(A[i]); Map[B[i]][A[i]] = 1;
	}
	scanf("%lld", &Q);
	for (int i = 1; i <= Q; i++) scanf("%lld", &G[i]);
	for (int i = 1; i <= N; i++) X[i] = i;

	//  2: 
	for (int i = 1; i <= M; i++) {
		if (X[A[i]] > X[B[i]]) { s1[A[i]]++; s2[B[i]]++; }
		if (X[A[i]] < X[B[i]]) { s1[B[i]]++; s2[A[i]]++; }
	}
	long long sum = 0;
	for (int i = 1; i <= M; i++) sum += s1[i] * s2[i];
	printf("%lld\n", sum);

	//  3: 
	for (int i = 1; i <= Q; i++) {
		int id = G[i];

		//  1: 
		if (I[id].size() >= 1200 && LastUpdate[id] >= 1) {
			vector<int> D;
			for (int j = LastUpdate[id] + 1; j < i; j++) {
				if (Map[id][G[j]] == 1 && used[G[j]] == false) { D.push_back(G[j]); used[G[j]] = true; }
			}
			for (int j = LastUpdate[id] + 1; j < i; j++) used[G[j]] = false;

			// 
			for (int j : D) sum -= s1[j] * s2[j];
			sum -= s1[id] * s2[id];

			// 
			for (int j : D) {
				if (X[j] > X[id]) { s1[j]--; s2[id]--; }
				if (X[j] < X[id]) { s1[id]--; s2[j]--; }
			}

			// 
			X[id] = N + i;

			// 
			for (int j : D) {
				if (X[j] > X[id]) { s1[j]++; s2[id]++; }
				if (X[j] < X[id]) { s1[id]++; s2[j]++; }
			}
			for (int j : D) sum += s1[j] * s2[j];
			sum += s1[id] * s2[id];
		}

		//  2: 
		else {
			// 
			for (int j : I[id]) sum -= s1[j] * s2[j];
			sum -= s1[id] * s2[id];

			// 
			for (int j : I[id]) {
				if (X[j] > X[id]) { s1[j]--; s2[id]--; }
				if (X[j] < X[id]) { s1[id]--; s2[j]--; }
			}

			// 
			X[id] = N + i;

			// 
			for (int j : I[id]) {
				if (X[j] > X[id]) { s1[j]++; s2[id]++; }
				if (X[j] < X[id]) { s1[id]++; s2[j]++; }
			}
			for (int j : I[id]) sum += s1[j] * s2[j];
			sum += s1[id] * s2[id];
		}
		LastUpdate[id] = i;

		printf("%lld\n", sum);
	}
	return 0;
}