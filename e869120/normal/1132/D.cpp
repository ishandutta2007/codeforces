#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, A[1 << 18], B[1 << 18];

bool solve(long long I) {
	vector<long long>E;
	for (int i = 0; i < N; i++) {
		if (B[i] <= I) {
			long long V = A[i], cx = 0;
			while (true) {
				long long F = V / B[i]; if (cx + F >= K) break;
				E.push_back(cx + F);
				V += (A[i] * B[i]);
				V %= B[i]; V += (I - B[i]);
				cx += F + 1;
			}
		}
		else {
			long long U = A[i] - K * B[i];
			if (U < 0) {
				if (I == 0) return false;
				U *= -1;
				long long R = (U + I - 1LL) / I;
				if (R > K) return false;
				for (int j = 0; j < R; j++) E.push_back(K - 1 - j);
			}
		}
		if (E.size() > K) return false;
	}
	sort(E.begin(), E.end());
	for (int i = 0; i < E.size(); i++) {
		if (E[i] < i) return false;
	}
	return true;
}

int main() {
	cin >> N >> K; K--;
	for (int i = 0; i < N; i++) scanf("%lld", &A[i]);
	for (int i = 0; i < N; i++) scanf("%lld", &B[i]);
	
	long long L = 0, R = (1LL << 41), M, minx = (1LL << 41);
	for (int i = 0; i < 50; i++) {
		M = (L + R) / 2;
		bool t = solve(M);
		if (t == true) { minx = min(minx, M); R = M; }
		else { L = M; }
	}
	if (minx == (1LL << 41)) cout << "-1" << endl;
	else cout << minx << endl;
	return 0;
}