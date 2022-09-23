#include <bits/stdc++.h>

using namespace std;

int N;
char A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		scanf("%s", A + 1);
		int c = 0;
		for(int i = 2; i <= N; i++) c += A[i] == A[i - 1];
		printf("%d\n", (c + 1) / 2);
	}
	return 0;
}