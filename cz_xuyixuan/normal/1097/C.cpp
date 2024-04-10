#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
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
int cnt[MAXN], cmt[MAXN];
int main() {
	int n; read(n);
	for (int i = 1; i <= n; i++) {
		string x; cin >> x;
		int sum = 0, Min = 0;
		for (auto y : x)
			if (y == '(') sum++;
			else sum--, chkmin(Min, sum);
		if (sum <= 0) {
			if (Min == sum) cnt[-sum]++;
		} else {
			if (Min == 0) cmt[sum]++;
		}
	}
	int ans = cnt[0] / 2;
	for (int i = 1; i <= 5e5; i++)
		ans += min(cnt[i], cmt[i]);
	writeln(ans);
	return 0;
}