#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef const long long constant;

constant maxn = 1E5+8;
struct qr {
	_ x, y, z;
} a[maxn];
_ n, m, t[maxn<<2], o[maxn], p[maxn<<2];

_ query(_ L, _ R, _ l, _ r, _ pos);
void build(_ l, _ r, _ pos);
void pushUp(_ pos);
void retr(_ l, _ r, _ pos);
void update(_ L, _ R, _ l, _ r, _ pos, _ c);
int main() {
	
	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= m; ++i) {
		scanf("%lld%lld%lld", &a[i].x, &a[i].y, &a[i].z);
		update(a[i].x, a[i].y, 1, n, 1, a[i].z);
	}
	retr(1, n, 1);
	build(1, n, 1);
	for(_ i = 1; i <= m; ++i) if(query(a[i].x, a[i].y, 1, n, 1) != a[i].z) {
		puts("NO");
		exit(0);
	}
	puts("YES");
	for(_ i = 1; i <= n; ++i) printf("%lld ", o[i]);
	putchar(10);
	
	return 0;
}

void update(_ L, _ R, _ l, _ r, _ pos, _ c) {
	if(L <= l && r <= R) {
		t[pos] |= c;
		return;
	}
	_ md = (l+r)>>1;
	if(L <= md) update(L, R, l, md, pos<<1, c);
	if(R > md) update(L, R, md+1, r, pos<<1|1, c);
	return;
}

void retr(_ l, _ r, _ pos) {
	if(l == r)  {
		o[l] = t[pos];
		return;
	}
	t[pos<<1] |= t[pos];
	t[pos<<1|1] |= t[pos];
	_ md = (l+r)>>1;
	retr(l, md, pos<<1);
	retr(md+1, r, pos<<1|1);
	return;
}

void pushUp(_ pos) {
	p[pos] = p[pos<<1] & p[pos<<1|1];
	return;
}

void build(_ l, _ r, _ pos) {
	if(l == r) {
		p[pos] = o[l];
		return;
	}
	_ md = (l+r)>>1;
	build(l, md, pos<<1);
	build(md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

_ query(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) return p[pos];
	_ md = (l+r)>>1;
	if(L <= md && R > md) return query(L, R, l, md, pos<<1) & query(L, R, md+1, r, pos<<1|1);
	ef(L <= md) return query(L, R, l, md, pos<<1);
	else return query(L, R, md+1, r, pos<<1|1);
}