#include<bits/stdc++.h>
using namespace std;
const int MAXN = 400005;
const int P = 1e9 + 7;
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
bool type[MAXN]; int x[MAXN];
map <int, bool> black, white, exist;
priority_queue <int> hb, hw;
int main() {
	int n; read(n);
	int last = 0;
	for (int i = 1; i <= n; i++) {
		char opt[15];
		scanf("\n%s%d", opt + 1, &x[i]);
		type[i] = opt[2] == 'D';
		if (!type[i]) last = i, exist[x[i]] = true;
	}
	for (int i = 1; i <= n; i++)
		if (type[i]) {
			hb.push(-x[i]);
			hw.push(x[i]);
		} else {
			while (!hb.empty() && hb.top() >= -x[i]) {
				if (hb.top() != -x[i]) black[-hb.top()] = true;
				hb.pop();
			}
			while (!hw.empty() && hw.top() >= x[i]) {
				if (hw.top() != x[i]) white[hw.top()] = true;
				hw.pop();
			}
		}
	int ans = 1, Max = 0, Min = 1e9;
	for (int i = 1; i <= last; i++)
		if (type[i]) {
			int tmp = 0;
			tmp += !black[x[i]];
			if (black[x[i]] && !exist[x[i]]) chkmax(Max, x[i]);
			tmp += !white[x[i]];
			if (white[x[i]] && !exist[x[i]]) chkmin(Min, x[i]);
			ans = ans * tmp % P;
		}
	int cnt = 1;
	for (int i = last + 1; i <= n; i++)
		if (x[i] >= Max && x[i] <= Min) cnt++;
	writeln(1ll * ans * cnt % P);
	return 0;
}