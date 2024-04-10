#include <bits/stdc++.h>

using namespace std;

int N, X;
int A[101010];
map<int, int> mp;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		mp.clear();
		scanf("%d%d", &N, &X);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);

		sort(A + 1, A + N + 1);
		reverse(A + 1, A + N + 1);
		int cnt = 0;
		int ans = 0;

		for(int i = 1; i <= N; i++) {
			cnt++;
			if((X + A[i] - 1) / A[i] <= cnt) {
				cnt = 0; ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}