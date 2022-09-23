#include <bits/stdc++.h>

using namespace std;

int A[50505];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		if(A[1] + A[2] > A[N]) puts("-1");
		else printf("%d %d %d\n", 1, 2, N);
	}
	return 0;
}