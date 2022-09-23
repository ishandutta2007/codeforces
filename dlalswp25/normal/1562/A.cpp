#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int l, r; scanf("%d%d", &l, &r);
		if(l * 2 - 1 > r) {
			printf("%d\n", r - l);
		}
		else {
			printf("%d\n", (r + 1) / 2 - 1);
		}
	}
	return 0;
}