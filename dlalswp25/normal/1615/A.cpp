#include <bits/stdc++.h>

using namespace std;

int N, S;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		S = 0;
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			S += a;
		}
		puts(S % N ? "1" : "0");
	}
	return 0;
}