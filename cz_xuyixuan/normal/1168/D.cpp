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
char c[MAXN];
int n, m, len, d[MAXN], f[MAXN], dp[MAXN][26], val[MAXN][26];
int cnt, sum[MAXN], depth[MAXN], father[MAXN];
vector <int> a[MAXN];
int F(int x) {
	if (f[x] == x) return x;
	else return f[x] = F(f[x]);
}
void work(int pos) {
	for (auto x : a[pos]) {
		work(x);
		for (int i = 0; i <= 25; i++)
			chkmax(dp[pos][i], dp[x][i]);
	}
	for (int i = 0; i <= 25; i++) {
		sum[pos] += dp[pos][i];
		dp[pos][i] += val[pos][i];
	}
	cnt += sum[pos] > len - depth[pos];
}
void update(int pos, int type) {
	cnt -= sum[pos] > len - depth[pos];
	dp[pos][type] -= val[pos][type];
	sum[pos] -= dp[pos][type], dp[pos][type] = 0;
	for (auto x : a[pos])
		chkmax(dp[pos][type], dp[x][type]);
	sum[pos] += dp[pos][type];
	dp[pos][type] += val[pos][type];
	cnt += sum[pos] > len - depth[pos];
	if (pos != 1) update(father[pos], type);
}
void printans() {
	int tot = 0;
	for (int i = 0; i <= 25; i++)
		tot += dp[1][i];
	if (cnt) {
		puts("Fou");
		return;
	}
	int ans = 0;
	for (int i = 0; i <= 25; i++)
		ans += (i + 1) * (len - tot + dp[1][i]);
	printf("Shi %d\n", ans);
}
int main() {
	read(n), read(m);
	for (int i = 2; i <= n; i++) {
		scanf("%d %c", &father[i], &c[i]);
		d[father[i]]++, depth[i] = depth[father[i]] + 1;
	}
	for (int i = 1; i <= n; i++)
		if (d[i] == 0) {
			if (len == 0) len = depth[i];
			else if (len != depth[i]) len = -1;
		}
	if (len == -1) {
		for (int i = 1; i <= m; i++)
			puts("Fou");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		f[i] = i;
	for (int i = 2; i <= n; i++)
		if (father[i] != 1 && d[father[i]] == 1) {
			f[father[i]] = i;
			father[i] = father[father[i]];
		}
	for (int i = 2; i <= n; i++) {
		f[i] = F(i);
		if (f[i] == i) a[father[i]].push_back(i);
		if (c[i] != '?') val[f[i]][c[i] - 'a']++;
	}
	work(1);
	for (int i = 1; i <= m; i++) {
		int x; char s;
		scanf("%d %c", &x, &s);
		if (c[x] != '?') {
			val[f[x]][c[x] - 'a']--;
			dp[f[x]][c[x] - 'a']--;
			update(f[x], c[x] - 'a');
		}
		c[x] = s;
		if (c[x] != '?') {
			val[f[x]][c[x] - 'a']++;
			dp[f[x]][c[x] - 'a']++;
			update(f[x], c[x] - 'a');
		}
		printans();
	}
	return 0;
}