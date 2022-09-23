#include <bits/stdc++.h>

using namespace std;

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		int N, M, x1, y1, x2, y2;
		scanf("%d%d%d%d%d%d", &N, &M, &x1, &y1, &x2, &y2);
		int ansx = (x1 > x2 ? N + N - x1 - x2 : x2 - x1);
		int ansy = (y1 > y2 ? M + M - y1 - y2 : y2 - y1);
		printf("%d\n", min(ansx, ansy));
	}
	return 0;
}