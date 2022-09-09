#include<bits/stdc++.h>
using namespace std;
const int MAXN = 20;
const int MAXS = 1 << 18;
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
int n, u, bit[MAXN], bits[MAXS]; char mp[MAXN][MAXN];
ll f[MAXN][MAXS], g[MAXN][MAXS], ans[MAXS];
void FWTOR(ll *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[j] += a[i];
}
void UFWTAND(ll *a, int N) {
	for (int len = 2; len <= N; len <<= 1)
	for (int s = 0; s < N; s += len)
	for (int i = s, j = s + len / 2; j < s + len; i++, j++)
		a[i] -= a[j];
}
vector <int> a; map <vector <int>, ll> res;
void work(int lft, int cur, int depth) {
	if (lft == 0) {
		ll ans = 0;
		for (int i = 0; i <= u; i++)
			if ((bits[i] & 1) ^ (bits[u] & 1)) ans -= g[depth][i];
			else ans += g[depth][i];
		res[a] += ans;
	} else {
		if (cur >= 2) work(lft, cur - 1, depth);
		if (lft >= cur) {
			for (int i = 0; i <= u; i++)
				g[depth + 1][i] = g[depth][i] * f[cur][i];
			a.push_back(cur);
			work(lft - cur, cur, depth + 1);
			a.pop_back();
		}
	}
}
void getf() {
	static ll dp[MAXN][MAXS];
	for (int i = 1; i <= n; i++) {
		bit[i] = 1 << (i - 1);
		dp[i][bit[i]] = 1;
	}
	for (int s = 0; s <= u; s++) {
		for (int i = 1; i <= n; i++)
			if (s & bit[i]) {
				for (int j = 1; j <= n; j++)
					if (mp[i][j] == '1' && (s & bit[j]) == 0) {
						dp[j][s ^ bit[j]] += dp[i][s];
					}
			}
	}
	for (int s = 0; s <= u; s++) {
		int cnt = 0;
		for (int i = 1; i <= n; i++)
			if (s & bit[i]) cnt++;
		bits[s] = cnt;
		for (int i = 1; i <= n; i++)
			f[cnt][s] += dp[i][s];
	}
	for (int i = 1; i <= n; i++)
		FWTOR(f[i], 1 << n);
}
int main() {
	read(n), u = (1 << n) - 1;
	for (int i = 1; i <= n; i++)
		scanf("\n%s", mp[i] + 1);
	getf();
	for (int i = 0; i <= u; i++)
		g[0][i] = 1;
	work(n, n, 0);
	for (int s = 0; s <= u / 2; s++) {
		vector <int> a; int last = 0;
		for (int i = 1; i <= n - 1; i++)
			if ((bit[i] & s) == 0) {
				a.push_back(i - last);
				last = i;
			}
		a.push_back(n - last);
		sort(a.begin(), a.end(), [&] (int x, int y) {return x > y; });
		ans[s] = res[a];
	}
	UFWTAND(ans, 1 << n);
	for (int i = 0; i <= u / 2; i++)
		printf("%lld ", ans[i]);
	return 0;
}