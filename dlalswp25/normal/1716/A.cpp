#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N == 1) puts("2");
		else printf("%d\n", (N + 2) / 3);	
	}
	return 0;
}