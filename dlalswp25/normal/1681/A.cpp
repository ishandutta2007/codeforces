#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a = 0, b = 0;
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			a = max(a, x);
		}
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int x; scanf("%d", &x);
			b = max(b, x);
		}
		puts(a >= b ? "Alice" : "Bob");
		puts(a <= b ? "Bob" : "Alice");
	}
	return 0;
}