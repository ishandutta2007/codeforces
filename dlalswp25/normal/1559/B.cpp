#include <bits/stdc++.h>

using namespace std;

int N;
char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		for(int i = 1; i <= N; i++) {
			if(A[i] != '?') continue;
			if(i == 1 || A[i - 1] == '?') continue;
			if(A[i - 1] == 'B') A[i] = 'R';
			else A[i] = 'B';
		}
		if(A[N] == '?') A[N] = 'B';

		for(int i = N - 1; i >= 1; i--) {
			if(A[i] != '?') continue;
			if(A[i + 1] == 'B') A[i] = 'R';
			else A[i] = 'B';
		}
		for(int i = 1; i <= N; i++) printf("%c", A[i]); puts("");
	}
	return 0;
}