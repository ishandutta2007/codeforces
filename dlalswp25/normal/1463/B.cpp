#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		for(int i = 1; i <= N; i++) {
			int a;
			scanf("%d", &a);
			ll b = 1;
			while(b <= a) b <<= 1;
			printf("%d ", b / 2);
		}
		puts("");
	}
	return 0;
}