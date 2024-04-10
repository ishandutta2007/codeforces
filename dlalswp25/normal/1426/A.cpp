#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, X; scanf("%d%d", &N, &X);
		if(N <= 2) puts("1");
		else printf("%d\n", (N - 3) / X + 2);
	}
	return 0;
}