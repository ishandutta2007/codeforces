#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
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
char opt[MAXN];
int n, m, x[MAXN], y[MAXN]; ll ans[MAXN];
vector <pair <int, int>> mns[MAXN];

vector <int> a[MAXN]; int tag[MAXN];
pair <int, int> last[MAXN]; int f[MAXN];
ll all[MAXN], self[MAXN];

int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int queryTimer(int x) {
	int y = find(x);
	if (tag[y] > last[x].first) return tag[y];
	else return last[x].second;
}
ll querySum(int x) {
	int y = find(x);
	return all[y] + self[x];
}
int main() {
	read(n), read(m);
	for (int i = 1; i <= m; i++) {
		scanf("\n%c", &opt[i]);
		if (opt[i] == 'U' || opt[i] == 'M') read(x[i]), read(y[i]);
		else read(x[i]);
	}
	for (int i = 1; i <= n; i++) {
		f[i] = i, tag[i] = 0;
		last[i] = make_pair(0, 0);
		a[i].clear(), a[i].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		if (opt[i] == 'Q') mns[queryTimer(x[i])].emplace_back(x[i], i);
		if (opt[i] == 'Z') tag[find(x[i])] = i;
		if (opt[i] == 'M') {
			int tx = find(x[i]), ty = find(y[i]);
			if (a[tx].size() > a[ty].size()) swap(tx, ty);
			for (auto x : a[tx]) {
				a[ty].push_back(x);
				last[x] = make_pair(i, queryTimer(x));
			}
			f[tx] = ty;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		f[i] = i, all[i] = self[i] = 0;
		a[i].clear(), a[i].push_back(i);
	}
	for (int i = 1; i <= m; i++) {
		for (auto x : mns[i]) ans[x.second] -= querySum(x.first);
		if (opt[i] == 'Q') ans[i] += querySum(x[i]);
		if (opt[i] == 'A') all[find(x[i])] += a[find(x[i])].size();
		if (opt[i] == 'U') {
			int tx = find(x[i]), ty = find(y[i]);
			if (a[tx].size() > a[ty].size()) swap(tx, ty);
			for (auto x : a[tx]) {
				a[ty].push_back(x);
				self[x] = querySum(x) - all[ty];
			}
			f[tx] = ty;
		}
	}
	
	for (int i = 1; i <= m; i++)
		if (opt[i] == 'Q') writeln(ans[i]);
	return 0;
}