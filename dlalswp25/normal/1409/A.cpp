#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int a, b; scanf("%d%d", &a, &b);
		if(a == b) puts("0");
		else printf("%d\n", (abs(a - b) - 1) / 10 + 1);
	}
	return 0;
}