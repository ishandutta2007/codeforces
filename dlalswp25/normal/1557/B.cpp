#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N, K;
pii A[101010];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &N, &K);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].first);
			A[i].second = i;
		}
		sort(A + 1, A + N + 1);
		int c = 0;
		for(int i = 1; i < N; i++) {
			if(A[i].second + 1 != A[i + 1].second) c++;
		}
		puts(c <= K - 1 ? "Yes" : "No");
	}
	return 0;
}