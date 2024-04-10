#include <bits/stdc++.h>

using namespace std;

int N;
int A[3030];
int D[3030][3030];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 2; i <= N; i++) {
			vector<int> v;
			for(int j = i - 1; j >= 1; j--) {
				D[i][j] = 0;
				D[i][j] = max(D[i - 1][j], D[i][j + 1]);
				if(A[j] == A[i]) v.push_back(j);
				for(int k : v) {
					D[i][j] = max(D[i][j], D[i - 1][k] + D[k][j] + 1);
				}
			}
		}
		printf("%d\n", N - 1 - D[N][1]);
	}
	return 0;
}