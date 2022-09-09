#include<bits/stdc++.h>
using namespace std;
const int MAXN = 1e7 + 5;
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
int power(int x, int y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void update(int &x, int y) {
	x += y;
	if (x >= P) x -= P;
}
int tot, prime[MAXN], f[MAXN], miu[MAXN];
void sieve(int n) {
	miu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i, miu[i] = P - 1;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
			if (prime[j] == f[i]) miu[tmp] = 0;
			else miu[tmp] = (P - miu[i]) % P;
		}
	}
}
int cnt[MAXN], two[MAXN];
int func(int cnt, int n) {
	int ans = 1ll * two[cnt] * n % P;
	update(ans, P - 1ll * two[cnt - 1] * cnt % P);
	update(ans, P - n);
	return ans;
}
int main() {
	int n, m = 1e7, ans = 0; read(n);
	for (int i = 1; i <= n; i++) {
		int x; read(x);
		cnt[x]++;
	}
	sieve(m), two[0] = 1;
	for (int i = 1; i <= m; i++)
		two[i] = two[i - 1] * 2 % P;
	for (int i = 1; i <= m; i++) {
		int all = 0;
		for (int j = i; j <= m; j += i)
			all += cnt[j];
		if (all && miu[i]) {
			int coef = 1ll * miu[i] * two[all - 1] % P;
			for (int j = i; j <= m; j += i)
				update(ans, 1ll * coef * cnt[j] % P);
			if (miu[i] == 1) update(ans, P - func(all, n));
			else update(ans, func(all, n));
		}
	}
	cout << ans << endl;
	return 0;
}