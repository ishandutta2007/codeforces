#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int INF = 2e9;
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
ll ans;
int n, s[MAXN];
vector <int> a[MAXN];
void work(int pos, int last) {
	if (s[pos] != -1) {
		if (s[pos] < last) assert(false);
		ans += s[pos] - last;
		last = s[pos];
	} else {
		int Min = INF;
		for (auto x : a[pos])
			chkmin(Min, s[x]);
		if (Min < last) {
			puts("-1");
			exit(0);
		} else if (Min == INF) Min = last;
		ans += Min - last;
		last = Min;
	}
	for (auto x : a[pos])
		work(x, last);
}
int main() {
	read(n);
	for (int i = 2; i <= n; i++) {
		int x; read(x);
		a[x].push_back(i);
	}
	for (int i = 1; i <= n; i++)
		read(s[i]);
	work(1, 0);
	writeln(ans);
	return 0;
}