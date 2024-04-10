#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N; scanf("%d", &N);
		if(N <= 3) puts("Bob");
		else if(N & 1) puts("Bob");
		else {
			bool ok = true;
			while(N > 8) {
				if(N & 3) { ok = false; break; }
				N >>= 2;
			}
			if(ok && N == 8) puts("Bob");
			else puts("Alice");
		}
	}
	return 0;
}