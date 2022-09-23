#include <bits/stdc++.h>

using namespace std;

char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		int N = strlen(A + 1);
		if(N & 1) { puts("NO"); continue; }
		int s = 0, t = N / 2 - 1;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			if(A[i] == '?') {
				if(t) { t--; s++; }
				else s--;
			}
			else if(A[i] == '(') s++;
			else s--;
			if(s < 0) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}