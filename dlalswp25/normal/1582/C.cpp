#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int ans = N + 1;
		for(int i = 'a'; i <= 'z'; i++) {
			int l = 1, r = N;
			int cnt = 0;
			while(l < r) {
				if(A[l] == A[r]) { l++; r--; continue; }
				if(A[l] != i && A[r] != i) { cnt = N + 1; break; }
				if(A[l] != i) { cnt++; r--; }
				else if(A[r] != i) { cnt++; l++; }
			}
			ans = min(ans, cnt);
		}
		printf("%d\n", ans > N ? -1 : ans);
	}
	return 0;
}