#include <bits/stdc++.h>

using namespace std;

int N, K;
char A[1010101];
char B[1010101];

int cnt1[30];
int cnt2[30];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		scanf("%s", B + 1);

		for(int i = 0; i < 26; i++) cnt1[i] = cnt2[i] = 0;
		for(int i = 1; i <= N; i++) cnt1[A[i] - 'a']++;
		for(int i = 1; i <= N; i++) cnt2[B[i] - 'a']++;

		bool ok = true;
		for(int i = 0; i < 25; i++) {
			if(cnt1[i] < cnt2[i]) { ok = false; break; }
			int diff = cnt1[i] - cnt2[i];
			if(diff % K) { ok = false; break; }

			cnt1[i + 1] += diff;
		}
		puts(ok ? "Yes" : "No");
	}
	return 0;
}