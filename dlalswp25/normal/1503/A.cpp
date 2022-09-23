#include <bits/stdc++.h>

using namespace std;

int N;
char S[202020];
int A[202020];
int B[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", S + 1);
		int zero = 0;
		for(int i = 1; i <= N; i++) zero += (S[i] == '0');
		if((N & 1) || (zero & 1)) { puts("NO"); continue; }

		int cnt = 0;
		for(int i = 1; i <= N; i++) {
			if(S[i] == '0') {
				if(cnt & 1) { A[i] = 1; B[i] = -1; }
				else { A[i] = -1; B[i] = 1; }
				cnt++;
			}
		}

		cnt = 0;
		for(int i = 1; i <= N; i++) {
			if(S[i] == '0') continue;
			if(cnt < (N - zero) / 2) A[i] = B[i] = 1;
			else A[i] = B[i] = -1;
			cnt++;
		}

		int sa = 0, sb = 0;
		bool ok = true;
		for(int i = 1; i <= N; i++) {
			sa += A[i]; sb += B[i];
			if(sa < 0 || sb < 0) ok = false;
		}
		if(!ok) { puts("NO"); continue; }
		puts("YES");
		for(int i = 1; i <= N; i++) printf("%c", A[i] == 1 ? '(' : ')'); puts("");
		for(int i = 1; i <= N; i++) printf("%c", B[i] == 1 ? '(' : ')'); puts("");
	}
	return 0;
}