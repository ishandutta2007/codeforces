#include<bits/stdc++.h>
using namespace std;
const int MAXN = 2e5 + 5;
const int P = 1e9 + 7;
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
int miu[MAXN], powk[MAXN];
vector <int> factors[MAXN];
int tot, prime[MAXN], f[MAXN];
void sieve(int n) {
	miu[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i, miu[i] = P - 1;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			if (prime[j] == f[i]) miu[tmp] = 0;
			else miu[tmp] = (P - miu[i]) % P;
			f[tmp] = prime[j];
		}
	}
	for (int i = 1; i <= n; i++)
	for (int j = i; j <= n; j += i)
		factors[j].push_back(i);
}
int calc(int lim, int sum) {
	int l = 1, r = lim;
	chkmax(l, sum - lim);
	chkmin(r, sum - 1);
	if (l > r) return 0;
	int ans = 0;
	for (auto x : factors[sum])
		update(ans, 1ll * miu[x] * (P - (l - 1) / x + r / x) % P);
	return ans;
}
int main() {
	int n, k, ans = 0; read(n), read(k);
	sieve(2 * n), powk[0] = 1;
	for (int i = 1; i <= n; i++)
		powk[i] = 1ll * powk[i - 1] * k % P;
	for (int s = 2; s <= 2 * n - 2; s++)
	for (auto g : factors[s]) {
		int lim = (n - 1) / g, sum = s / g;
		if (lim <= 0 || sum <= 1) continue;
		update(ans, 1ll * calc(lim, sum) * powk[max(g, s - n)] % P);
	}
	writeln(1ll * ans * power(powk[n], P - 2) % P);
	return 0;
}