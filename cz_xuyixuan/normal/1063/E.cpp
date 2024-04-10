#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;
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
int n, a[MAXN];
char ans[MAXN][MAXN];
int main() {
	read(n);
	bool all = true; 
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] != i) all = false;
		for (int j = 1; j <= n; j++)
			ans[i][j] = '.';
	}
	if (all) {
		printf("%d\n", n);
		for (int i = 1; i <= n; i++)
			printf("%s\n", ans[i] + 1);
		return 0;
	}
	int token = 1, pos = 0;
	for (int i = 1; i <= n; i++)
		if (a[i] == 1) pos = i;
	for (int i = n; i >= 1; i--) {
		if (token == pos) {
			int dest = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] < j) dest = j;
			if (dest == 0) continue;
			ans[i][dest] = ans[i][a[dest]] = ans[i][pos] = '\\';
			int x = dest, y = a[dest];
			swap(a[x], a[y]), swap(a[pos], a[x]), pos = x;
		} else {
			int dest = 0;
			for (int j = 1; j <= n; j++)
				if (a[j] == pos) dest = j;
			if (dest > pos) ans[i][dest] = ans[i][pos] = '\\';
			else ans[i][dest] = ans[i][pos] = '/';
			swap(a[pos], a[dest]), pos = dest;
		}
	}
	printf("%d\n", n - 1);
	for (int i = 1; i <= n; i++)
		printf("%s\n", ans[i] + 1);
	return 0;
}