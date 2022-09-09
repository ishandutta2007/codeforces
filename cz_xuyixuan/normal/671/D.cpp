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
struct Tree {
	set <pair <int, ll>> st; ll tag;
	int size() {
		return st.size();
	}
	void add(ll x) {
		tag += x;
	}
	ll query() {
		assert(size() != 0);
		auto x = st.end(); x--;
		return (*x).second + tag;
	}
	void del(int depth) {
		if (size() != 0) {
			auto x = st.end(); x--;
			if ((*x).first == depth) st.erase(x);
		}
	}
	void ins(pair <int, ll> x) {
		x.second -= tag;
		auto tmp = st.insert(x).first;
		if (tmp != st.begin()) {
			auto pre = tmp; pre--;
			if ((*pre).second <= (*tmp).second) {
				st.erase(tmp);
				return;
			}
		}
		auto suf = tmp; suf++;
		while (suf != st.end()) {
			if ((*tmp).second <= (*suf).second) {
				st.erase(suf);
			} else return;
			suf = tmp; suf++;
		}
	}
	void join(Tree &t) {
		for (auto x : t.st) {
			x.second += t.tag;
			ins(x);
		}
	}
};
int n, m, depth[MAXN]; ll cost[MAXN];
Tree t[MAXN]; vector <int> a[MAXN];
vector <pair <int, int>> b[MAXN];
void work(int pos, int fa) {
	depth[pos] = depth[fa] + 1;
	ll sum = 0;
	for (auto x : a[pos])
		if (x != fa) {
			work(x, pos);
			sum += cost[x];
		}
	if (pos == 1) {
		writeln(sum);
		exit(0);
	}
	for (auto x : b[pos]) t[pos].ins(make_pair(depth[x.first], sum + x.second));
	for (auto x : a[pos])
		if (x != fa) {
			t[x].add(sum - cost[x]);
			if (t[pos].size() < t[x].size()) swap(t[pos], t[x]);
			t[pos].join(t[x]);
		}
	if (fa != 0) {
		t[pos].del(depth[pos]);
		if (t[pos].size() == 0) {
			puts("-1");
			exit(0);
		}
	}
	cost[pos] = t[pos].query();
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= m; i++) {
		int x, y, z; read(x), read(y), read(z);
		if (x != y) b[x].emplace_back(y, z);
	}
	work(1, 0);
	return 0;
}