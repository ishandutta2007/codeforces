#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
#define ss(x) (int) x.size()
#define pb push_back
#define ll long long
#define cat(x) cerr << #x << " = " << x << endl
#define FOR(i, n) for(int i = 0; i < n; ++i)

using namespace std;

const int nax = 1000000;
const int mod = 998244353;

void add(int &a, int b) {
	a += b;
	if(a >= mod)
		a -= mod;
}

void sub(int &a, int b) {
	a -= b;
	if(a < 0)
		a += mod;
}

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % mod;
		a = 1ll * a * a % mod;
		b /= 2;
	}
	return c;
}

int n, m, k;
int fac[nax];
int rev[nax];
int PT[nax];

int daj(int N, int K) {
	if(N < K) return 0;
	int res = 1;
	for(int i = N - K + 1; i <= N; ++i) {
		res = 1ll * res * i % mod;
	}
	return 1ll * res * rev[K] % mod;
}

int newton(int N, int K) {
	if(N < K) return 0;
	return 1ll * fac[N] * rev[N - K] % mod * rev[K] % mod;
}

int xd(int l, int X) {
	int res = 1;
	for(int i = 1; i <= l; ++i) {
		res = 1ll * res * X % mod;
		X--;
	}
	return res;
}

int main() {
	fac[0] = 1;
	rev[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 0; i < nax; ++i)
		PT[i] = pt(i, k);
	
	int res = 0;
	for(int i = 1; i <= k; ++i) { // rozne
		int elo = 0;
		for(int j = 0; j < i; ++j) {
			if(j % 2 == 0) 
				add(elo, 1ll * PT[i - j] * newton(i, j) % mod);
			else
				sub(elo, 1ll * PT[i - j] * newton(i, j) % mod);
		}
		add(res, 1ll * elo * daj(n, i) % mod * pt(pt(m, i), mod - 2) % mod);
		assert(res > 0);
	}
	printf("%d", res);
		


	return 0;
}