#include <bits/stdc++.h>

using namespace std;

int N, H;
int A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &H);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1);
		int t = H / (A[N - 1] + A[N]);
		H -= t * (A[N - 1] + A[N]);
		if(!H) printf("%d\n", 2 * t);
		else if(H <= A[N]) printf("%d\n", 2 * t + 1);
		else printf("%d\n", 2 * t + 2);
	}
	return 0;
}