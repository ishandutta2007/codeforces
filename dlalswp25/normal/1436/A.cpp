#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		int s = 0;
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			s += x;
		}
		puts(M == s ? "YES" : "NO");
	}
	return 0;
}