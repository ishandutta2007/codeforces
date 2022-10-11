#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, K, A, B, minx = (1LL << 60), maxn = -(1LL << 60); vector<long long>E1, E2;

long long gcd(long long a, long long b) {
	if (b == 0) return a;
	return gcd(b, a % b);
}

int main() {
	cin >> N >> K >> A >> B;
	E1.push_back(A); E1.push_back(K - A);
	E2.push_back(B); E2.push_back(K - B);

	for (int i = 0; i < E1.size(); i++) {
		for (int j = 0; j < E2.size(); j++) {
			long long SA = E2[j] - E1[i];
			for (int k = 0; k <= N; k++) {
				long long V = 1LL * k * K + SA;
				if (V <= 0 || V > N * K) continue;
				long long VV = (N * K) / gcd(V, N * K);
				minx = min(minx, VV);
				maxn = max(maxn, VV);
			}
		}
	}
	cout << minx << " " << maxn << endl;
	return 0;
}