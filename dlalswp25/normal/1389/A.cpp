#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int l, r; scanf("%d%d", &l, &r);
		if(l * 2 > r) { puts("-1 -1"); continue; }
		printf("%d %d\n", l, 2 * l);
	}
	return 0;
}