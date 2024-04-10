#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, d; scanf("%d%d", &n, &d);

		bool ok = false;
		for(int i = 0; i <= 1000000; i++) {
			int t = d / (i + 1);
			if(d % (i + 1)) t++;
			if(i + t <= n) ok = true;
		}
		puts(ok ? "YES" : "NO");
	}

	return 0;
}