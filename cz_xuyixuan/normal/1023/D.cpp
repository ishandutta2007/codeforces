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
int n, q, a[MAXN], f[MAXN];
vector <int> b[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void merge(int x, int y) {
	f[F(x)] = F(y);
}
int main() {
	read(n), read(q);
	bool big = false, zero = false;
	for (int i = 1; i <= n; i++) {
		read(a[i]);
		if (a[i] == q) big = true;
		if (a[i] == 0) zero = true;
	}
	if (!big && !zero) {
		printf("NO\n");
		return 0;
	}
	if (!big) {
		for (int i = 1; i <= n; i++)
			if (a[i] == 0) {
				a[i] = q;
				break;
			}
	}
	for (int i = 1; i <= n; i++) {
		if (a[i] != 0) continue;
		int pos = i;
		while (pos <= n && a[pos] == 0) pos++;
		int val = max(a[i - 1], a[pos]);
		for (int j = i; j < pos; j++)
			a[j] = val;
	}
	for (int i = 1; i <= n; i++)
		b[a[i]].push_back(i);
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = q; i >= 1; i--) {
		for (unsigned j = 0; j < b[i].size(); j++) {
			int tmp = b[i][j];
			if (a[tmp - 1] >= i) merge(tmp - 1, tmp);
			if (a[tmp + 1] >= i) merge(tmp + 1, tmp);
		}
		if (b[i].size()) {
			int root = F(b[i][0]);
			for (unsigned j = 1; j < b[i].size(); j++) {
				int tmp = b[i][j];
				if (root != F(tmp)) {
					printf("NO\n");
					return 0;
				}
			}
		}
	}
	printf("YES\n");
	for (int i = 1; i <= n; i++)
		printf("%d ", a[i]);
	return 0;
}