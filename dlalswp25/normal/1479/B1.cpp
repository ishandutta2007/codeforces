#include <bits/stdc++.h>

using namespace std;

int N;
int A[101010];
int nxt[101010];

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
	nxt[N] = 0;
	for(int i = N - 1; i >= 1; i--) {
		if(A[i] == A[i + 1]) nxt[i] = nxt[i + 1];
		else nxt[i] = A[i + 1];
	}
	int x = -1, y = -1;
	int ans = 0;
	for(int i = 1; i <= N; i++) {
		if(x != A[i]) {
			if(y != A[i]) {
				if(nxt[i] == x) {
					ans++; x = A[i];
				}
				else {
					ans++; y = A[i];
				}
			}
			else {
				ans++; x = A[i];
			}
		}
		else if(y != A[i]) {
			ans++; y = A[i];
		}
	}
	printf("%d\n", ans);
	return 0;
}