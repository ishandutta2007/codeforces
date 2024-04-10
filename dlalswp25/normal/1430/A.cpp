#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N < 3 || N == 4) puts("-1");
		else if(N % 3 == 0) printf("%d %d %d\n", N / 3, 0, 0);
		else if(N % 3 == 1) printf("%d %d %d\n", N / 3 - 2, 0, 1);
		else printf("%d %d %d\n", N / 3 - 1, 1, 0);
	}
	return 0;
}