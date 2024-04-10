#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M; scanf("%d%d", &N, &M);
		if(N == 1 || M == 1) printf("1 1\n");
		else printf("2 2\n");
	}
	return 0;
}