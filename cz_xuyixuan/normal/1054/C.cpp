#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int n, a[MAXN], l[MAXN], r[MAXN];
int rnk[MAXN], pos[MAXN];
bool cmp(int x, int y) {
	return l[x] + r[x] < l[y] + r[y];
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(l[i]);
	for (int i = 1; i <= n; i++)
		read(r[i]);
	for (int i = 1; i <= n; i++)
		pos[i] = i;
	sort(pos + 1, pos + n + 1, cmp);
	for (int i = 1; i <= n; i++) {
		int now = pos[i], last = pos[i - 1];
		if (i == 1 || l[now] + r[now] != l[last] + r[last]) rnk[i] = i;
		else rnk[i] = rnk[i - 1];
		a[now] = n - rnk[i] + 1;
	}
	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= i - 1; j++)
			if (a[j] > a[i]) cnt++;
		if (cnt != l[i]) {
			printf("NO\n");
			return 0;
		}
		cnt = 0;
		for (int j = i + 1; j <= n; j++)
			if (a[j] > a[i]) cnt++;
		if (cnt != r[i]) {
			printf("NO\n");
			return 0;
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}