#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x, y; scanf("%d%d", &x, &y);
		if(!x && !y) { puts("0"); continue; }
		int d = x * x + y * y;
		bool ok = false;
		for(int i = 1; i <= 100; i++) {
			if(i * i == d) ok = true;
		}
		puts(ok ? "1" : "2");
	}
	return 0;
}