#include <bits/stdc++.h>

using namespace std;

int query(int x) {
	printf("? %d\n", x); fflush(stdout);
	int ret; scanf("%d", &ret);
	return ret;
}

int rd(int s, int e) {
	int a = rand() & 32767;
	int b = rand() & 32767;
	return ((a << 15) | b) % (e - s + 1) + s;
}

int main() {
	srand((int)time(NULL));
	int N, K; scanf("%d%d", &N, &K);

	int pos, t;

	while(1) {
		pos = rd(1, N);
		t = query(pos);
		if(t != K) break;
	}

	int b = 1;
	while(1) {
		b <<= 1;
		if(b > (N - 1) / 2) { b >>= 1; break; }
	}

	if(t < K) {
		while(b >= 1) {
			int nxt = pos + b;
			if(nxt > N) nxt -= N;
			t = query(nxt);
			if(t < K) pos = nxt;
			b >>= 1;
		}
		pos++; if(pos > N) pos -= N;
	}
	else {
		while(b >= 1) {
			int nxt = pos - b;
			if(nxt <= 0) nxt += N;
			t = query(nxt);
			if(t > K) pos = nxt;
			b >>= 1;
		}
		pos--; if(pos <= 0) pos += N;
	}

	printf("! %d\n", pos);
	fflush(stdout);

	return 0;
}