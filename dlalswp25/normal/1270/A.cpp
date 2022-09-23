#include <bits/stdc++.h>

using namespace std;

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		int n, a, b; scanf("%d%d%d", &n, &a, &b);
		bool ok = true;
		for(int i = 1; i <= a; i++) { int x; scanf("%d", &x); }
		for(int i = 1; i <= b; i++) {
			int x; scanf("%d", &x);
			if(x == n) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}