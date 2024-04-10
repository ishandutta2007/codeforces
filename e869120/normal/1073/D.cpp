#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, X, S, A[1 << 18], rem, cnt, minx = (1LL << 60);

int main() {
	scanf("%lld%lld", &N, &X);
	for (int i = 0; i < N; i++) { scanf("%lld", &A[i]); S += A[i]; minx = min(minx, A[i]); }

	long long rem = N;

	while (true) {
		if (X >= S) { cnt += (X / S) * rem; X -= (X / S) * S; }
		else {
			for (int i = 0; i < N; i++) {
				if (X >= A[i]) { X -= A[i]; cnt++; }
			}
			S = 0; rem = 0;
			for (int i = 0; i < N; i++) {
				if (X >= A[i]) { S += A[i]; rem++; }
			}
		}
		if (X < minx) break;
	}
	cout << cnt << endl;
	return 0;
}