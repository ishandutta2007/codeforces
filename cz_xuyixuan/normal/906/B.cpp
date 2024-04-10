#include<bits/stdc++.h>
using namespace std;
#define MAXN	200005
template <typename T> void read(T &x) {
	x = 0; int f = 1;
	char c = getchar();
	for (; !isdigit(c); c = getchar()) if (c == '-') f = -f;
	for (; isdigit(c); c = getchar()) x = x * 10 + c - '0';
	x *= f;
}
template <typename T> void write(T x) {
	if (x < 0) x = -x, putchar('-');
	if (x > 9) write(x / 10);
	putchar(x % 10 + '0');
}
template <typename T> void writeln(T x) {
	write(x);
	puts("");
}
int n, m, a[MAXN];
void modify(int x, int y, int d) {
	int pos = (x - 1) * m + y;
	a[pos] = d;
}
int query(int x, int y) {
	int pos = (x - 1) * m + y;
	return a[pos];
}
void print() {
	printf("YES\n");
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++)
			printf("%d ", query(i, j));
		printf("\n");
	}
}
int main() {
	scanf("%d%d", &n, &m);
	if (m >= 5) {
		for (int i = 1; i <= n; i++) {
			int now = 0;
			for (int j = 1; j <= m; j++) {
				if (j % 2 == i % 2) {
					now++;
					modify(i, j, (i - 1) * m + now);
				}
			}
			for (int j = 1; j <= m; j++) {
				if (j % 2 != i % 2) {
					now++;
					modify(i, j, (i - 1) * m + now);
				}
			}
		}
		print();
		return 0;
	}
	if (n >= 5) {
		for (int j = 1; j <= m; j++) {
			int now = 0;
			for (int i = 1; i <= n; i++) {
				if (j % 2 == i % 2) {
					now++;
					modify(i, j, (now - 1) * m + j);
				}
			}
			for (int i = 1; i <= n; i++) {
				if (j % 2 != i % 2) {
					now++;
					modify(i, j, (now - 1) * m + j);
				}
			}
		}
		print();
		return 0;
	}
	if (n == 1) {
		if (m == 4) {
			printf("YES\n");
			printf("2 4 1 3\n");
		} else if (m == 1) {
			printf("YES\n");
			printf("1\n");
		} else printf("NO\n");
	}
	if (n == 2) {
		if (m == 4) {
			printf("YES\n");
			printf("1 3 5 2\n");
			printf("8 6 4 7\n");
		} else printf("NO\n");
	}
	if (n == 3) {
		if (m == 4) {
			printf("YES\n");
			printf("1 3 5 2\n");
			printf("4 6 12 9\n");
			printf("11 8 10 7\n");
		} else if (m == 3) {
			printf("YES\n");
			printf("1 3 4\n");
			printf("5 7 6\n");
			printf("9 2 8\n");
		} else printf("NO\n");
	}
	if (n == 4) {
		if (m == 1) {
			printf("YES\n");
			printf("2\n");
			printf("4\n");
			printf("1\n");
			printf("3\n");
		}
		if (m == 2) {
			printf("YES\n");
			printf("1 4\n");
			printf("5 8\n");
			printf("2 3\n");
			printf("6 7\n");
		}
		if (m == 3) {
			printf("YES\n");
			printf("1 3 4\n");
			printf("5 7 2\n");
			printf("11 6 8\n");
			printf("9 10 12\n");
		}
		if (m == 4) {
			printf("YES\n");
			printf("10 2 12 4\n");
			printf("1 9 3 11\n");
			printf("13 6 15 8\n");
			printf("5 14 7 16\n");
		}
	}
	return 0;
}