#include<bits/stdc++.h>
#define rep(i,a,b) for (int i=(a); i<=(b); i++)
#define per(i,a,b) for (int i=(a); i>=(b); i--)
#define REP(i,n) for (int i=0; i<(n); i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;

const int L = 200005, N = 2005, M = 20;
const int mod = 1000000007;
int f[N][M + 5], fac[L], rev[L], x[N], y[N];
int n, m, K, s;

inline int inv(int x, int p = mod - 2) {
	int res = 1;
	while (p) {
		if (p & 1) res = 1ll * res * x % mod;
		x = 1ll * x * x % mod; p >>= 1;
	}
	return res;
}

void init(int n) {
	fac[0] = rev[0] = 1;
	rep (i, 1, n)
		fac[i] = 1ll * i * fac[i - 1] % mod;
	rev[n] = inv(fac[n]);
	per (i, n - 1, 1)
		rev[i] = 1ll * rev[i + 1] * (i + 1) % mod;
}

inline int C(int n, int m) {
	if (m < 0 || m > n) return 0;
	return 1ll * fac[n] * rev[m] % mod * rev[n - m] % mod;
}

inline int add(int &a, int b) {
	a += b; if (a >= mod) a -= mod;
}

inline int del(int &a, int b) {
	a -= b; if (a < 0) a += mod;
}

int rk[N];
inline bool cmp(int a, int b) {
	return x[a] < x[b] || x[a] == x[b] && y[a] < y[b] || b == K;
}

inline int ways(int a, int b) {
	return C(x[b] - x[a] + y[b] - y[a], x[b] - x[a]);
}

void doit() {
	x[0] = y[0] = 1;
	x[++K] = n, y[K] = m;
	f[0][0] = 1;
	rep (i, 1, K) rk[i] = i;
	sort(rk + 1, rk + K + 1, cmp);
	rep (i, 1, K) {
		int u = rk[i];
		rep (j, 0, i - 1) {
			int v = rk[j];
			if (x[v] > x[u] || y[v] > y[u]) continue;
			rep (k, u != K, M) {
				add(f[u][k], 1ll * f[v][k - (u != K)] 
								 * ways(v, u) % mod);
				del(f[u][k], 1ll * f[v][k - (u != K) + 1]
								 * ways(v, u) % mod);
			}
		}
	}
}

int main() {
	scanf("%d%d%d%d", &n, &m, &K, &s);
	rep (i, 1, K)
		scanf("%d%d", &x[i], &y[i]);
	init(n + m);
	doit();
	int res = 0, tmp = inv(C(n + m - 2, n - 1));
	rep (i, 0, M) {
		res = (res + 1ll * f[K][i] * s % mod) % mod;
		s = (s + 1) >> 1;
	}
	printf("%lld\n", 1ll * res * tmp % mod);
	return 0;
}