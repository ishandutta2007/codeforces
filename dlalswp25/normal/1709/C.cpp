#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		int cnt[2] = {0, 0};
		for(int i = 1; i <= N; i++) {
			if(A[i] != '?') {
				cnt[A[i] == '(' ? 0 : 1]++;
			}
		}
		if(cnt[0] == N / 2 || cnt[1] == N / 2) { puts("YES"); continue; }
		int s = 0, mn = N + 1;
		bool fg = false;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '(') s++;
			else if(A[i] == ')') s--;
			else {
				if(cnt[0] == N / 2 - 1) {
					if(fg) { cnt[0]++; s++; }
					else { fg = true; s--; }
				}
				else if(cnt[0] < N / 2) {
					cnt[0]++; s++;
				}
				else s--;
			}
			mn = min(mn, s);
		}
		puts(mn < 0 ? "YES" : "NO");
	}
	return 0;
}