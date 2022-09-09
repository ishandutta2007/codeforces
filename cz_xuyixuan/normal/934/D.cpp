#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
long long p;
int k, d, ans[MAXN];
int main() {
	read(p), read(k);
	bool postive = true;
	while (p) {
		int x = p % k; p /= k;
		if (postive) ans[++d] = x;
		else {
			if (x == 0) ans[++d] = x;
			else ans[++d] = k - x, p++;
		}
		postive ^= true;
	}
	writeln(d);
	for (int i = 1; i <= d; i++)
		printf("%d ", ans[i]);
	return 0;
}