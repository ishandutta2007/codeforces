#include<bits/stdc++.h>
#define fo(i, x, y) for(int i = x, _b = y; i <= _b; i ++)
#define ff(i, x, y) for(int i = x, _b = y; i <  _b; i ++)
#define fd(i, x, y) for(int i = x, _b = y; i >= _b; i --)
#define ll long long
#define pp printf
#define hh pp("\n")
using namespace std;

const int N = 1e6 + 5;

char s[N], t[N];
int n;

void Init() {
	scanf("%s", t + 1);
	n = strlen(t + 1);
	int l = 1, r = n;
	int s0 = 0;
	while(l <= r) {
		s[++ s0] = t[l ++];
		if(l <= r) s[++ s0] = t[r --];
	}
}

const int mo = 1e9 + 7;

ll f[N];

struct hwt {
	int n;
	int son[N][26], fa[N], len[N], tot, la;
	
	int dta[N], to[N];
	
	ll g[N];
	
	void build() {
		tot = 1; la = 0;
		fa[0] = fa[1] = 1;
		len[0] = 0; len[1] = -1;
		s[0] = -1;
	}
	
	int gf(int x) {
		while(s[n - len[x] - 1] != s[n]) x = fa[x];
		return x;
	}
	
	void add(int c) {
		n ++;
		int p = gf(la);
		if(!son[p][c]) {
			int q = ++ tot;
			len[q] = len[p] + 2;
			fa[q] = son[gf(fa[p])][c];
			son[p][c] = q;
			dta[q] = len[q] - len[fa[q]];
			to[q] = (dta[q] == dta[fa[q]] ? to[fa[q]] : fa[q]);
		}
		p = son[p][c];
		la = p;
		
		for(int x = la; x; x = to[x]) {
			g[x] = f[n - len[to[x]] - dta[x]];
			if(to[x] != fa[x]) g[x] = (g[x] + g[fa[x]]) % mo;
		}
	}
	
	ll calc() {
		ll ans = 0;
		for(int x = la; x; x = to[x]) {
			ans = (ans + g[x]) % mo;
		}
		return ans;
	}
	
} suf;

int main() {
	Init();
//	fo(i, 1, n) pp("%c", s[i]); hh;
	suf.build();
	f[0] = 1;
	fo(i, 1, n) {
		suf.add(s[i] - 'a');
		f[i] = suf.calc();
		if(i & 1) f[i] = 0;
	}
	pp("%lld\n", f[n]);
}