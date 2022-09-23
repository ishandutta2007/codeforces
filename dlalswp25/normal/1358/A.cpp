#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, M; scanf("%d%d", &N, &M);
		if((N & 1) && (M & 1)) printf("%d\n", N * M / 2 + 1);
		else printf("%d\n", N * M / 2);
	}
	return 0;
}