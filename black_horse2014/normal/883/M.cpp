#include<bits/stdc++.h>
using namespace std;

int main() {
	int x1, y1, x2, y2; cin >> x1 >> y1 >> x2 >> y2;
	int dx = abs(x1 - x2), dy = abs(y1 - y2);
	dx = max(2, dx + 1), dy = max(2, dy + 1);
	printf("%d\n", 2 * (dx + dy));
	return 0;
}