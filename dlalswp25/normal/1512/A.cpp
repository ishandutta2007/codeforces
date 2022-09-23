#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

pii A[105];

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			scanf("%d", &A[i].first);
			A[i].second = i;
		}
		sort(A + 1, A + N + 1);
		if(A[1].first != A[2].first) printf("%d\n", A[1].second);
		else printf("%d\n", A[N].second);
	}
	return 0;
}