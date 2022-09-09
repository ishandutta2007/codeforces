#include<bits/stdc++.h>
using namespace std;
const int MAXN = 531441;
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
int w, n, m, bit[15], zero[MAXN], one[MAXN];
int bnt[MAXN], cnt[MAXN], mask[MAXN], two[MAXN];
int main() {
	read(w), read(n), read(m);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		bnt[x]++;
	}
	int goal = (1 << w) - 1;
	bit[0] = 1;
	for (int i = 1; i <= w; i++)
		bit[i] = bit[i - 1] * 3;
	for (int i = 0; i <= goal; i++) {
		for (int j = 0; j <= w - 1; j++) {
			mask[i] += bit[j] * ((i & (1 << j)) != 0);
			if (i & (1 << j)) two[i] += bit[j] * 2, one[i] += 1 << j;
			else zero[i] += 1 << j;
		}
	}
	for (int i = 0; i <= goal; i++) {
		if (bnt[i] == 0) continue;
		for (int j = 0; j <= goal; j++)
			cnt[mask[i & j] + two[goal ^ j]] += bnt[i];
	}
	for (int i = 1; i <= m; i++) {
		char str[15];
		scanf("\n%s", str);
		reverse(str, str + w);
		ll ans = 0;
		int opt[2][3] = {{0, 0, 0}, {0, 0, 0}};
		for (int j = 0; j <= w - 1; j++) {
			if (str[j] == 'A') {
				opt[0][2] += 1 << j;
				opt[1][0] += 1 << j;
			}
			if (str[j] == 'O') opt[0][0] += 1 << j;
			if (str[j] == 'X') {
				opt[0][0] += 1 << j;
				opt[1][1] += 1 << j;
			}
			if (str[j] == 'a') opt[1][1] += 1 << j;
			if (str[j] == 'o') {
				opt[0][1] += 1 << j;
				opt[1][2] += 1 << j;
			}
			if (str[j] == 'x') {
				opt[0][1] += 1 << j;
				opt[1][0] += 1 << j;
			}
		}
		for (int s = 0; s <= goal; s++) {
			if (bnt[s] == 0) continue;
			int tmp[3];
			tmp[0] = (zero[s] & opt[0][0]) + (one[s] & opt[1][0]);
			tmp[1] = (zero[s] & opt[0][1]) + (one[s] & opt[1][1]);
			tmp[2] = (zero[s] & opt[0][2]) + (one[s] & opt[1][2]);
			if (tmp[0] + tmp[1] + tmp[2] == goal) ans += 1ll * cnt[mask[tmp[1]] + two[tmp[2]]] * bnt[s];
		}
		writeln(ans);
	}
	return 0;
}