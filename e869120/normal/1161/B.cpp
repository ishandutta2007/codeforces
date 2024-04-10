#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, M, A[1 << 18], B[1 << 18]; vector<pair<int, int>>vec;

int main() {
	scanf("%d%d", &N, &M);
	for (int i = 0; i < M; i++) {
		scanf("%d%d", &A[i], &B[i]);
		if (A[i] == N) A[i] = 0;
		if (B[i] == N) B[i] = 0;
		if (A[i] > B[i]) swap(A[i], B[i]);
		vec.push_back(make_pair(A[i], B[i]));
	}
	sort(vec.begin(), vec.end());

	for (int i = 1; i < N; i++) {
		if (N%i != 0) continue;

		vector<pair<int, int>>vec2;
		for (int j = 0; j < M; j++) {
			int v1 = (A[j] + i) % N, v2 = (B[j] + i) % N;
			if (v1 > v2) swap(v1, v2);
			vec2.push_back(make_pair(v1, v2));
		}
		sort(vec2.begin(), vec2.end());

		if (vec == vec2) {
			cout << "Yes" << endl;
			return 0;
		}
	}
	cout << "No" << endl;
	return 0;
}