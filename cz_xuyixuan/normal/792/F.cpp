#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const double eps = 1e-10;
const int P = 1e6;
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
int n; double m;
multiset <pair <int, int>> st;
double getvalue(pair <int, int> a, double pos, pair <int, int> b) {
	return a.second + (pos - a.first) / (b.first - a.first) * (b.second - a.second);
}
bool query(pair <int, int> x) {
	double Min = 1.0 * x.second / x.first;
	auto suf = st.lower_bound(make_pair(Min - eps + 1, 0));
	if (suf == st.end()) return false;
	auto pre = suf; pre--;
	double Mana = getvalue(*pre, Min, *suf);
	return Mana * x.first - eps <= m;
}
bool turn(pair <int, int> a, pair <int, int> b, pair <int, int> c) {
	int xa = c.first - b.first, ya = c.second - b.second;
	int xb = b.first - a.first, yb = b.second - a.second;
	return 1ll * xa * yb - 1ll * xb * ya >= 0;
}
void insert(pair <int, int> x) {
	auto tmp = st.insert(x);
	auto suf = tmp; suf++;
	if (suf != st.end() && (*suf).first == (*tmp).first) {
		st.erase(suf);
		suf = tmp; suf++;
	}
	auto pre = tmp; pre--;
	if ((*pre).first == (*tmp).first) {
		st.erase(tmp);
		return;
	}
	if (suf != st.end() && turn(*pre, *tmp, *suf)) {
		st.erase(tmp);
		return;
	}
	while (suf != st.end()) {
		auto nxt = suf; nxt++;
		if (nxt != st.end() && turn(*tmp, *suf, *nxt)) {
			st.erase(suf);
			suf = tmp; suf++;
		} else break;
	}
	while (pre != st.begin()) {
		auto nxt = pre; nxt--;
		if (turn(*nxt, *pre, *tmp)) {
			st.erase(pre);
			pre = tmp; pre--;
		} else break;
	}
}
int main() {
	read(n), read(m);
	int lastans = 0;
	st.insert(make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		int type, x, y;
		read(type), read(x), read(y);
		x = (x + lastans) % P + 1;
		y = (y + lastans) % P + 1;
		if (type == 1) insert(make_pair(x, y));
		else {
			bool ans = query(make_pair(x, y));
			if (ans) {
				puts("YES");
				lastans = i;
			} else puts("NO");
		}
	}
	return 0;
}