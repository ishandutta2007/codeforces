#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b; scanf("%d%d", &a, &b);
		if(a + b & 1) puts("-1 -1");
		else if(a > b) printf("%d %d\n", a + b >> 1, 0);
		else printf("%d %d\n", 0, a + b >> 1);
	}
	return 0;
}