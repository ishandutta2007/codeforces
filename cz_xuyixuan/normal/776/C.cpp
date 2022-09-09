#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
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
long long ans, k, s[MAXN];
long long calc(long long x) {
	static map <long long, int> mp;
	long long ans = 0; mp.clear();
	for (int i = 1; i <= n; i++) {
		mp[s[i - 1]]++;
		ans += mp[s[i] - x];
	}
	return ans;
}
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]), s[i] = s[i - 1] + a[i];
	long long now = 1;
	while (abs(now) <= 1e15) {
		ans += calc(now);
		now = now * k;
		if (now == 1) break;
	}
	writeln(ans);
	return 0;
}