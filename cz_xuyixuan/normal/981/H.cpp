#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 998244353;
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
namespace NTT {
	const int MAXN = 262144;
	const int P = 998244353;
	const int G = 3;
	int power(int x, int y) {
		if (y == 0) return 1;
		int tmp = power(x, y / 2);
		if (y % 2 == 0) return 1ll * tmp * tmp % P;
		else return 1ll * tmp * tmp % P * x % P;
	}
	int N, Log, home[MAXN];
	void NTTinit() {
		for (int i = 0; i < N; i++) {
			int ans = 0, tmp = i;
			for (int j = 1; j <= Log; j++) {
				ans <<= 1;
				ans += tmp & 1;
				tmp >>= 1;
			}
			home[i] = ans;
		}
	}
	void NTT(int *a, int mode) {
		for (int i = 0; i < N; i++)
			if (home[i] < i) swap(a[i], a[home[i]]);
		for (int len = 2; len <= N; len <<= 1) {
			int delta;
			if (mode == 1) delta = power(G, (P - 1) / len);
			else delta = power(G, P - 1 - (P - 1) / len);
			for (int i = 0; i < N; i += len) {
				int now = 1;
				for (int j = i, k = i + len / 2; k < i + len; j++, k++) {
					int tmp = a[j];
					int tnp = 1ll * a[k] * now % P;
					a[j] = (tmp + tnp) % P;
					a[k] = (tmp - tnp + P) % P;
					now = 1ll * now * delta % P;
				}
			}
		}
		if (mode == -1) {
			int inv = power(N, P - 2);
			for (int i = 0; i < N; i++)
				a[i] = 1ll * a[i] * inv % P;
		}
	}
	vector <int> times(vector <int> a, vector <int> b) {
		N = 1, Log = 0;
		int limit = a.size() + b.size() - 1;
		int sa = a.size(), sb = b.size();
		while (N < limit) {
			N <<= 1;
			Log++;
		}
		static int tmp[MAXN], tnp[MAXN];
		for (int i = 0; i < N; i++) {
			if (i < sa) tmp[i] = a[i];
			else tmp[i] = 0;
			if (i < sb) tnp[i] = b[i];
			else tnp[i] = 0;
		}
		NTTinit();
		NTT(tmp, 1);
		NTT(tnp, 1);
		for (int i = 0; i < N; i++)
			tmp[i] = 1ll * tmp[i] * tnp[i] % P;
		NTT(tmp, -1);
		vector <int> ans;
		ans.resize(limit);
		for (unsigned i = 0; i < ans.size(); i++)
			ans[i] = tmp[i];
		return ans;
	}
}
map <int, int> ans[MAXN];
vector <int> a[MAXN], b[MAXN];
int n, m, size[MAXN], depth[MAXN], sum[MAXN], finalans;
void dfs(int pos, int fa) {
	size[pos] = 1;
	depth[pos] = depth[fa] + 1;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			dfs(a[pos][i], pos);
			size[pos] += size[a[pos][i]];
		}
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
vector <int> work(int from, int l, int r) {
	if (l == r) {
		vector <int> ans;
		ans.push_back(1);
		ans.push_back(b[from][l]);
		return ans;
	}
	int mid = (l + r) / 2;
	return NTT :: times(work(from, l, mid), work(from, mid + 1, r));
}
int fac[MAXN], inv[MAXN], vin[MAXN];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
int getc(int x, int y) {
	if (y > x) return 0;
	else return 1ll * fac[x] * inv[y] % P * inv[x - y] % P;
}
void init(int n) {
	fac[0] = 1;
	for (int i = 1; i <= n; i++)
		fac[i] = 1ll * fac[i - 1] * i % P;
	inv[n] = power(fac[n], P - 2);
	for (int i = n - 1; i >= 0; i--)
		inv[i] = inv[i + 1] * (i + 1ll) % P;
	for (int i = 1; i <= n; i++)
		vin[i] = power(i, P - 2);
}
void getans(int pos, int fa) {
	sum[pos] = 0;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			getans(a[pos][i], pos);
			update(sum[pos], sum[a[pos][i]]);
		}
	int tmpans = 0;
	update(tmpans, 1ll * sum[pos] * sum[pos] % P);
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) {
			update(tmpans, P - 1ll * sum[a[pos][i]] * sum[a[pos][i]] % P);
			update(finalans, 1ll * sum[a[pos][i]] * ans[pos][b[pos][i]] % P);
		} else update(sum[pos], ans[pos][b[pos][i]]);
	update(finalans, 1ll * tmpans * vin[2] % P);
}
int main() {
	init(MAXN - 1);
	read(n), read(m);
	if (n == 1) {
		printf("%d\n", 0);
		return 0;
	}
	for (int i = 1; i <= n - 1; i++) {
		int x, y; read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) {
		b[i].resize(a[i].size());
		for (unsigned j = 0; j < a[i].size(); j++) {
			int dest = a[i][j];
			if (depth[dest] > depth[i]) b[i][j] = size[dest];
			else b[i][j] = n - size[i];
		}
		vector <int> now = work(i, 0, b[i].size() - 1);
		for (unsigned j = 0; j < a[i].size(); j++) {
			int x = a[i][j], y = b[i][j];
			if (ans[i].count(y)) continue;
			if (m == 1) {
				ans[i][y] = 1;
				continue;
			}
			vector <int> tmp = now;
			vector <int> res (now.size() - 1);
			for (unsigned k = now.size() - 1; k >= 1; k--) {
				int tes = 1ll * tmp[k] * vin[y] % P;
				res[k - 1] = tes;
				update(tmp[k], P - 1ll * tes * size[x] % P);
				update(tmp[k - 1], P - tes);
			}
			int val = 0;
			for (unsigned k = 0; k < res.size(); k++)
				update(val, 1ll * res[k] * getc(m, k) % P * fac[k] % P);
			ans[i][y] = val;
		}
	}
	getans(1, 0);
	writeln(finalans);
	return 0;
}