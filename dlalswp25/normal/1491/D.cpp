#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int u, v; scanf("%d%d", &u, &v);
		if(u > v) { puts("NO"); continue; }
		int ux = 0, vx = 0;
		bool ok = true;
		for(int i = 0; i < 30; i++) {
			if(u & 1 << i) ux++;
			if(v & 1 << i) vx++;
			if(ux < vx) ok = false;
		}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}