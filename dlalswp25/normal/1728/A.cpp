#include <bits/stdc++.h>

using namespace std;

int N;
int A[25];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		printf("%d\n", max_element(A + 1, A + N + 1) - A);
	}
	return 0;
}