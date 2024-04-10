#include <bits/stdc++.h>
 
using namespace std;
 
int N, M;
char A[1010];
int L[1010];
int R[1010];
 
int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &M);
		scanf("%s", A + 1);
		int x = -1100000000;
		for(int i = 1; i <= N; i++) {
			L[i] = x;
			if(A[i] == '1') x = i;
		}
		x = 1100000000;
		for(int i = N; i >= 1; i--) {
			R[i] = x;
			if(A[i] == '1') x = i;
		}
 
		for(int i = 1; i <= N; i++) {
			if(A[i] == '1') continue;
			if(i - L[i] == R[i] - i) continue;
			int t = min(i - L[i], R[i] - i);
			if(t <= M) A[i] = '1';
		}
		for(int i = 1; i <= N; i++) printf("%c", A[i]); puts("");
	}
	return 0;
}