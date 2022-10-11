#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

long long N, M, A, B, V, Q; vector<long long>H1, H2;

int main() {
	cin >> N >> M >> A >> B >> V;
	for (int i = 0; i < A; i++) { long long P; scanf("%lld", &P); H1.push_back(P); }
	for (int i = 0; i < B; i++) { long long P; scanf("%lld", &P); H2.push_back(P); }
	sort(H1.begin(), H1.end());
	sort(H2.begin(), H2.end());
	cin >> Q;
	for (int i = 0; i < Q; i++) {
		long long px, py, qx, qy; cin >> px >> py >> qx >> qy;
		long long L = qy, R = py, minx = (1LL << 60); if (L > R) swap(L, R);

		if (px == qx) {
			minx = min(minx, abs(L - R));
		}

		int pos1 = lower_bound(H1.begin(), H1.end(), L) - H1.begin();
		for (int j = pos1 - 1; j <= pos1 + 1; j++) {
			if (j < 0 || j >= H1.size()) continue;
			minx = min(minx, abs(L - H1[j]) + abs(H1[j] - R) + abs(px - qx));
		}
		int pos2 = lower_bound(H2.begin(), H2.end(), L) - H2.begin();
		for (int j = pos2 - 1; j <= pos2 + 1; j++) {
			if (j < 0 || j >= H2.size()) continue;
			minx = min(minx, abs(L - H2[j]) + abs(H2[j] - R) + (abs(px - qx) + V - 1) / V);
		}
		printf("%lld\n", minx);
	}
	return 0;
}