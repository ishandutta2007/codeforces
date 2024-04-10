#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M, X, Y, D; scanf("%d%d%d%d%d", &N, &M, &X, &Y, &D);
		bool f1 = true, f2 = true;
		if(abs(X - 1) <= D || abs(M - Y) <= D) f1 = false;
		if(abs(N - X) <= D || abs(Y - 1) <= D) f2 = false;
		if(!f1 && !f2) puts("-1");
		else printf("%d\n", N + M - 2);
	}
	return 0;
}