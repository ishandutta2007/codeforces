#include <bits/stdc++.h>

using namespace std;

int N, M;
char S[505];
char T[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", S + 1);
		scanf("%s", T + 1);
		N = strlen(S + 1);
		M = strlen(T + 1);
		bool ans = false;
		for(int i = 1; i <= N; i++) {
			for(int j = i; j <= N; j++) {
				bool ok = true;
				int p = 1;
				for(int k = i; k <= j; k++) {
					if(p > M || T[p] != S[k]) { ok = false; break; }
					p++;
				}
				if(!ok) continue;

				int q = j - 1;
				while(p <= M) {
					if(q < 1 || T[p] != S[q]) { ok = false; break; }
					q--; p++;
				}

				if(ok) { ans = true; break; }
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}