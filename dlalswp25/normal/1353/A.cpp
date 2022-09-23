#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N, X; scanf("%d %d", &N, &X);
		if(N == 1) puts("0");
		else if(N == 2) printf("%d\n", X);
		else printf("%d\n", X * 2);
	}
	return 0;
}