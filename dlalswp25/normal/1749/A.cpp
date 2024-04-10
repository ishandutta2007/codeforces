#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		for(int i = 1; i <= M; i++) scanf("%*d%*d");
		puts(N > M ? "YES" : "NO");
	}
	return 0;
}