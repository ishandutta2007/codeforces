#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N <= 3) printf("%d\n", N - 1);
		else if(N % 2 == 0) puts("2");
		else puts("3");
	}
	return 0;
}