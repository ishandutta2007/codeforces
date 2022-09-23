#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		int q = N / 2020, r = N % 2020;
		puts(q < r ? "NO" : "YES");
	}
	return 0;
}