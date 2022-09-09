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
int n, ans[MAXN]; ll s;
bool solve(int k) {
	static ll cnt[MAXN];
	ll now = 1; int depth = 1; cnt[depth] = 1;
	while (now < n) {
		cnt[depth + 1] = cnt[depth] * k, depth++;
		now += cnt[depth];
	}
	cnt[depth] -= now - n;
	ll cursum = 0;
	for (int i = 1; i <= depth; i++)
		cursum += 1ll * i * cnt[i];
	if (cursum > s) return false;
	puts("Yes");
	int tepth = depth;
	while (cursum < s) {
		while (cnt[tepth] == 1) tepth--;
		if (cursum + depth + 1 - tepth <= s) cnt[++depth] = 1, cnt[tepth]--, cursum += depth - tepth;
		else cnt[tepth]--, cnt[s - cursum + tepth]++, cursum = s;
	}
	for (int i = 1, start = 1; i <= depth - 1; start += cnt[i], i++) {
		int pos = start, lft = k;
		for (int j = start + cnt[i]; j < start + cnt[i] + cnt[i + 1]; j++) {
			ans[j] = pos;
			if (--lft == 0) {
				pos++;
				lft = k;
			}
		}
	}
	for (int i = 2; i <= n; i++)
		printf("%d ", ans[i]);
	return true;
}
int main() {
	read(n), read(s);
	if (s > 1ll * n * (n + 1) / 2) {
		puts("No");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		if (solve(i)) return 0;
	puts("No");
	return 0;
}