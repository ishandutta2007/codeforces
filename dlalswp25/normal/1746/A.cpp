#include <bits/stdc++.h>

using namespace std;

int N, K;
int A[55];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		puts(*max_element(A + 1, A + N + 1) == 1 ? "YES" : "NO");	
	}
	return 0;
}