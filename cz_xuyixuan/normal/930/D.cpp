#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
const int HALF = 200000;
const int INF = 1e9;
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
int n, x[MAXN], y[MAXN];
int Maxp[MAXN], Minp[MAXN];
int Maxs[MAXN], Mins[MAXN];
long long ans;
void chkmax(int &x, int y) {x = max(x, y); }
void chkmin(int &x, int y) {x = min(x, y); }
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(x[i]), read(y[i]);
	
	for (int i = 0; i < MAXN; i++) {
		Maxp[i] = Maxs[i] = -INF;
		Minp[i] = Mins[i] = INF;
	}
	for (int i = 1; i <= n; i++)
		if ((x[i] % 2 == 0) ^ (y[i] % 2 == 0)) {
			chkmax(Maxp[y[i] - x[i] + HALF], x[i] + y[i]);
			chkmax(Maxs[y[i] - x[i] + HALF], x[i] + y[i]);
			chkmin(Minp[y[i] - x[i] + HALF], x[i] + y[i]);
			chkmin(Mins[y[i] - x[i] + HALF], x[i] + y[i]);
		}
	for (int i = 1; i < MAXN; i++) {
		chkmax(Maxp[i], Maxp[i - 1]);
		chkmin(Minp[i], Minp[i - 1]);
	}
	for (int i = MAXN - 2; i >= 0; i--) {
		chkmax(Maxs[i], Maxs[i + 1]);
		chkmin(Mins[i], Mins[i + 1]);
	}
	for (int i = 0; i < MAXN; i++) {
		if (i % 2 == 1) continue;
		int l = max(Minp[i], Mins[i]);
		int r = min(Maxp[i], Maxs[i]);
		if (l < r) ans += (r - l) / 2;
	}
	
	for (int i = 0; i < MAXN; i++) {
		Maxp[i] = Maxs[i] = -INF;
		Minp[i] = Mins[i] = INF;
	}
	for (int i = 1; i <= n; i++)
		if (!((x[i] % 2 == 0) ^ (y[i] % 2 == 0))) {
			chkmax(Maxp[y[i] - x[i] + HALF], x[i] + y[i]);
			chkmax(Maxs[y[i] - x[i] + HALF], x[i] + y[i]);
			chkmin(Minp[y[i] - x[i] + HALF], x[i] + y[i]);
			chkmin(Mins[y[i] - x[i] + HALF], x[i] + y[i]);
		}
	for (int i = 1; i < MAXN; i++) {
		chkmax(Maxp[i], Maxp[i - 1]);
		chkmin(Minp[i], Minp[i - 1]);
	}
	for (int i = MAXN - 2; i >= 0; i--) {
		chkmax(Maxs[i], Maxs[i + 1]);
		chkmin(Mins[i], Mins[i + 1]);
	}
	for (int i = 0; i < MAXN; i++) {
		if (i % 2 == 0) continue;
		int l = max(Minp[i], Mins[i]);
		int r = min(Maxp[i], Maxs[i]);
		if (l < r) ans += (r - l) / 2;
	}
	writeln(ans);
	return 0;
}