#include <bits/stdc++.h>

using namespace std;

int P[404040];
int N;

void f() {
	puts("0 0 0");
}

int main() {
	int T; scanf("%d", &T);
	while(T--) {
		scanf("%d", &N);
		for(int i = 1; i <= N; i++) scanf("%d", &P[i]);
		int cut = P[N / 2 + 1];

		int x = N / 2;
		while(x >= 1 && P[x] == cut) x--;

		if(x < 1) { f(); continue; }

		int y = 1;
		while(y <= x && P[y] == P[y + 1]) y++;

		if(y > x) { f(); continue; }

		int g = y;

		y = 2 * g + 1;
		while(y <= x && P[y] == P[y + 1]) y++;
		if(y > x) { f(); continue; }

		if(x - y <= g) { f(); continue; }
		printf("%d %d %d\n", g, y - g, x - y);
	}
	return 0;
}