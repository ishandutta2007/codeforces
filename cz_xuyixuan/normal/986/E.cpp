#include<bits/stdc++.h>
using namespace std;
const int MAXN = 100005;
const int MAXLOG = 30;
const int MAXP = 1e6 + 5;
const int MAXV = 1e7 + 5;
const int P = 1e9 + 7;
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
struct querys {int home, val; bool type; };
vector <int> a[MAXN];
vector <querys> q[MAXN];
int m, ans[MAXN];
int tot, prime[MAXP], f[MAXV];
int val[MAXN], cnt[MAXP][MAXLOG];
int n, depth[MAXN], father[MAXN][MAXLOG];
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void modify(int val, int d) {
	for (int i = 1; prime[i] * prime[i] <= val; i++)
		if (val % prime[i] == 0) {
			int p = 0;
			while (val % prime[i] == 0) {
				val /= prime[i];
				p++;
			}
			cnt[i][p] += d;
		}
	if (val != 1) {
		int pos = lower_bound(prime + 1, prime + tot + 1, val) - prime;
		cnt[pos][1] += d;
	}
}
int query(int val) {
	int ans = 1;
	for (int i = 1; prime[i] * prime[i] <= val; i++)
		if (val % prime[i] == 0) {
			int p = 0;
			while (val % prime[i] == 0) {
				val /= prime[i];
				p++;
			}
			int tans = 0;
			for (int j = 1; j <= p; j++)
				tans += cnt[i][j] * j;
			for (int j = p + 1; j < MAXLOG; j++)
				tans += cnt[i][j] * p;
			ans = 1ll * ans * power(prime[i], tans) % P;
		}
	if (val != 1) {
		int pos = lower_bound(prime + 1, prime + tot + 1, val) - prime, tans = 0;
		for (int j = 1; j < MAXLOG; j++)
			tans += cnt[pos][j];
		ans = 1ll * ans * power(prime[pos], tans) % P;
	}
	return ans;
}
void work(int pos, int fa) {
	modify(val[pos], 1);
	for (unsigned i = 0; i < q[pos].size(); i++)
		if (q[pos][i].type) ans[q[pos][i].home] = 1ll * ans[q[pos][i].home] * query(q[pos][i].val) % P;
		else ans[q[pos][i].home] = 1ll * ans[q[pos][i].home] * power(query(q[pos][i].val), P - 2) % P;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) work(a[pos][i], pos);
	modify(val[pos], -1);
}
void dfs(int pos, int fa) {
	father[pos][0] = fa;
	depth[pos] = depth[fa] + 1;
	for (int i = 1; i < MAXLOG; i++)
		father[pos][i] = father[father[pos][i - 1]][i - 1];
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (a[pos][i] != fa) dfs(a[pos][i], pos);
}
int lca(int x, int y) {
	if (depth[x] < depth[y]) swap(x, y);
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (depth[father[x][i]] >= depth[y]) x = father[x][i];
	if (x == y) return x;
	for (int i = MAXLOG - 1; i >= 0; i--)
		if (father[x][i] != father[y][i]) {
			x = father[x][i];
			y = father[y][i];
		}
	return father[x][0];
}
int main() {
	for (int i = 2; i < MAXV; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp >= MAXV) break;
			f[tmp] = prime[j];
		}
	}
	read(n);
	for (int i = 2; i <= n; i++) {
		int x, y;
		read(x), read(y);
		a[x].push_back(y);
		a[y].push_back(x);
	}
	for (int i = 1; i <= n; i++)
		read(val[i]);
	dfs(1, 0);
	read(m);
	for (int i = 1; i <= m; i++) {
		ans[i] = 1;
		int x, y, z;
		read(x), read(y), read(z);
		int Lca = lca(x, y);
		q[x].push_back((querys) {i, z, true});
		q[y].push_back((querys) {i, z, true});
		q[Lca].push_back((querys) {i, z, false});
		q[father[Lca][0]].push_back((querys) {i, z, false});
	}
	work(1, 0);
	for (int i = 1; i <= m; i++)
		writeln(ans[i]);
	return 0;
}