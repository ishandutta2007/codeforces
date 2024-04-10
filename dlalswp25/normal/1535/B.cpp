#include <bits/stdc++.h>

using namespace std;

int N;
int A[2020];

int gcd(int a, int b) { while(b) { a %= b; swap(a, b); } return a; }

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &A[i]);
		sort(A + 1, A + N + 1, [&](const int a, const int b) {
			return a % 2 < b % 2;
		});
		int ans = 0;
		for(int i = 1; i <= N; i++) {
			for(int j = i + 1; j <= N; j++) {
				if(gcd(A[i], 2 * A[j]) > 1) ans++;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}