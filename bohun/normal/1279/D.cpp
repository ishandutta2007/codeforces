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

const int mod = 998244353;

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

int n;
int v[1000111];
int vv[1000111];
int a;

int main() {
	scanf("%d", &n);
	int odw2 = pt(1ll * n * n % mod, mod - 2);
	for(int i = 1; i <= n; ++i) {
		int k;
		scanf("%d", &k);
		int elo = pt(k, mod - 2);
		for(int j = 1; j <= k; ++j) {
			scanf("%d", &a);
			v[a] = (v[a] + elo) % mod;
			vv[a]++;
		}
	}
	int ans = 0;
	for(int i = 1; i <= 1000000; ++i) {
		ans = (ans + 1ll * odw2 * vv[i] % mod * v[i] % mod) % mod;
	}
	printf("%d", ans);
	
		
	
	return 0;
}