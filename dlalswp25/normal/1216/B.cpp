#include <bits/stdc++.h>

using namespace std;
typedef pair<int, int> pii;

int N;
pii A[1010];
int ans;

int main() {
	scanf("%d", &N);
	for(int i = 1; i <= N; i++) {
		scanf("%d", &A[i].first);
		A[i].second = i;
	}
	sort(A + 1, A + N + 1);
	reverse(A + 1, A + N + 1);

	for(int i = 1; i <= N; i++) {
		ans += (i - 1) * A[i].first + 1;
	}
	printf("%d\n", ans);
	for(int i = 1; i <= N; i++) printf("%d ", A[i].second); puts("");

	return 0;
}