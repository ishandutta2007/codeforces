#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int T;
int A[1 << 18];
pair<int, int> B[1 << 18];
int c[309][309];

void init() {
	for (int i = 0; i < 309; i++) {
		for (int j = 0; j < 309; j++) c[i][j] = 0;
	}
	for (int i = 0; i < 309; i++) A[i] = 0;
	for (int i = 0; i < 309; i++) B[i] = make_pair(0, 0);
}

void solve(int N, int K) {
	init();
	for (int i = 0; i < K; i++) A[i % N] += 1;
	sort(A, A + N);
	reverse(A, A + N);
	for (int i = 0; i < N; i++) B[i] = make_pair(A[i], i);

	int cl = 10000, cr = 0, dl = 10000, dr = 0;
	for (int i = 0; i < N; i++) {
		cl = min(cl, A[i]);
		cr = max(cr, A[i]);
		dl = min(dl, B[i].first);
		dr = max(dr, B[i].first);
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < A[i]; j++) {
			c[i][B[j].second] += 1;
			B[j].first -= 1;
		}
		sort(B, B + N);
		reverse(B, B + N);
	}
	printf("%d\n", (cr - cl) * (cr - cl) + (dr - dl) * (dr - dl));
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) printf("%d", c[i][j]);
		printf("\n");
	}
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		int N, K; cin >> N >> K;
		solve(N, K);
	}
	return 0;
}