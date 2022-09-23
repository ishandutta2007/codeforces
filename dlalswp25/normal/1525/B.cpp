#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		bool sorted = true;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(A[i] != i) sorted = false;
		}
		if(sorted) puts("0");
		else if(A[1] == 1 || A[N] == N) puts("1");
		else if(A[1] == N && A[N] == 1) puts("3");
		else puts("2");
	}
	return 0;
}