#include <bits/stdc++.h>

using namespace std;

char A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		int N = strlen(A + 1);
		if(A[1] != A[N]) A[N] = A[1];
		printf("%s\n", A + 1);
	}
	return 0;
}