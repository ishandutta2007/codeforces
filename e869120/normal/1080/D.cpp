#include <iostream>
#include <algorithm>
using namespace std;

long long T;
long long INF = 3010000000000000000LL;

long long solve(long long N, long long K) {
	long long L = 4, R = 4, S = 4;
	for (int i = 1; i <= min(64LL, N); i++) {
		// R 
		if (N >= 32) R = (1LL << 62);
		else {
			long long V1 = (2LL << i) - 1LL; V1 = min(V1, INF);
			long long V2 = (1LL << N) - (1LL << (N - i)); if (V2 >= 2000000000LL) V2 = 2000000000LL;
			V2 *= V2; V2 = min(V2, INF);

			R = V1 + V2; R = min(R, INF);
		}

		if (L <= K * 3LL + 1LL && K * 3LL + 1LL <= R) {
			return N - i;
		}
		L += (S - 1LL) * 3LL; L = min(L, INF);
		S *= 2LL; S = min(S, INF / 3);
	}
	return -1;
}

int main() {
	cin >> T;
	for (int i = 1; i <= T; i++) {
		long long A, B; cin >> A >> B;
		long long C = solve(A, B);
		if (C == -1) cout << "NO" << endl;
		else cout << "YES " << C << endl;
	}
	return 0;
}