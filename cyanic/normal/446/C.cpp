#include<bits/stdc++.h>
#define lc (o << 1)
#define rc (o << 1 | 1)
#define mid ((l+r) >> 1)
using namespace std;

const int maxn = 300009;
const int MOD = 1000000009;
const int base = 276601605;
const int q1 = 691504013;
const int q2 = 308495997;
int pow1[maxn], pow2[maxn], T[maxn<<2], lazy1[maxn<<2], lazy2[maxn];
int n, m, a, b, c, s[maxn];

void calc(int o, int l, int r, int a, int b){
	T[o] = ((T[o] + 1LL*a*(pow1[r-l+3]-pow1[2]) - 1LL*b*(pow2[r-l+3]-pow2[2]))%MOD+MOD)%MOD;
	lazy1[o] = (lazy1[o] + a) % MOD; lazy2[o] = (lazy2[o] + b) % MOD;
}

void pushdown(int o, int l, int r, int &a, int &b){
	calc(lc, l, mid, a, b);
	calc(rc, mid+1, r, 1LL*a*pow1[mid-l+1]%MOD, 1LL*b*pow2[mid-l+1]%MOD);
	a = b = 0;
}

void update(int o, int l, int r, int x, int y, int a, int b){
	if (l == x && y == r){ calc(o, l, r, a, b); return; }
	pushdown(o, l, r, lazy1[o], lazy2[o]);
	if (y <= mid) update(lc, l, mid, x, y, a, b);
	else if (mid+1 <= x) update(rc, mid+1, r, x, y, a, b);
	else{
		update(lc, l, mid, x, mid, a, b);
		update(rc, mid+1, r, mid+1, y, 1LL*a*pow1[mid-x+1]%MOD, 1LL*b*pow2[mid-x+1]%MOD);
	}
	T[o] = (T[lc] + T[rc]) % MOD;
}

int query(int o, int l, int r, int x, int y){
	if (l == x && y == r) return T[o];
	pushdown(o, l, r, lazy1[o], lazy2[o]);
	if (y <= mid) return query(lc, l, mid, x, y);
	if (mid+1 <= x) return query(rc, mid+1, r, x, y);
	return (query(lc, l, mid, x, mid) + query(rc, mid+1, r, mid+1, y)) % MOD;
}

int main(){
	scanf("%d%d", &n, &m);
	for (int i=1; i<=n; i++){
		scanf("%d", &a); s[i] = (s[i-1] + a) % MOD;
	}
	pow1[0] = 1;
	for (int i=1; i<maxn; i++) pow1[i] = 1LL*pow1[i-1]*q1%MOD;
	pow2[0] = 1;
	for (int i=1; i<maxn; i++) pow2[i] = 1LL*pow2[i-1]*q2%MOD;
	while (m--){
		scanf("%d%d%d", &c, &a, &b);
		if (c == 1) update(1, 1, n, a, b, 1, 1);
		else printf("%d\n", (((s[b]-s[a-1])%MOD + 1LL*base*query(1, 1, n, a, b))%MOD+MOD)%MOD);
	}
	return 0;
}

/*
na[]
1, l, rl<=i<=r,a[i]] += f[i-l+1]
2, l, ra[i](l<=i<=r)
n,m<=300000
f[i]f[1]=1,f[2]=1

sqrt(5)=383008016
sqrt(5)/5=276601605
(1+sqrt(5))/2=691504013
(1-sqrt(5))/2=308495997

q-1q

q(q^n-1)/(q-1)
=q^2(q^n-1)
=q^(n+2)-q^2
*/