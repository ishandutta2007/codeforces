#include<bits/stdc++.h>
using namespace std;
const int MAXN = 605;
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
int n, fa[MAXN], depth[MAXN];
bool vis[MAXN], col[MAXN];
vector <int> a[MAXN], part[2];
map <vector <int>, int> mem;
int query(vector <int> a) {
	if (a.size() <= 1) return 0;
	sort(a.begin(), a.end());
	if (mem.count(a)) return mem[a];
	printf("? %d", a.size());
	cout << endl;
	for (auto i : a) printf("%d ", i);
	cout << endl;
	int ans; read(ans);
	return mem[a] = ans;
}
int query(vector <int> a, vector <int> b) {
	vector <int> tmp;
	for (auto i : a) tmp.push_back(i);
	for (auto i : b) tmp.push_back(i);
	return query(tmp) - query(a) - query(b);
}
void dfs(int pos) {
	vis[pos] = true;
	part[col[pos]].push_back(pos);
	for (auto dest : a[pos])
		if (!vis[dest]) {
			fa[dest] = pos;
			depth[dest] = depth[pos] + 1;
			col[dest] = !col[pos];
			dfs(dest);
		}
}
void answer(int x, int y) {
	vector <int> a, b;
	if (depth[x] < depth[y]) swap(x, y);
	while (depth[x] > depth[y]) {
		a.push_back(x);
		x = fa[x];
	}
	while (x != y) {
		a.push_back(x);
		x = fa[x];
		b.push_back(y);
		y = fa[y];
	}
	a.push_back(x);
	while (!b.empty()) {
		a.push_back(b.back());
		b.pop_back();
	}
	printf("N %d", a.size());
	cout << endl;
	for (auto i : a) printf("%d ", i);
	cout << endl;
	exit(0);
}
void work(vector <int> a) {
	if (a.size() == 2) answer(a[0], a[1]);
	while (true) {
		random_shuffle(a.begin(), a.end());
		vector <int> b, c;
		for (unsigned i = 0; i < a.size(); i++)
			if (i & 1) b.push_back(a[i]);
			else c.push_back(a[i]);
		if (query(b)) work(b);
		if (query(c)) work(c);
	}
}
int main() {
	read(n);
	vector <int> now, lft;
	now.push_back(1);
	for (int i = 2; i <= n; i++)
		lft.push_back(i);
	while (lft.size() != 0) {
		vector <int> rem = lft, pa, pb;
		while (rem.size() > 1) {
			unsigned mid = rem.size() / 2;
			pa.clear();
			pb.clear();
			for (unsigned j = 0; j < rem.size(); j++)
				if (j < mid) pa.push_back(rem[j]);
				else pb.push_back(rem[j]);
			if (query(now, pa)) rem = pa;
			else rem = pb;
		}
		vector <int> bak = rem;
		int pos = rem.back();
		rem = now;
		while (rem.size() > 1) {
			unsigned mid = rem.size() / 2;
			pa.clear();
			pb.clear();
			for (unsigned j = 0; j < rem.size(); j++)
				if (j < mid) pa.push_back(rem[j]);
				else pb.push_back(rem[j]);
			if (query(pa, bak)) rem = pa;
			else rem = pb;
		}
		int dest = rem.back();
		a[pos].push_back(dest);
		a[dest].push_back(pos);
		now.push_back(pos);
		for (unsigned j = 0; j < lft.size(); j++)
			if (lft[j] == pos) {
				lft.erase(lft.begin() + j);
				break;
			}
	}
	dfs(1);
	if (query(part[0]) + query(part[1]) == 0) {
		printf("Y %d", part[0].size());
		cout << endl;
		for (auto i : part[0]) printf("%d ", i);
		cout << endl;
		return 0;
	}
	if (query(part[0])) work(part[0]);
	else work(part[1]);
	return 0;
}