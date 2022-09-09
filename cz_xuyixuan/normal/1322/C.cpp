#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5e5 + 5;
typedef long long ll;
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
ll a[MAXN]; ull b[MAXN], v[MAXN];
map <ull, ll> mp; int n, m;
ull rnd() {
	ull ans = 0;
	for (int i = 0; i <= 7; i++) {
		ans <<= 8;
		ans ^= rand() & 255;
	}
	return ans;
}
int main() {
	srand('X' + 'Y' + 'X');
	int T; read(T);
	while (T--) {
		read(n), read(m);
		for (int i = 1; i <= n; i++) {
			read(a[i]), b[i] = 0;
			v[i] = rnd();
		}
		for (int i = 1; i <= m; i++) {
			int x, y; read(x), read(y);
			b[y] ^= v[x];
		}
		mp.clear();
		for (int i = 1; i <= n; i++)
			if (b[i] != 0) mp[b[i]] += a[i];
		ll ans = 0;
		for (auto x : mp)
			ans = __gcd(ans, x.second);
		printf("%lld\n", ans);
	}
	return 0;
}