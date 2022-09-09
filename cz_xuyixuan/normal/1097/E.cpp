#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e5 + 5;
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
int n, a[MAXN]; 
bool vis[MAXN];
vector <vector <int> > ans;
void solve(int k) {
	static vector <int> low[MAXN];
	int Max = 0; low[0].resize(1);
	static int dp[MAXN], from[MAXN];
	for (int i = 1; i <= n; i++) {
		if (vis[a[i]]) continue;
		int l = 0, r = Max + 1;
		while (l < r) {
			int mid = (l + r) / 2;
			if (a[i] > low[mid].back()) l = mid + 1;
			else r = mid;
		}
		dp[a[i]] = l, from[a[i]] = low[l - 1].back();
		if (l > Max) {
			Max = l;
			low[Max].clear();
			low[Max].push_back(a[i]);
		} else low[l].push_back(a[i]);
	}
	if (Max == 0) return;
	if (Max >= k) {
		vector <int> res; res.clear();
		int pos = 0;
		for (int i = 1; i <= n; i++)
			if (!vis[a[i]] && dp[a[i]] == Max) {
				pos = a[i];
				break;
			}
		while (pos) {
			res.push_back(pos);
			vis[pos] = true;
			pos = from[pos];
		}
		reverse(res.begin(), res.end());
		ans.push_back(res);
		solve(k - 1);
	} else {
		for (int i = 1; i <= Max; i++)
			ans.push_back(low[i]);
	}
}
int main() {
	int T; read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= n; i++) {
			read(a[i]);
			vis[i] = false;
		}
		ans.clear();
		int k = 1;
		while (k * (k + 1) / 2 <= n) k++;
		solve(k);
		writeln(ans.size());
		for (auto x : ans) {
			write(x.size());
			for (auto y : x)
				printf(" %d", y);
			putchar('\n');
		}
	}
	return 0;
}