#include <bits/stdc++.h>
#define LL long long
#define LD long double
#define pb push_back
#define mp make_pair
#define ss(x) (int) x.size()
#define fi first
#define se second
#define cat(x) cerr << #x << " = " << x << endl
#define rep2(i, j, n) for (LL i = j; i <= n; ++i)
#define rep(i, j, n) for (int i = j; i <= n; ++i)
#define per(i, j, n) for (int i = n; j <= i; --i)

using namespace std;

void setIO(string name) {
    freopen((name+".in").c_str(),"r",stdin);
    freopen((name+".out").c_str(),"w",stdout);
}

const int N = 1e5 + 100;
const int M = 1e6 + 100;
const int MOD = 1e9 + 7;

void add(int &a, int b) {
	a += b;
	if (a >= MOD) a -= MOD;
}

void sub(int &a, int b) {
	a -= b;
	if (a < 0) a += MOD;
}

int pt(LL a, LL b) {
	if (!b) return 1;
	if (b & 1) return a * pt(a, b - 1) % MOD;
	return pt(a * a % MOD, b / 2);
}

int n, k, q;
int b;
int fac[M];
int rev[M];
vector <int> divi[M];

int e[M];
int ans;
int w[M];

int Newton(int N, int K) {
	if (N < K) return 0;
	return (LL) fac[N] * rev[N - K] % MOD * rev[K] % MOD;
}

int dp[M];
int phi[M];

void qw(int x) {
	for (auto it : divi[x]) {
		add(ans, (LL) phi[it] * w[e[it]] % MOD);
		e[it]++;
	}
}

int main() {
	fac[0] = rev[0] = 1;
	rep(i, 1, M - 1) {
		fac[i] = (LL) fac[i - 1] * i % MOD;
		rev[i] = pt(fac[i], MOD - 2);
		phi[i] = i;
	}
	rep(i, 1, M - 1) {
		for (int j = i; j < M; j += i) {
			divi[j].pb(i);
		}
		if (i > 1 && ss(divi[i]) == 2)
			for (int j = i; j < M; j += i)
				phi[j] -= phi[j] / i;
	}
	scanf ("%d%d%d", &n, &k, &q);
	rep(i, 0, M - 1) 
		w[i] = Newton(i, k - 1);
	rep(i, 1, n + q) {
		scanf ("%d", &b);
		qw(b);
		if (i > n) printf ("%d\n", ans);
	}
	
	
	return 0;
}