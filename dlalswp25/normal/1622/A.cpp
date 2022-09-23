#include <bits/stdc++.h>

using namespace std;

int A[3];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d%d", &A[0], &A[1], &A[2]);
		sort(A, A + 3);
		if(A[0] + A[1] == A[2]) puts("YES");
		else if(A[0] % 2 == 0 && A[1] == A[2]) puts("YES");
		else if(A[2] % 2 == 0 && A[0] == A[1]) puts("YES");
		else puts("NO");
	}
	return 0;
}