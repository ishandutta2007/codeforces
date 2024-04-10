#include <iostream>
#include <algorithm>
using namespace std;

long long N, D, B, A[200009], I[200009], J[200009];

bool solve(long long V) {
	for (long long i = 1LL; i <= N; i++) J[i] = A[i];
	long long cx = 0;
	for (long long i = V + 1LL; i <= N - V; i++) {
		long long rem = B;
		while (true) {
			if (J[cx] >= rem) {
				J[cx] -= rem; rem = 0;
				break;
			}
			else {
				rem -= J[cx]; J[cx] = 0;
				cx++;
			}
			if (cx == N + 1) break;
		}
		if (abs(cx - i) > I[i] * D || rem != 0) return false;
		cx = max(cx, 1LL * (i + 1) - I[i + 1] * D);
	}
	return true;
}

int main() {
	cin >> N >> D >> B;
	for (long long i = 1; i <= N; i++) cin >> A[i];
	for (long long i = 1; i <= N; i++) I[i] = min(1LL * i, N + 1 - i);
	long long L = 0, R = N / 2, M, minx = (1 << 30);
	for (long long i = 1; i <= 30; i++) {
		M = (L + R) / 2;
		bool T = solve(M);
		if (T == true) { minx = min(minx, M); R = M; }
		else { L = M; }
	}
	cout << minx << endl;
	return 0;
}