#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>

const int as[4][2] = {
	{1, 1}, {1, 2}, {1, 3}, {1, 4}
} ;
const int bs[4][2] = {
	{3, 1}, {3, 3}, {4, 1}, {4, 3}
} ;
int ta, tb;
int main() {
	while (true) {
		char t = getchar();
		if (t < 48) break;
		int now = 0;
		if (t & 1) {
			now = tb++ % 4;
		printf("%d %d\n", bs[now][0], bs[now][1]);
		} else {
			now = ta++ % 4;
		printf("%d %d\n", as[now][0], as[now][1]);
		}
	}
	return 0;
}