#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M; scanf("%d%d", &N, &M);
		puts(N % M == 0 ? "YES" : "NO");
	}
	return 0;
}