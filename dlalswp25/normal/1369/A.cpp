#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int N; scanf("%d", &N);
		puts(N % 4 ? "NO" : "YES");
	}
	return 0;
}