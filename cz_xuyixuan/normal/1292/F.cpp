#include<bits/stdc++.h>
using namespace std;
const int MAXN = 65;
const int MAXS = 32768;
const int P = 1e9 + 7;
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
int n, m, bit[MAXN], a[MAXN], key[MAXN];
int f[MAXN], binom[MAXN][MAXN], dp[MAXS][MAXN];
int find(int x) {
	if (f[x] == x) return x;
	else return f[x] = find(f[x]);
}
int getcnt(int x) {
	int ans = -1;
	for (int i = 1; i <= n; i++)
		if (f[i] == x) ans += key[i] == -1;
	return max(ans, 0);
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int getans(int x) {
	int cnt = getcnt(x), m = 0;
	if (cnt == 0) return 1; cnt++;
	static int ins[MAXS], type[MAXN];
	for (int i = 1; i <= n; i++)
		if (f[i] == x && key[i] != -1) key[i] = ++m;
	for (int i = 0; i < (1 << m); i++)
		ins[i] = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == x && key[i] == -1) {
			type[i] = 0;
			for (int j = 1; j <= n; j++)
				if (f[j] == x && key[j] != -1 && a[i] % a[j] == 0) type[i] |= 1 << (key[j] - 1);
			for (int j = 0; j < (1 << m); j++)
				ins[j] += (type[i] | j) == j;
		}
	static int dp[MAXN][MAXS];
	memset(dp, 0, sizeof(dp));
	for (int i = 1; i <= n; i++)
		if (f[i] == x && key[i] == -1) update(dp[1][type[i]], 1);
	for (int i = 1; i <= cnt - 1; i++)
	for (int j = 0; j < (1 << m); j++) {
		int tmp = dp[i][j];
		if (!tmp) continue;
		update(dp[i + 1][j], 1ll * tmp * (ins[j] - i) % P);
		for (int k = 1; k <= n; k++)
			if (f[k] == x && key[k] == -1 && (type[k] & j) != 0 && (type[k] | j) != j) update(dp[i + 1][j | type[k]], tmp);
	}
	return dp[cnt][(1 << m) - 1];
}
int main() {
	read(n);
	for (int i = 1; i <= n; i++)
		read(a[i]), f[i] = i;
	for (int i = 0; i <= n; i++) {
		binom[i][0] = 1;
		for (int j = 1; j <= i; j++)
			binom[i][j] = (binom[i - 1][j - 1] + binom[i - 1][j]) % P;
	}
	sort(a + 1, a + n + 1);
	for (int i = 1; i <= n; i++) {
		if (key[i] == -1) continue;
		bool vis = false;
		for (int j = i + 1; j <= n; j++)
			if (a[j] % a[i] == 0) {
				vis = true;
				key[j] = -1;
				f[find(i)] = find(j);
			}
		if (vis) key[i] = ++m;
		else key[i] = -1;
	}
	for (int i = 1; i <= n; i++)
		f[i] = find(i);
	assert(m <= 15);
	int ans = 1, cnt = 0;
	for (int i = 1; i <= n; i++)
		if (f[i] == i) {
			ans = 1ll * ans * getans(i) % P * binom[cnt + getcnt(i)][cnt] % P;
			cnt += getcnt(i);
		}
	cout << ans << endl;
	return 0;
}