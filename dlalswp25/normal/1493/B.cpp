#include <bits/stdc++.h>

using namespace std;

int H, M;
int X[10] = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

bool valid(int h, int m) {
	if(X[m % 10] == -1 || X[m / 10] == -1) return false;
	int th = X[m % 10] * 10 + X[m / 10];
	if(X[h % 10] == -1 || X[h / 10] == -1) return false;
	int tm = X[h % 10] * 10 + X[h / 10];
	if(th >= H || tm >= M) return false;
	return true;
}

int main() {
	int tc; scanf("%d", &tc);
	while(tc--) {
		scanf("%d%d", &H, &M);
		int h, m; scanf("%02d:%02d", &h, &m);
		while(1) {
			if(valid(h, m)) break;
			m++;
			if(m >= M) { m = 0; h++; }
			if(h >= H) h -= H;
		}
		printf("%02d:%02d\n", h, m);
	}
	return 0;
}