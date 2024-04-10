#include<bits/stdc++.h>
using namespace std;
const int MAXN = 300005;
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
int a[MAXN];
char s[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]);
	scanf("%s", s + 1);
	int last = 1;
	for (int i = 1; i <= n; i++)
		if (s[i] != '1') {
			sort(a + last, a + i + 1);
			last = i + 1;
		}
	for (int i = 1; i <= n; i++)
		if (a[i] != i) {
			printf("No\n");
			return 0;
		}
	printf("Yes\n");
	return 0;
}