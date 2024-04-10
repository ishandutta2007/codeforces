#include<bits/stdc++.h>
using namespace std;
const int MAXN = 5005;
const double eps = 1e-9;
const int P = 998244353;
typedef long long ll;
typedef long double ld;
typedef pair <ll, int> info;
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
ll ans, n, m, tot, a[MAXN];
vector <info> b;
ll gcd(ll x, ll y) {
	if (y == 0) return x;
	else return gcd(y, x % y);
}
int main() {
	read(m);
	for (int i = 1; i <= m; i++) {
		ll x, tmp; read(x);
		tmp = pow(x, 1.0 / 4.0);
		while (tmp * tmp * tmp * tmp < x) tmp++;
		while (tmp * tmp * tmp * tmp > x) tmp--;
		if (tmp * tmp * tmp * tmp == x) {
			b.push_back(make_pair(tmp, 4));
			continue;
		}
		tmp = pow(x, 1.0 / 3.0);
		while (tmp * tmp * tmp < x) tmp++;
		while (tmp * tmp * tmp > x) tmp--;
		if (tmp * tmp * tmp == x) {
			b.push_back(make_pair(tmp, 3));
			continue;
		}
		tmp = pow(x, 1.0 / 2.0);
		while (tmp * tmp < x) tmp++;
		while (tmp * tmp > x) tmp--;
		if (tmp * tmp == x) {
			b.push_back(make_pair(tmp, 2));
			continue;
		}
		a[++n] = x;
	}
	for (int i = 1; i <= n; i++)
	for (int j = i + 1; j <= n; j++)
		if (a[i] != a[j]) {
			ll tmp = gcd(a[i], a[j]);
			if (tmp != 1) b.push_back(make_pair(tmp, 0));
		}
	sort(b.begin(), b.end());
	ll ans = 1;
	while (!b.empty()) {
		ll x = b.back().first;
		int cnt = b.back().second;
		b.pop_back();
		while (!b.empty() && x == b.back().first) {
			cnt += b.back().second;
			b.pop_back();
		}
		for (int i = 1; i <= n; i++)
			if (a[i] % x == 0) {
				cnt++;
				b.push_back(make_pair(a[i] / x, 1));
				a[i] = 1;
			}
		ans = ans * (cnt + 1) % P;
		sort(b.begin(), b.end());
	}
	sort(a + 1, a + n + 1);
	for (int i = 1, nxt; i <= n; i = nxt) {
		nxt = i;
		while (a[nxt] == a[i]) nxt++;
		int cnt = nxt - i;
		if (a[i] == 1) continue;
		ans = ans * (cnt + 1) % P * (cnt + 1) % P;
	}
	cout << ans << endl;
	return 0;
}