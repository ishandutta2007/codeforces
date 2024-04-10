#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int x, y; scanf("%d%d", &x, &y);
		if(x < y) swap(x, y);
		if(x == y) printf("%d\n", x + y);
		else printf("%d\n", 2 * y + 1 + (x - y - 1) * 2);
	}
	return 0;
}