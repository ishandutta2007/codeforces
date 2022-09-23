#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			int z = 0;
			for(int j = i; j <= N; j++) {
				if(A[j] == 0) z++;
				ans += (j - i + 1 + z);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}