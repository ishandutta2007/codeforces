#include <bits/stdc++.h>

using namespace std;

int N;
char A[202020];

void solve() {
	scanf("%s", A + 1);
	N = strlen(A + 1);
	for(int i = N - 1; i >= 1; i--) {
		int x = A[i] - '0', y = A[i + 1] - '0';
		if(x + y >= 10) {
			A[i] = (x + y) / 10 + '0';
			A[i + 1] = (x + y) % 10 + '0';
			printf("%s\n", A + 1);
			return;
		}
	}
	A[2] = (A[1] - '0' + A[2] - '0') + '0';
	printf("%s\n", A + 2);
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		solve();
	}
	return 0;
}