#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int MAXN = 500010;
int len, c[2], fail[MAXN], tl;
char buf[MAXN], B[MAXN];
int main() {
	scanf("%s", buf + 1); len = strlen(buf + 1);
	for (int i = 1; i <= len; ++i)
		++c[buf[i] & 1];
	scanf("%s", B + 1); tl = strlen(B + 1);
	for (int i = 1; i <= tl; ++i) {
		int now = fail[i - 1];
		while (now && B[now + 1] != B[i]) now = fail[now];
		fail[i] = B[now + 1] == B[i] && now + 1 != i ? now + 1 : 0;
	}
	int now = 0;
	for (int i = 1; i <= len; ++i) {
		if (now == tl) now = fail[now];
		++now;
		if (!c[B[now] & 1]) {
			while (c[0] --> 0) putchar(48);
			while (c[1] --> 0) putchar(49);
			putchar(10);
			return 0;
		}
		putchar(B[now]); --c[B[now] & 1];
	}
	putchar(10);
	return 0;
}