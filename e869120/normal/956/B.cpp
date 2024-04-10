#include <iostream>
#include <algorithm>
using namespace std;
#pragma warning (disable: 4996)

int N, U, A[100009]; long double maxn = -1.0;

int main() {
	scanf("%d%d", &N, &U);
	for (int i = 0; i < N; i++) scanf("%d", &A[i]);
	sort(A, A + N);

	for (int i = 0; i < N; i++) {
		int pos1 = i;
		int pos2 = i + 1;
		int pos3 = lower_bound(A, A + N, A[i] + U + 1) - A; pos3--;
		if (pos1 < pos2 && pos2 < pos3) { maxn = max(maxn, 1.0L * (A[pos3] - A[pos2]) / (A[pos3] - A[pos1])); }
	}
	if (maxn < -0.5) cout << "-1" << endl;
	else printf("%.12Lf\n", maxn);
	return 0;
}