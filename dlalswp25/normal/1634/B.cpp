#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int N;
ll X, Y;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%lld%lld", &N, &X, &Y);
		for(int i = 1; i <= N; i++) {
			int a; scanf("%d", &a);
			X += a;
		}
		puts(X % 2 == Y % 2 ? "Alice" : "Bob");
	}
	return 0;
}