#include<bits/stdc++.h>
using namespace std;
const int MAXN = 105;
const int MAXM = 2e3 + 5;
const int MAXV = 1e5 + 5;
const int INF  = 1e9;
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
struct info {ll k, b; };
void exgcd(ll a, ll b, ll &x, ll &y) {
	if (b == 0) {
		assert(a == 1);
		x = 1, y = 0;
		return;
	}
	ll q = a / b, r = a % b;
	exgcd(b, r, y, x);
	x = -x, y = -y + x * q;
}
info merge(info x, info y) {
	if (x.b > y.b) swap(x, y);
	ll g = __gcd(x.k, y.k), c = y.b - x.b;
	if (c % g != 0) {
		puts("-1");
		exit(0);
	}
	ll tx = 0, ty = 0; c /= g;
	exgcd(x.k / g, y.k / g, tx, ty);
	if (y.k <= 30) {
		ll k = y.k / g, b = (tx % k + k) * c % k;
		x.b += x.k * b, x.k *= k;
		return x;
	} else {
		ll k = x.k / g, b = (ty % k + k) * c % k;
		y.b += y.k * b, y.k *= k;
		return y;
	}
}
set <int> primes;
int n, a[MAXN], b[MAXN];
int x[MAXN], y[MAXN], tx[MAXN], ty[MAXN];
int tot, prime[MAXV], f[MAXV];
void sieve(int n) {
	for (int i = 2; i <= n; i++) {
		if (f[i] == 0) prime[++tot] = f[i] = i;
		for (int j = 1; j <= tot && prime[j] <= f[i]; j++) {
			int tmp = prime[j] * i;
			if (tmp > n) break;
			f[tmp] = prime[j];
		}
	}
}
void inprime(int x) {
	for (int i = 1; i <= tot; i++)
		while (x % prime[i] == 0) {
			x /= prime[i];
			primes.insert(prime[i]);
		}
	if (x != 1) primes.insert(x);
}
int power(int x, ll y) {
	if (y == 0) return 1;
	int tmp = power(x, y / 2);
	if (y % 2 == 0) return 1ll * tmp * tmp % P;
	else return 1ll * tmp * tmp % P * x % P;
}
void report(int pos, ll val) {
	if (val < 0) {
		puts("-1");
		exit(0);
	}
	for (auto p : primes) {
		static int x[MAXN], y[MAXN];
		for (int i = 1, tmp; i <= n; i++) {
			x[i] = 0, y[i] = 0;
			tmp = a[i]; while (tmp % p == 0) tmp /= p, x[i]++;
			tmp = b[i]; while (tmp % p == 0) tmp /= p, y[i]++;
		}
		ll goal = x[pos] + y[pos] * val;
		for (int i = 1; i <= n; i++) {
			if (x[i] > goal || (y[i] == 0 && x[i] != goal) || (y[i] != 0 && (goal - x[i]) % y[i])) {
				puts("-1");
				exit(0);
			}
		}
	}
	printf("%lld\n", 1ll * a[pos] * power(b[pos], val) % P);
	exit(0);
}
int main() {
	read(n), sieve(sqrt(1e9 + 7));
	for (int i = 1; i <= n; i++) {
		read(a[i]), read(b[i]);
		inprime(a[i]);
		inprime(b[i]);
	}
	if (n == 1) {
		cout << a[1] << endl;
		return 0;
	}
	bool vis = false;
	for (auto p : primes) {
		int Min = INF;
		for (int i = 1, tmp; i <= n; i++) {
			x[i] = 0, y[i] = 0;
			tmp = a[i]; while (tmp % p == 0) tmp /= p, x[i]++;
			tmp = b[i]; while (tmp % p == 0) tmp /= p, y[i]++;
			chkmin(Min, x[i]);
		}
		int g = 0;
		for (int i = 1; i <= n; i++) {
			x[i] -= Min;
			g = __gcd(g, x[i]);
			g = __gcd(g, y[i]);
		}
		if (g == 0) continue;
		for (int i = 1; i <= n; i++) {
			x[i] /= g;
			y[i] /= g;
		}
		bool fx = true, fy = true;
		for (int i = 1; i <= n; i++) {
			if (y[i]) fy = false;
			if (x[i] != x[1]) fx = false;
		}
		if (fy) {
			if (fx) continue;
			else {
				puts("-1");
				return 0;
			}
		}
		for (int i = 1; i <= n; i++)
		for (int j = i + 1; j <= n; j++) {
			if (y[i] == 0 && y[j] != 0) report(j, (x[i] - x[j]) / y[j]);
			if (y[j] == 0 && y[i] != 0) report(i, (x[j] - x[i]) / y[i]);
		}
		if (vis) {
			for (int i = 1; i <= n; i++)
			for (int j = i + 1; j <= n; j++) {
				int k1, k2, b1, b2;
				k1 = ty[i] * y[j];
				b1 = ty[i] * (x[j] - x[i]);
				k2 = y[i] * ty[j];
				b2 = y[i] * (tx[j] - tx[i]);
				if (k1 != k2) report(j, (b1 - b2) / (k2 - k1));
				else if (b1 != b2) {
					puts("-1");
					exit(0);
				}
				k1 = ty[j] * y[i];
				b1 = ty[j] * (x[i] - x[j]);
				k2 = y[j] * ty[i];
				b2 = y[j] * (tx[i] - tx[j]);
				if (k1 != k2) report(i, (b1 - b2) / (k2 - k1));
				else if (b1 != b2) {
					puts("-1");
					exit(0);
				}
			}
		} else {
			for (int i = 1; i <= n; i++) {
				tx[i] = x[i];
				ty[i] = y[i];
			}
			vis = true;
		}
	}
	if (!vis) {
		cout << a[1] << endl;
		return 0;
	}
	info res = (info) {1, 0};
	for (int i = 1; i <= n; i++)
		res = merge(res, (info) {ty[i], tx[i] % ty[i]});
	ll ans = res.b;
	for (int i = 1; i <= n; i++)
		while (tx[i] > ans) ans += res.k;
	report(1, (ans - tx[1]) / ty[1]);
	return 0;
}