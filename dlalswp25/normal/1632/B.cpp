#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int M = 1;
		while(M < N) M <<= 1;
		M >>= 1;
		for(int i = M - 1; i >= 0; i--) printf("%d ", i);
		for(int i = M; i < N; i++) printf("%d ", i); puts("");
	}
	return 0;
}