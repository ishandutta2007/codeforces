#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
#pragma warning (disable: 4996)

int N, A[1 << 18], cl[1 << 18][30], cr[1 << 18][30];
map<int, int>Map;

int main() {
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		for (int j = 0; j < 30; j++) {
			if ((A[i] / (1 << j)) % 2 == 1) {
				cl[i][j] = i;
				cr[i][j] = i;
			}
			else {
				cl[i][j] = -1;
				cr[i][j] = -1;
			}
		}
	}
	for (int i = 0; i < 30; i++) { cl[0][i] = 0; cr[N + 1][i] = N + 1; }
	for (int i = 1; i <= N; i++) { for (int j = 0; j < 30; j++) { if (cl[i][j] == -1) cl[i][j] = cl[i - 1][j]; } }
	for (int i = N; i >= 1; i--) { for (int j = 0; j < 30; j++) { if (cr[i][j] == -1) cr[i][j] = cr[i + 1][j]; } }

	long long sum = 0;
	for (int i = 1; i <= N; i++) {
		long long ml = Map[A[i]] + 1, mr = (1LL << 30);
		for (int j = 0; j < 30; j++) {
			if ((A[i] / (1LL << j)) % 2 == 1) continue;
			ml = max(ml, 1LL * (cl[i - 1][j] + 1LL));
			mr = min(mr, 1LL * (cr[i + 1][j] - 1LL));
		}
		if (ml <= mr) sum += 1LL * (1LL + mr - i) * (1LL + i - ml);
		Map[A[i]] = i;
	}
	cout << 1LL * N * (N + 1LL) / 2LL - sum << endl;
	return 0;
}