#include <bits/stdc++.h>

using namespace std;

int N;
char A[1010];
char ans[1010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);	
		scanf("%s", A + 1);

		int len = 1;
		bool ok = false;

		for(int i = 0; i < 26; i++) {
			ans[0] = 'a' + i;
			bool found = false;
			for(int j = 1; j <= N; j++) {
				if(A[j] == ans[0]) { found = true; break; }
			}
			if(!found) { ok = true; break; }
		}

		if(!ok) {
			len = 2;
			for(int i = 0; i < 26; i++) {
				ans[0] = 'a' + i;
				for(int j = 0; j < 26; j++) {
					ans[1] = 'a' + j;
					bool found = false;
					for(int k = 1; k < N; k++) {
						if(A[k] == ans[0] && A[k + 1] == ans[1]) { found = true; break; }
					}
					if(!found) { ok = true; break; }
				}
				if(ok) break;
			}
		}

		if(!ok) {
			len = 3;
			for(int i = 0; i < 26; i++) {
				ans[0] = 'a' + i;
				for(int j = 0; j < 26; j++) {
					ans[1] = 'a' + j;
					for(int k = 0; k < 26; k++) {
						ans[2] = 'a' + k;
						bool found = false;
						for(int l = 1; l < N - 2; l++) {
							if(A[l] == ans[0] && A[l + 1] == ans[1] && A[l + 2] == ans[2]) { found = true; break; }
						}
						if(!found) { ok = true; break; }
					}
					if(ok) break;
				}
				if(ok) break;
			}
		}
		for(int i = 0; i < len; i++) printf("%c", ans[i]); puts("");
	}
	return 0;
}