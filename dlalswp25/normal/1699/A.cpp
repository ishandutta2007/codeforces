#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N & 1) puts("-1");
		else printf("%d %d %d\n", N / 2, 0, 0);
	}
	return 0;
}