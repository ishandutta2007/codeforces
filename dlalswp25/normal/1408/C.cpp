#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[101010];
double L[101010];
double R[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		A[N + 1] = X; R[N + 1] = 0;

		for(int i = 1; i <= N + 1; i++) {
			L[i] = L[i - 1] + (double)(A[i] - A[i - 1]) / i;
		}
		for(int i = N; i >= 0; i--) {
			R[i] = R[i + 1] + (double)(A[i + 1] - A[i]) / (N - i + 1);
		}

		double l = 0, r = 2e9;
		for(int i = 0; i < 80; i++) {
			double m = (l + r) / 2;
			int j;
			for(j = 1; j <= N + 1; j++) {
				if(L[j] > m) break;
			}
			if(j > N + 1) { r = m; continue; }
			j--;
			double lx = (m - L[j]) * (j + 1) + A[j];

			for(j = N; j >= 0; j--) {
				if(R[j] > m) break;
			}
			if(j < 0) { r = m; continue; }
			j++;
			double rx = A[j] - (m - R[j]) * (N + 2 - j);

			if(lx < rx) l = m;
			else r = m;
		}
		printf("%.10f\n", l);
	}
	return 0;
}