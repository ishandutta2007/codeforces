#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i)
#define fi first
#define se second
#define cat(x) cout << #x << " = " << x << endl

using namespace std;

const int nax = 4111;
const int mod = 1e9 + 7;

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

int fac[nax];
int rev[nax];
int len[nax];

int n, k;
int a[nax];

int newton(int N, int K) {
	K = N - K;
	int R = 1;
	for(int i = 1; i <= K; ++i)
		R = 1ll * R * (N - i + 1) % mod;
	R = 1ll * R * rev[K] % mod;
	return R;
}
 
int main() {
	fac[0] = rev[0] = 1;
	for(int i = 1; i < nax; ++i) {
		fac[i] = 1ll * fac[i - 1] * i % mod;
		rev[i] = pt(fac[i], mod - 2);
	}
	scanf("%d %d", &n, &k);
	for(int i = 0; i < n; ++i) 
		scanf("%d", a + i);
	if(!k) {
		for(int i = 0; i < n; ++i)
			printf("%d ", a[i]);
		return 0;
	}
	for(int i = 0; i <= n; ++i)
		len[i] = newton(i + k - 1, k - 1);
	for(int i = 0; i < n; ++i) {
		int ans = 0;
		for(int j = 0; j <= i; ++j)
			ans = (ans + 1ll * a[j] * len[i - j]) % mod;
		printf("%d ", ans);
	}
	
	
	return 0;
}