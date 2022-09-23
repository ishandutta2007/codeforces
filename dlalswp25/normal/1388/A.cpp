#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N <= 30) { puts("NO"); continue; }
		puts("YES");
		if(N == 36 || N == 40 || N == 44) printf("6 10 15 %d\n", N - 31);
		else printf("6 10 14 %d\n", N - 30);
	}
	return 0;
}