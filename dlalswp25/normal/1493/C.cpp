#include <bits/stdc++.h>

using namespace std;

int N, K;
int cnt[30];
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		scanf("%s", A + 1);
		if(N % K) { puts("-1"); continue; }
		for(int i = 0; i < 26; i++) cnt[i] = 0;
		for(int i = 1; i <= N; i++) cnt[A[i] - 'a']++;

		bool ok = true;
		for(int i = 0; i < 26; i++) if(cnt[i] % K) ok = false;
		if(ok) { printf("%s\n", A + 1); continue; }

		for(int i = N - 1; i >= 0; i--) {
			char c = A[i + 1];
			cnt[c - 'a']--;
			ok = false;
			for(int j = c + 1; j <= 'z'; j++) {
				cnt[j - 'a']++;
				int x = 0;
				for(int k = 0; k < 26; k++) x += (K - cnt[k] % K) % K;
				if(x > N - i - 1) { cnt[j - 'a']--; continue; }
				A[i + 1] = j;

				int lft = N - i - 1 - x;
				int k = i + 2;
				while(lft) { A[k] = 'a'; lft--; k++; }

				int p = 'a';
				for(; k <= N; k++) {
					while(p <= 'z' && cnt[p - 'a'] % K == 0) p++;
					if(p > 'z') break;
					A[k] = p; cnt[p - 'a']++;
				}
				ok = true;
				break;
			}
			if(ok) break;
		}
		printf("%s\n", A + 1);
	}
	return 0;
}