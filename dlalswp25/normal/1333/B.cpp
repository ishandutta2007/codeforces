#include <bits/stdc++.h>

using namespace std;

int A[101010];
int B[101010];
int N;

int state[101010];

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		for(int i = 1; i <= N; i++) scanf("%d", &B[i]);

		for(int i = 1; i <= N; i++) {
			int x = -1;
			if(A[i] == 1) x = 0;
			if(A[i] == -1) x = 1;
			state[i] = state[i - 1];
			if(x >= 0) state[i] |= (1 << x);
		}
		// for(int i = 1; i <= N; i++) printf("%d ", state[i]); puts("");

		bool ok = true;
		for(int i = N; i >= 1; i--) {
			if(A[i] == B[i]) continue;
			if(A[i] < B[i]) {
				if(!(state[i - 1] & 1)) ok = false;
			}
			if(A[i] > B[i]) {
				if(!(state[i - 1] & 2)) ok = false;
			}
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}