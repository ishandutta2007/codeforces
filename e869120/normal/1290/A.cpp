#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

int T;
int N, M, K;
int A[1 << 18];

int solve() {
	vector<int> leng;
	for (int i = 1; i <= M; i++) {
		leng.push_back(max(A[i], A[i + (N - M)]));
	}

	int cp = max(1, M - K), ans = -(1 << 30);
	for (int i = 0; i < M - cp + 1; i++) {
		int minx = (1 << 30);
		for (int j = i; j < i + cp; j++) minx = min(minx, leng[j]);
		ans = max(ans, minx);
	}
	return ans;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		cin >> N >> M >> K;
		for (int j = 1; j <= N; j++) cin >> A[j];
		cout << solve() << endl;
	}
	return 0;
}