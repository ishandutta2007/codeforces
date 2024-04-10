#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 998244353;
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
bool vis[MAXN];
int n, k, a[MAXN], home[MAXN];
int main() {
	read(n), read(k);
	for (int i = 1; i <= n; i++)
		read(a[i]), home[a[i]] = i;
	ll ans = 0; int cnt = 1;
	for (int i = 1; i <= k; i++) {
		ans += n - i + 1;
		vis[home[n - i + 1]] = true;
	}
	int last = 0;
	for (int i = 1; i <= n; i++)
		if (vis[i]) {
			if (last != 0) cnt = 1ll * cnt * (i - last) % P;
			last = i;
		}
	printf("%lld %d\n", ans, cnt);
	return 0;
}