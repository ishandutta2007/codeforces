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

const int mod = 998244353;
const int nax = 2e5 + 11;

void add(int &a, int b) {
	a += b;
	if(a < 0)
		a += mod;
	if(a >= mod)
		a -= mod;
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

int n, q;
int p[nax], a;

set<int> s;
int ak[nax];

int w[nax];
int o[nax];
int pref[nax];
int ja[nax];

int out;

int oblicz(int le, int pr) {
	int num = 0;
	add(num, 1ll * (pr - le + 1) * w[pr] % mod * o[le - 1] % mod);
	add(num, 1ll * (ja[pr] - ja[le - 1] + mod) * o[le - 1] % mod);
	add(num, 1ll * (-le + 1 + mod) * (pref[pr] - pref[le - 1] + mod) % mod * o[le - 1] % mod);
	int den = 0;
	add(den, 1ll * (pref[pr] - pref[le - 1] + mod) * o[le - 1] % mod);
	return 1ll * num * pt((1 - den + mod) % mod, mod - 2) % mod;
}
 
int main() {
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		p[i] = 1ll * a * pt(100, mod - 2) % mod;
	}
	
	s.insert(1);
	s.insert(n + 1);
	ak[1] = 1;
	ak[n + 1] = 1;
	
	w[0] = 1;
	o[0] = 1;
	for(int i = 1; i <= n; ++i) {
		w[i] = 1ll * w[i - 1] * p[i] % mod;
		o[i] = 1ll * o[i - 1] * pt(p[i], mod - 2) % mod;
		pref[i] = (pref[i - 1] + 1ll * w[i - 1] * ((1 - p[i] + mod) % mod)) % mod;
		ja[i] = (ja[i - 1] + 1ll * i * w[i - 1] % mod * ((1 - p[i] + mod) % mod)) % mod;
	}
	out = oblicz(1, n);
	while(q--) {
		scanf("%d", &a);
		ak[a] ^= 1;
		auto left = --s.lower_bound(a);
		auto right = s.upper_bound(a);
		
		add(out, (ak[a] ? 1 : -1) * oblicz(*left, a - 1));
		add(out, (ak[a] ? 1 : -1) * oblicz(a, *right - 1));
		add(out, (ak[a] ? -1 : 1) * oblicz(*left, *right - 1));
		
		if(ak[a])
			s.insert(a);
		else
			s.erase(a);
		
		printf("%d\n", out);
	}
	
	
	
	
	return 0;
}