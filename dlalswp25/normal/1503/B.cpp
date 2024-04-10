#include <bits/stdc++.h>

using namespace std;

int ans[105][105];
int N;
int bx = 1;
int by = 1;
int wx = 1;
int wy = 2;
int bc, wc;

void black(int c) {
	printf("%d %d %d\n", c, bx, by);
	fflush(stdout);
	ans[bx][by] = c;
	bc++;
	by += 2;
	if(by > N) {
		bx++;
		if(bx & 1) by = 1;
		else by = 2;
	}
}

void white(int c) {
	printf("%d %d %d\n", c, wx, wy);
	fflush(stdout);
	ans[wx][wy] = c;
	wc++;
	wy += 2;
	if(wy > N) {
		wx++;
		if(wx & 1) wy = 2;
		else wy = 1;
	}
}

int main() {
	scanf("%d", &N);
	int b = (N * N + 1) / 2;
	int w = N * N - b;

	for(int i = 1; i <= N * N; i++) {
		int a; scanf("%d", &a);
		if(a == 1) {
			if(wc == w) black(3);
			else white(2);
		}
		else if(a == 2) {
			if(bc == b) white(3);
			else black(1);
		}
		else {
			if(wc == w) black(1);
			else white(2);
		}
	}

	return 0;
}