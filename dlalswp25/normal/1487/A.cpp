#include <bits/stdc++.h>

using namespace std;

int N;
int A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		int mn = *min_element(A + 1, A + N + 1);
		int cnt = 0;
		for(int i = 1; i <= N; i++) if(A[i] > mn) cnt++;
		printf("%d\n", cnt);
	}
	return 0;
}