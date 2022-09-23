#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];
bool chk[30];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		N = strlen(A + 1);
		for(int i = 0; i < 26; i++) chk[i] = false;
		int M = 0;
		for(int i = 1; i <= N; i++) {
			if(!chk[A[i] - 'a']) { chk[A[i] - 'a'] = true; M++; }
		}
		bool ok = true;
		for(int i = 1; i <= M; i++) {
			for(int j = i; j <= N; j += M) if(A[j] != A[i]) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}