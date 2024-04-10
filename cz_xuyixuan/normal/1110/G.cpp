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
int n; char s[MAXN];
vector <int> a[MAXN];
void solve() {
	if (n <= 2) {
		puts("Draw");
		return;
	}
	if (n == 3) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			cnt += s[i] == 'W';
		if (cnt >= 2) puts("White");
		else puts("Draw");
		return;
	}
	if (n == 4) {
		int cnt = 0; bool flg = false;
		for (int i = 1; i <= n; i++) {
			cnt += s[i] == 'W';
			if (a[i].size() == 3) flg = true;
		}	
		if (flg) {
			if (cnt >= 1) puts("White");
			else puts("Draw");
		} else {
			for (int i = 1; i <= n; i++)
				if (s[i] == 'W' && a[i].size() >= 2) {
					puts("White");
					return;
				}
			puts("Draw");
		}
		return;
	}
	int cnt = 0, tot = 0, spe = 0;
	for (int i = 1; i <= n; i++) {
		if (s[i] == 'W') {
			tot++;
			if (a[i].size() >= 2 || a[a[i][0]].size() >= 3) {
				puts("White");
				return;
			}
		}
		if (a[i].size() >= 2) cnt++;
		if (a[i].size() >= 4) {
			puts("White");
			return;
		}
		if (a[i].size() >= 3) {
			int cmt = 0; spe++;
			for (auto x : a[i])
				if (a[x].size() >= 2) cmt++;
			if (cmt >= 2) {
				puts("White");
				return;
			}
		}
	}
	assert(cnt >= 2 && tot <= 2);
	if (tot && spe && cnt % 2 == 1) {
		puts("White");
		return;
	}
	if (tot >= 2 && cnt % 2 == 1) {
		puts("White");
		return;
	}
	if (spe >= 2 && cnt % 2 == 1) {
		puts("White");
		return;
	}
	puts("Draw");
}
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i <= n - 1; i++) {
			int x, y; read(x), read(y);
			a[x].push_back(y);
			a[y].push_back(x);
		}
		scanf("\n%s", s + 1);
		solve();
	}
	return 0;
}