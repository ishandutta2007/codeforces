#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N;
		scanf("%d", &N);
		if(N % 7 == 0) { printf("%d\n", N); continue; }
		for(int i = 0; i < 10; i++) {
			int t = (N / 10) * 10 + i;
			if(t % 7 == 0) { printf("%d\n", t); break; }
		}
	}
	return 0;
}