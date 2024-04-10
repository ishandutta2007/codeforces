#include<bits/stdc++.h>
using namespace std;
const int MAXN = 4096;
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
int k, n, p[MAXN], q[MAXN], t[MAXN], a[MAXN], home[MAXN];
void fix(int i, int j) {
	int k = home[t[i] ^ q[i]];
	if (k == i) return;
	if (k == j) {
		swap(home[p[i]], home[p[j]]);
		swap(p[i], p[j]);
		return; 
	}
	swap(home[p[i]], home[p[k]]);
	swap(p[i], p[k]), swap(q[j], q[k]);
	fix(k, j);
}
int main() {
	read(k), n = 1 << k;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		read(a[i]);
		sum ^= a[i];
		p[i] = q[i] = home[i] = i;
	}
	if (sum != 0) {
		puts("Fou");
		return 0;
	}
	for (int i = 0; i < n - 1; i++)
		if (a[i] != t[i]) {
			int delta = t[i] ^ a[i];
			t[i] ^= delta, t[i + 1] ^= delta;
			fix(i, i + 1);
		}
	puts("Shi");
	for (int i = 0; i < n; i++)
		printf("%d ", p[i]);
	printf("\n");
	for (int i = 0; i < n; i++)
		printf("%d ", q[i]);
	printf("\n");
	return 0;
}