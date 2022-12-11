#include <bits/stdc++.h>

const int MAXN = 710;
const int mod = 1e9 + 7;
typedef long long LL;
void reduce(int & x) { x += x >> 31 & mod; }
int mul(int a, int b) { return (LL) a * b % mod; }

typedef std::pair<int, int> pi;
char buf[MAXN];
pi f[10][MAXN][MAXN];
bool vis[10][MAXN][MAXN];
int pw[MAXN];
typedef std::pair<int, int> pi;
pi calc(int nu, int dig, int at, bool eq) {
	if (dig == -1) return pi(0, pw[at]);
	if (!eq && vis[nu][dig][at])
		return f[nu][dig][at];
	int lhs = 0, rhs = 0;
	int up = eq ? buf[dig] - '0' : 9;
	for (int i = 0; i <= up; ++i) {
		pi ret = calc(nu, dig - 1, at + (i > nu), eq && i == up);
		reduce(rhs += ret.second - mod);
		if (i == nu) {
			lhs = ((LL) ret.first * 10 + ret.second + lhs) % mod;
		} else {
			reduce(lhs += ret.first - mod);
		}
	}
	if (!eq) {
		vis[nu][dig][at] = true;
		f[nu][dig][at] = pi(lhs, rhs);
	}
	return pi(lhs, rhs);
}
int main() {
	std::ios_base::sync_with_stdio(false), std::cin.tie(0);
	std::cin >> buf; int L = strlen(buf);
	std::reverse(buf, buf + L);
	int ans = 0;
	for (int i = *pw = 1; i != MAXN; ++i)
		pw[i] = mul(pw[i - 1], 10);
	for (int i = 1; i < 10; ++i)
		ans = (ans + (LL) i * calc(i, L - 1, 0, 1).first) % mod;
	std::cout << ans << '\n';
	return 0;
}