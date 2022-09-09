#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1 << 18;
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
bool vis[MAXN]; ll ans;
int n, cnt[MAXN], f[MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
void work(int x, int y) {
	ll inc = x + y, cmt = 1;
	x = find(x), y = find(y);
	if (x == y) return;
	if (!vis[x]) cmt += cnt[x] - 1;
	if (!vis[y]) cmt += cnt[y] - 1;
	ans += inc * cmt, f[x] = y;
	vis[x] = vis[y] = true;
}
int main() {
	read(n), cnt[0]++;
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		cnt[x]++, ans -= x;
	}
	int u = (1 << 18) - 1;
	for (int i = 0; i <= u; i++)
		f[i] = i, vis[i] = false;
	for (int i = u; i >= 0; i--)
	for (int j = i; j > (i ^ j); j = (j - 1) & i)
		if (cnt[j] && cnt[i ^ j]) work(j, i ^ j);
	cout << ans << endl;
	return 0;
}