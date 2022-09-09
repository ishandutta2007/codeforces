#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e3 + 5;
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
} int n, Min, ans;
vector <int> a[MAXN];
bool vis[MAXN], mp[MAXN][MAXN];
char s[MAXN][MAXN];

int tot, belong[MAXN], size[MAXN];
int timer, dfn[MAXN], low[MAXN];
int top, Stack[MAXN];
bool instack[MAXN];
void tarjan(int pos) {
	dfn[pos] = low[pos] = ++timer;
	instack[pos] = true;
	Stack[++top] = pos;
	for (unsigned i = 0; i < a[pos].size(); i++)
		if (dfn[a[pos][i]] == 0) {
			tarjan(a[pos][i]);
			low[pos] = min(low[pos], low[a[pos][i]]);
		} else if (instack[a[pos][i]]) low[pos] = min(low[pos], dfn[a[pos][i]]);
	if (low[pos] == dfn[pos]) {
		int tmp = Stack[top--];
		instack[tmp] = false;
		belong[tmp] = ++tot, size[tot]++;
		while (tmp != pos) {
			tmp = Stack[top--];
			instack[tmp] = false;
			belong[tmp] = tot, size[tot]++;
		}
	}
}
int fac(int x) {
	if (x == 0) return 1;
	int ans = x;
	while (--x) ans *= x;
	return ans;
}
void work(int pos, int cnt) {
	if (pos > n) {
		for (int i = 1; i <= n; i++)
			a[i].clear();
		for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			if (i != j && (mp[i][j] ^ vis[i] ^ vis[j])) a[i].push_back(j);
		memset(dfn, 0, sizeof(dfn)), tot = 0;
		tarjan(1);
		bool flg = true;
		for (int i = 1; i <= n; i++)
			if (!dfn[i] || belong[i] != belong[1]) {
				flg = false;
				break;
			}
		if (flg) {
			if (cnt < Min) {
				Min = cnt;
				ans = fac(cnt);
			} else if (cnt == Min) ans += fac(cnt);
		}
	} else {
		vis[pos] = true;
		work(pos + 1, cnt + 1);
		vis[pos] = false;
		work(pos + 1, cnt);
	}
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++) {
		scanf("\n%s", s[i] + 1);
		for (int j = 1; j <= n; j++) {
			mp[i][j] = s[i][j] == '1';
			if (mp[i][j]) a[i].push_back(j);
		}
	}
	if (n <= 6) {
		Min = 1e9, work(1, 0);
		if (Min > 2) puts("-1");
		else cout << Min << ' ' << ans << endl;
		return 0;
	}
	static int d[MAXN], res[MAXN];
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
		d[i] += mp[i][j];
	memcpy(res, d, sizeof(d));
	sort(res + 1, res + n + 1, [&] (int x, int y) {return x > y; });
	bool flg = false; int pre = 0;
	for (int j = 1; j <= n - 1; j++) {
		pre += res[j];
		flg |= pre == j * (j - 1) / 2 + j * (n - j);
	}
	if (!flg) {
		cout << 0 << ' ' << 1 << endl;
		return 0;
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++)
			if (i != j) {
				d[i] -= mp[i][j], d[i] += mp[j][i];
				d[j] += mp[i][j], d[j] -= mp[j][i];
			}
		memcpy(res, d, sizeof(d));
		sort(res + 1, res + n + 1, [&] (int x, int y) {return x > y; });
		bool flg = false; int pre = 0;
		for (int j = 1; j <= n - 1; j++) {
			pre += res[j];
			flg |= pre == j * (j - 1) / 2 + j * (n - j);
		}
		ans += !flg;
		for (int j = 1; j <= n; j++)
			if (i != j) {
				d[j] -= mp[i][j], d[j] += mp[j][i];
				d[i] += mp[i][j], d[i] -= mp[j][i];
			}
	}
	cout << 1 << ' ' << ans << endl;
	return 0;
}