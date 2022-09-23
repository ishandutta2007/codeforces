#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];
bool D[202020];

int main() {
	scanf("%d", &N);
	int S = 0;
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i]);
		S += A[i];
	}
	D[0] = true;
	for(int i = 1; i <= N; i++) {
		for(int j = 200000; j >= A[i]; j--) {
			D[j] = (D[j] || D[j - A[i]]);
		}
	}
	if((S & 1) || !D[S / 2]) { puts("0"); return 0; }

	puts("1");
	int ans = 0;
	while(1) {
		for(int i = 1; i <= N; i++) {
			if(A[i] & 1) { ans = i; break; }
		}
		if(ans) { printf("%d\n", ans); break; }
		for(int i = 1; i <= N; i++) A[i] >>= 1;
	}
	return 0;
}