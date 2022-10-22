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

const int pod = (1 << 19);
const int mod = 1e9 + 7;

int pt(int a, int b) {
	if(b == 0) return 1;
	if(b & 1) return 1ll * a * pt(a, b - 1) % mod;
	return pt(1ll * a * a % mod, b / 2) % mod;
}

int sito[311];
vector <int> pr;

int n, q;
int a, b;

int ilo[2 * pod];
int lazy[2 * pod];
int t[311][20];
int lo[2 * pod];

void push(int u, int lvl) {
	if(lazy[u] == 1) return;
	lazy[2 * u] = 1ll * lazy[2 * u] * lazy[u] % mod;
	lazy[2 * u + 1] = 1ll * lazy[2 * u + 1] * lazy[u] % mod;
	ilo[2 * u] = 1ll * ilo[2 * u] * pt(lazy[u], 1 << (lvl - 1)) % mod;
	ilo[2 * u + 1] = 1ll * ilo[2 * u + 1] * pt(lazy[u], 1 << (lvl - 1)) % mod;
	lazy[u] = 1;
}

void mul(int x, int y, int c, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		ilo[u] = 1ll * ilo[u] * t[c][lo[r - l + 1]] % mod;
		lazy[u] = 1ll * lazy[u] * c % mod;
		return;
	}
	push(u, lo[r - l + 1]);
	int m = (l + r) / 2;
	if(x <= m)
		mul(x, y, c, 2 * u, l, m);
	if(m < y)
		mul(x, y, c, 2 * u + 1, m + 1, r);
	ilo[u] = 1ll * ilo[2 * u] * ilo[2 * u + 1] % mod;
}

int que(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		return ilo[u];
	}
	push(u, lo[r - l + 1]);
	int m = (l + r) / 2;
	int res = 1;
	if(x <= m)
		res = que(x, y, 2 * u, l, m);
	if(m < y)
		res = 1ll * res * que(x, y, 2 * u + 1, m + 1, r) % mod;
	return res;
}
	
bitset <100> bit[2 * pod];
bitset <100> laz[2 * pod];
bitset <100> e;

void se(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		bit[u] = (bit[u] | e);
		laz[u] = (laz[u] | e);
		return;
	}
	bit[2 * u] |= laz[u];
	bit[2 * u + 1] |= laz[u];
	laz[2 * u] |= laz[u];
	laz[2 * u + 1] |= laz[u];
	
	int m = (l + r) / 2;
	if(x <= m)
		se(x, y, 2 * u, l, m);
	if(m < y)
		se(x, y, 2 * u + 1, m + 1, r);
	bit[u] = (bit[2 * u] | bit[2 * u + 1]);
}	

bitset<100> que2(int x, int y, int u = 1, int l = 0, int r = pod - 1) {
	if(x <= l && r <= y) {
		return bit[u];
	}
	bit[2 * u] |= laz[u];
	bit[2 * u + 1] |= laz[u];
	laz[2 * u] |= laz[u];
	laz[2 * u + 1] |= laz[u];
	
	int m = (l + r) / 2;
	bitset <100> res;
	if(x <= m)
		res = que2(x, y, 2 * u, l, m);
	if(m < y)
		res = (res | que2(x, y, 2 * u + 1, m + 1, r));
	return res;
}

void Cat(bitset<100> b) {
	cat("e\n");
	for(int i = 0; i <= 5; ++i)
		cout << b[i];
	cout << endl;
}

int odw[301];
			
int main() {
	for(int i = 2; i < 2 * pod; ++i)
		lo[i] = 1 + lo[i / 2];
	for(int i = 1; i <= 300; ++i)
		for(int j = 0; j <= 19; ++j)
			t[i][j] = pt(i, (1 << j));
	for(int i = 2; i <= 300; ++i) {
		if(sito[i] == 0) {
			pr.pb(i);
			for(int j = i + i; j <= 300; j += i)
				sito[j] = 1;
		}
		odw[i] = pt(i, mod - 2);
	}
	
	
	
	for(int i = 1; i < 2 * pod; ++i) {
		ilo[i] = 1;
		lazy[i] = 1;
	}
	
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; ++i) {
		scanf("%d", &a);
		mul(i, i, a);
		e.reset();
		for(int j = 0; j < ss(pr); ++j)  
			if(a % pr[j] == 0) 
				e[j] = 1;
		se(i, i);
	}
	
	for(int i = 1; i <= q; ++i) {
		char s[10];
		scanf("%s %d %d", s, &a, &b);
		if(s[0] == 'T') {
			int res = que(a, b);
			e.reset();
			e = que2(a, b);
			for(int j = 0; j < ss(pr); ++j) 
				if(e[j] == 1) {
					res = 1ll * res * (pr[j] - 1) % mod * odw[pr[j]] % mod;
					//cat(pr[j]);
				}
			printf("%d\n", res);		
		}
		else {
			int c;
			scanf("%d", &c);
			mul(a, b, c);
			e.reset();
			for(int j = 0; j < ss(pr); ++j) 
				if(c % pr[j] == 0) 
					e[j] = 1;
			se(a, b);
		}
	}
		
		
	
	
	
	
	return 0;
}