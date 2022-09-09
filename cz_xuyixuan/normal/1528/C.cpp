#include<bits/stdc++.h>
using namespace std;
const int MAXN = 3e5 + 5;
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
vector <int> a[MAXN], b[MAXN];
int n, ans, Max, timer, dfn[MAXN], low[MAXN];
set <pair <int, int>> st;
void dfs(int pos) {
	dfn[pos] = ++timer;
	for (auto x : b[pos])
		dfs(x);
	low[pos] = timer;
}
bool check(int fa, int pos) {
	return dfn[pos] >= dfn[fa] && dfn[pos] <= low[fa];
}
void ins(int pos) {
	auto tmp = st.insert(make_pair(dfn[pos], pos)).first;
	auto pre = tmp, suf = tmp; suf++;
	if (tmp != st.begin()) {
		pre--;
		ans += !check((*pre).second, (*tmp).second);
		if (suf != st.end()) {
			ans -= !check((*pre).second, (*suf).second);
			ans += !check((*tmp).second, (*suf).second);
		}
	} else {
		if (suf != st.end()) ans += !check((*tmp).second, (*suf).second);
		else ans += 1;
	}
}
void del(int pos) {
	auto tmp = st.lower_bound(make_pair(dfn[pos], pos));
	auto pre = tmp, suf = tmp; suf++;
	if (tmp != st.begin()) {
		pre--;
		ans -= !check((*pre).second, (*tmp).second);
		if (suf != st.end()) {
			ans += !check((*pre).second, (*suf).second);
			ans -= !check((*tmp).second, (*suf).second);
		}
	} else {
		if (suf != st.end()) ans -= !check((*tmp).second, (*suf).second);
		else ans -= 1;
	}
	st.erase(tmp);
}
void work(int pos) {
	ins(pos);
	chkmax(Max, ans);
	for (auto x : a[pos])
		work(x);
	del(pos);
}
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) {
			a[i].clear();
			b[i].clear();
		}
		for (int i = 2; i <= n; i++) {
			int x; read(x);
			a[x].push_back(i);
		}
		for (int i = 2; i <= n; i++) {
			int x; read(x);
			b[x].push_back(i);
		}
		timer = Max = ans = 0;
		dfs(1); st.clear();
		work(1);
		printf("%d\n", Max);
	}
	return 0;
}