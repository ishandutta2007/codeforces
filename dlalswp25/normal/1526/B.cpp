#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N > 10 * 110) puts("YES");
		else {
			bool ok = false;
			for(int i = 0; 111 * i <= N; i++) {
				if((N - 111 * i) % 11 == 0) ok = true;
			}
			puts(ok ? "YES" : "NO");
		}
	}
	return 0;
}