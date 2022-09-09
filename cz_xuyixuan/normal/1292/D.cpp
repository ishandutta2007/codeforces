#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
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
int tot, prime[MAXN], f[MAXN], home[MAXN];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) {
			prime[++tot] = f[i] = i;
			home[i] = tot;
		}
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
}
int m; vector <int> num[MAXN];
int dist(vector <int> a, vector <int> b) {
	int ans = 0;
	for (int i = 1; i <= tot; i++)
		ans += abs(a[i] - b[i]);
	return ans;
}
vector <int> lca(vector <int> a, vector <int> b) {
	for (int i = tot; i >= 1; i--) {
		if (a[i] != b[i]) {
			chkmin(a[i], b[i]);
			for (int j = i - 1; j >= 1; j--)
				a[j] = 0;
			return a;
		}
	}
	return a;
}
vector <pair <int, int>> a[MAXN];
int q, root, cnt[MAXN], sum[MAXN]; ll ans;
void addedge(int x, int y) {
	int d = dist(num[x], num[y]);
	a[x].emplace_back(y, d);
	a[y].emplace_back(x, d);
}
void dfs(int pos, int fa) {
	sum[pos] = cnt[pos];
	for (auto x : a[pos])
		if (x.first != fa) {
			dfs(x.first, pos);
			sum[pos] += sum[x.first];
		}
}
void getroot(int pos, int fa) {
	root = pos;
	for (auto x : a[pos])
		if (x.first != fa && sum[x.first] * 2 > q) {
			getroot(x.first, pos);
			return;
		}
}
void getans(int pos, int fa, int len) {
	ans += 1ll * len * cnt[pos];
	for (auto x : a[pos])
		if (x.first != fa) getans(x.first, pos, len + x.second);
}
int main() {
	int n = 5000; m = n, sieve(n);
	num[0].resize(tot + 1);
	for (int i = 1; i <= n; i++) {
		num[i] = num[i - 1];
		int tmp = i;
		while (tmp != 1) {
			num[i][home[f[tmp]]]++;
			tmp /= f[tmp];
		}
	}
	static int Stack[MAXN];
	int top = 1; Stack[top = 1] = 1;
	for (int i = 2; i <= n; i++) {
		vector <int> tmp = lca(num[i], num[Stack[top]]);
		if (tmp == num[Stack[top]]) Stack[++top] = i;
		else {
			while (tmp < num[Stack[top - 1]]) {
				addedge(Stack[top], Stack[top - 1]);
				top--;
			}
			if (tmp == num[Stack[top - 1]]) {
				addedge(Stack[top], Stack[top - 1]);
				Stack[top] = i;
			} else {
				num[++m] = tmp;
				addedge(Stack[top], m);
				Stack[top] = m;
				Stack[++top] = i;
			}
		}
	}
	for (int i = 1; i <= top - 1; i++)
		addedge(Stack[i], Stack[i + 1]);
	read(q);
	for (int i = 1; i <= q; i++) {
		int x; read(x);
		chkmax(x, 1);
		cnt[x]++;
	}
	dfs(1, 0);
	getroot(1, 0);
	getans(root, 0, 0);
	cout << ans << endl;
	return 0;
}