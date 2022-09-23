#include <bits/stdc++.h>

using namespace std;

int N, M;
int A[303];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) scanf("%d", &A[i]);
		int ans = 0;
		for(int i = 1; i <= M; i++) {
			for(int j = 1; j < i; j++) {
				if(A[j] < A[i]) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}