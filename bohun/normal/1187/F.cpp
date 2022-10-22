#include <bits/stdc++.h>
#define ll long long
#define mp make_pair
#define pb push_back
#define ld long double
#define ss(x) (int) x.size()
#define FOR(i, n) for(int i = 1; i <= n; ++i) 
#define fi first
#define se second
#define cat(x) cerr << #x << " " << x << endl;


using namespace std;

const int nax = 200005, mod = 1e9 + 7;

int n;
int l[nax], r[nax];
int dl[nax];
int p[nax];
int pref[nax];
int dou[nax];

int daj(int x, int y) {
	int R = min(r[x], r[y]);
	int L = max(l[x], l[y]);
	return max(0, R - L + 1);
}

int daj(int x, int y, int z) {
	int R = min({r[x], r[y], r[z]});
	int L = max({l[x], l[y], l[z]});
	return max(0, R - L + 1);
}

int pt(int a, int b) {
	int res = 1;
	while(b) {
		if(b & 1)
			res = (ll) res * a % mod;
		a = (ll) a * a % mod;
		b /= 2;
	}
	return res;
}

int ha(int x) {
	int res = (ll) pref[n] * pt(dou[x], mod - 2) % mod;
	return res;
} 
int sum = 0;

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

int main() {
	cin >> n;
	for(int i = 1; i <= n; ++i) {
		cin >> l[i];
	}
	for(int i = 1; i <= n; ++i) {
		cin >> r[i];
	}
	for(int i = 1; i <= n; ++i) {
		dl[i] = r[i] - l[i] + 1;
	}
	
	dl[0] = pref[0] = 1;
	for(int i = 1; i <= n; ++i) {
		p[i] = (((ll) dl[i] * dl[i - 1] - daj(i, i - 1)) % mod + mod) % mod;
		pref[i] = (ll) pref[i - 1] * dl[i] % mod;
		dou[i] = (ll) dl[i] * dl[i - 1] % mod;
	}
	
	int Q = 1;
	for(int i = 1; i <= n; ++i) {
		Q = (ll) Q * dl[i] % mod;
		
	}
	Q = pt(Q, mod - 2);
	int P = 0;
	// 1. 
	for(int i = 1; i <= n; ++i) {
		P = (P + (ll) p[i] * ha(i)) % mod;
	}
	// 2.  
	P = (P + (ll) 2 * p[2] * ha(2)) % mod;
	for(int i = 3; i <= n; ++i) {
		ll val = pref[n];
		val = (val - (ll) daj(i, i - 1) * pref[n] % mod * pt(dou[i], mod - 2) % mod + mod) % mod; 
		val = (val - (ll) daj(i - 2, i - 1) * pref[n] % mod * pt(dou[i - 1], mod - 2) % mod + mod) % mod;
		val = (val + (ll) daj(i, i - 1, i - 2) * pref[n] % mod * pt(dl[i], mod - 2) % mod * pt(dl[i - 1], mod - 2) % mod * pt(dl[i - 2], mod - 2) % mod + mod) % mod;
		add(P, 2 * val % mod);
	}
	// 3.
	sum = 0;
	for(int i = 1; i <= n; ++i) {
		sum = (sum + (ll) p[i] * pt(dou[i], mod - 2) % mod) % mod;
	}
	for(int i = 1; i <= n; ++i) {
		ll X = (ll) p[i] * pref[n] % mod * pt(dou[i], mod - 2) % mod;
		P = (P + (ll) X * sum) % mod;
	}
	for(int i = 1; i <= n; ++i) {
		sub(P, (ll) p[i] * p[i] % mod * pref[n] % mod * pt(dou[i], mod - 2) % mod * pt(dou[i], mod - 2) % mod);
	}
	for(int i = 1; i < n; ++i) {
		sub(P, (ll) 2 * p[i] % mod * p[i + 1] % mod * pref[n] % mod * pt(dou[i], mod - 2) % mod * pt(dou[i + 1], mod - 2) % mod);
	}
	P = (ll) P * Q % mod;
	cout << P;
	
		
	return 0;
}