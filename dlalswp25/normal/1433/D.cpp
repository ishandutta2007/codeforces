#include <bits/stdc++.h>

using namespace std;

int N;
int A[5050];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		int dif = 0;
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i]);
			if(!dif && i > 1 && A[i] != A[i - 1]) dif = i;
		}
		if(!dif) { puts("NO"); continue; }
		puts("YES");
		printf("%d %d\n", 1, dif);
		for(int i = 2; i <= N; i++) {
			if(i == dif) continue;
			if(A[i] == A[1]) printf("%d %d\n", i, dif);
			else printf("%d %d\n", i, 1);
		}
	}
	return 0;
}