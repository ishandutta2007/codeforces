#include <bits/stdc++.h>

using namespace std;

int main() {
	int y, b, r; scanf("%d%d%d", &y, &b, &r);
	b--; r--; r--;
	int x = min(y, b); x = min(x, r);
	printf("%d\n", x * 3 + 3);
	return 0;
}