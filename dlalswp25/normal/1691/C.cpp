#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		int l, r;
		for(l = 1; l <= N && A[l] == '0'; l++);
		for(r = N; r >= 1 && A[r] == '0'; r--);
		if(!r) { puts("0"); continue; }
		int ans = 0;
		for(int i = 2; i < N; i++) if(A[i] == '1') ans += 11;
		if(A[1] == '1') ans += 10;
		if(A[N] == '1') ans++;

		if(A[N] == '0' && N - r <= K) {
			K -= N - r;
			ans -= 10;
			if(r == 1) ans++;
			A[r] = '0';
		}
		if(l < N && A[l] == '1' && A[1] == '0' && l - 1 <= K) ans--;
		printf("%d\n", ans);
	}
	return 0;
}