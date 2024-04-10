#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int x = 0;
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			x += a - 1;
		}
		puts(x & 1 ? "errorgorn" : "maomao90");
	}
	return 0;
}