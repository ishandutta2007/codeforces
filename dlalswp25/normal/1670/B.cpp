#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];
bool B[101010];
bool chk[30];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int K; scanf("%d", &K);
		for(int i = 0; i < 26; i++) chk[i] = false;
		for(int i = 1; i <= K; i++) {
			char c; scanf(" %c", &c);
			chk[c - 'a'] = true;
		}
		for(int i = 1; i <= N; i++) B[i] = chk[A[i] - 'a'];
		int ans = 0, cnt = -1010101010;
		for(int i = N; i >= 1; i--) {
			ans = max(ans, cnt);
			if(B[i]) cnt = 0;
			cnt++;
		}
		printf("%d\n", ans);
	}
	return 0;
}