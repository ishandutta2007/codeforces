#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
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
long long cost[MAXN];
int main() {
	int n, m;
	read(n), read(m);
	for (int i = 1; i <= n; i++)
		read(cost[i]);
	for (int i = 2; i <= n; i++)
		if (cost[i - 1] * 2 < cost[i]) cost[i] = cost[i - 1] * 2;
	long long ans = cost[1] * m, now = 0;
	for (int i = n; i >= 1; i--) {
		int tmp = 1 << i - 1;
		int cnt = (m - 1) / tmp + 1;
		ans = min(ans, now + cost[i] * cnt);
		cnt = m / tmp;
		now += cnt * cost[i];
		m -= tmp * cnt; 
	}
	cout << ans << endl;
	return 0;
}