#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y);

using namespace std;

typedef long long _;
typedef string str;
typedef long double _D;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E5+8;

_ n, m, k, x, y, l, a[maxn];
deque<_> q[maxn];
v_ t[maxn<<2];

_ query(_ L, _ R, _ l, _ r, _ pos);
void build(_ l, _ r, _ pos);
int main() {

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= n; ++i) {
		scanf("%lld", &x);
		if((_)q[x].size() == m) {
			a[i] = q[x].front();
			q[x].pop_front();
		} else a[i] = -1;
		q[x].push_back(i);
	}
	build(1, n, 1);
	scanf("%lld", &k);
	for(; k--; ) {
		scanf("%lld%lld", &x, &y);
		x = (x+l)%n+1;
		y = (y+l)%n+1;
		if(x > y) swap(x, y);
//		printf("actual query is {%lld, %lld}\n", x, y);
		l = query(x, y, 1, n, 1);
		printf("%lld\n", l);
	}

	return 0;
}

void pushUp(_ pos) {
	for(_ i : t[pos<<1]) t[pos].push_back(i);
	for(_ i : t[pos<<1|1]) t[pos].push_back(i);
	sort(t[pos].begin(), t[pos].end());
	return;
}

void build(_ l, _ r, _ pos) {
	if(l == r) {
		t[pos].push_back(a[l]);
		return;
	}
	_ md = (l+r)>>1;
	build(l, md, pos<<1);
	build(md+1, r, pos<<1|1);
	pushUp(pos);
	return;
}

_ query(_ L, _ R, _ l, _ r, _ pos) {
	if(L <= l && r <= R) {
//		printf("returning direct query at {L, R} = {%lld, %lld} and {l, r} = {%lld, %lld}\n", L, R, l, r);
//		printf("contents of t[%lld]: ", pos);
//		for(_ i : t[pos]) printf("%lld ", i);
//		putchar(10);
		return lower_bound(t[pos].begin(), t[pos].end(), L)-t[pos].begin();
	}
	_ md = (l+r)>>1, rv = 0;
	if(L <= md) rv += query(L, R, l, md, pos<<1);
	if(R > md) rv += query(L, R, md+1, r, pos<<1|1);
	return rv;
}