#include <bits/stdc++.h>

using namespace std;

char A[202020];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%s", A + 1);
		int N = strlen(A + 1);
		int sa = 0, sb = 0;
		for(int i = 1; i <= N; i++) sa += (A[i] - 'a' + 1);
		if(N & 1) {
			sb = min(A[1], A[N]) - 'a' + 1;
			sa -= sb;
		}
		if(sa > sb) printf("Alice %d\n", sa - sb);
		else printf("Bob %d\n", sb - sa);
	}
	return 0;
}