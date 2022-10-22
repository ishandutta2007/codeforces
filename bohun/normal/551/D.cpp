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

ll n, k, l, m;

int Pot(int a, ll b) {
	int c = 1;
	while(b) {
		if(b & 1)
			c = 1ll * c * a % m;
		a = 1ll * a * a % m;
		b /= 2;
	}
	return c;
}

struct matrix {
	int t[2][2];
	
	matrix () {
		memset(t, 0, sizeof(t));
	}
	
	matrix operator * (matrix b) {
		matrix c = matrix();
		for(int i = 0; i < 2; ++i)
			for(int j = 0; j < 2; ++j)
				for(int k = 0; k < 2; ++k)
					c.t[i][j] = (c.t[i][j] + 1ll * t[i][k] * b.t[k][j]) % m;
		return c;
	}
};

matrix pot (matrix a, ll K) {
	matrix res = matrix();
	res.t[0][0] = res.t[1][1] = 1;
	while(K) {
		if(K & 1)
			res = res * a;
		a = a * a;
		K /= 2;
	}
	return res;
}
	
 
int main() {
	scanf("%lld %lld %lld %lld", &n, &k, &l, &m);
	int ile = 0;
	ll xx = 0;
	for(int i = l - 1; 0 <= i; --i) {
		if(((k >> i) & 1)) {
			xx += (1ll << i);
			ile += 1;
		}
	}
	if(xx != k) 
		return printf("0"), 0;
	
	matrix x = matrix();
	x.t[0][0] = 1;
	x.t[1][0] = 1;
	x.t[0][1] = 1;
	x.t[1][1] = 0;
	
	matrix y = matrix();
	y.t[0][0] = 1;
	y.t[0][1] = 1;
	
	x = pot(x, n - 1);
	
	y = y * x;
	
	int z = (y.t[0][0] + y.t[0][1]) % m;
	int zz = Pot(2, n);
	int zzz = (zz - z + m) % m;
	
	int ans = 1;
	for(int i = 1; i <= ile; ++i)
		ans = 1ll * ans * zzz % m;
	for(int i = 1; i <= l - ile; ++i)
		ans = 1ll * ans * z % m;
	printf("%lld", ans % m);
	
	
	
	
	
	
	
	
	return 0;
}