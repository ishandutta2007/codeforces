#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		int x, y;
		int mx = -1010101010;
		for(int i = 1; i <= N; i++) {
			for(int j = 1; j <= M; j++) {
				int a; scanf("%d", &a);
				if(a > mx) {
					mx = a;
					x = i; y = j;
				}
			}
		}
		printf("%d\n", max(x, N - x + 1) * max(y, M - y + 1));
	}
	return 0;
}