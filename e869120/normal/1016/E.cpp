#include <iostream>
#include <algorithm>
using namespace std;

long double sy, a, b, L[200009], R[200009], S[200009]; int n, q;

long double range(int pl, int pr) {
	if (pl == 0) return S[pr];
	return S[pr] - S[pl - 1];
}

int main() {
	cin >> sy >> a >> b;
	cin >> n;
	for (int i = 0; i < n; i++) { scanf("%Lf%Lf", &L[i], &R[i]); S[i] = R[i] - L[i]; }
	for (int i = 1; i < n; i++) S[i] += S[i - 1];
	cin >> q;
	for (int i = 1; i <= q; i++) {
		long double px, py; scanf("%Lf%Lf", &px, &py);
		long double fl = (px * -sy + a * py) / (py - sy);
		long double fr = (px * -sy + b * py) / (py - sy);
		int pos1 = lower_bound(L, L + n, fl) - L;
		int pos2 = lower_bound(R, R + n, fr) - R; pos2--;

		if (pos2 - pos1 <= 0) {
			long double sum = 0;
			for (int j = max(0, pos1 - 1); j <= min(n - 1, pos2 + 1); j++) {
				sum += max(0.0L, min(R[j], fr) - max(L[j], fl));
			}
			printf("%.12Lf\n", sum * (b - a) / (fr - fl));
		}
		else {
			long double E1 = range(pos1, pos2);
			long double E2 = 0; if (pos1 >= 1) E2 = max(E2, R[pos1 - 1] - fl);
			long double E3 = 0; if (pos2 < n - 1) E3 = max(E3, fr - L[pos2 + 1]);
			printf("%.12Lf\n", (E1 + E2 + E3) * (b - a) / (fr - fl));
		}
	}
	return 0;
}