#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define FOR(i, j, n) for(int i = j; i <= n; ++i)
#define fi first
#define se second
#define ss(x) (int) x.size()

using namespace std;

const int nax = 2e5 + 111;
const int mod = 1e9 + 7;

int n, m;
int res = 0;

int pt(int a, int b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = (ll) c * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return c;
}

int sil[nax];
int odw[nax];

int daj(int N, int K) {
	int res = sil[N];
	res = (ll) res * odw[K] % mod;
	res = (ll) res * odw[N - K] % mod;
	return res;
}

int main() {
	sil[0] = odw[0] = 1;
	FOR(i, 1, nax - 1) {
		sil[i] = (ll) sil[i - 1] * i % mod;
		odw[i] = pt(sil[i], mod - 2);
	}

	scanf("%d %d", &n, &m);
	for(int d = 0; d <= max(n, m); ++d) {
		int j1 = n - 2 * d;
		if(j1 >= 0) {
			res = (res + (ll) daj(j1 + d, d) * 2 % mod) % mod;
		}
		int j2 = m - 2 * d;
		if(j2 >= 0) {
			res = (res + (ll) daj(j2 + d, d) * 2 % mod) % mod;
		}
	}
	printf("%d", (res - 2 + mod) % mod);





	return 0;
}