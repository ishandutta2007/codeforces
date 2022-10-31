#include <bits/stdc++.h>
using namespace std;


int main() {
	int x1, y1, x2, y2;
	scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
	printf("%d\n", 2 * (max(x1, x2) + y1 + y2 + 2));
	return 0;
}