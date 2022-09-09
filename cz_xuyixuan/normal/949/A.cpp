#include<bits/stdc++.h>
using namespace std;
const int MAXN = 200005;
template <typename T> void chkmax(T &x, T y) {x = max(x, y); }
template <typename T> void chkmin(T &x, T y) {x = min(x, y); } 
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
char s[MAXN];
vector <int> a[MAXN];
int main() {
	scanf("%s", s + 1);
	int n = strlen(s + 1);
	int tot = 0, zero = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == '0') a[++zero].push_back(i);
		else {
			if (zero == 0) {
				printf("-1\n");
				return 0;
			}
			a[zero--].push_back(i);
		}
		if (zero > tot) tot = zero;
	}
	if (zero != tot) printf("-1\n");
	else {
		printf("%d\n", tot);
		for (int i = 1; i <= tot; i++) {
			printf("%u", a[i].size());
			for (unsigned j = 0; j < a[i].size(); j++)
				printf(" %d", a[i][j]);
			printf("\n");
		}
	}
	return 0;
}