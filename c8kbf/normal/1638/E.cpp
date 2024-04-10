#include <bits/stdc++.h>
#define mp make_pair
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 1E6+8;

_ n, m, t[maxn<<2], cl[maxn], x, y, c;
struct pr {
	_ x, y, c;
	bool operator < (const pr &b) const {
		return x < b.x;
	}
};
set<pr> st;
char in[18];

void split(_ x);
_ query(_ l, _ r, _ c, _ pos);
void update(_ L, _ R, _ l, _ r, _ c, _ pos);
int main() {

	scanf("%lld%lld", &n, &m);
	st.insert((pr){0, 0, -1});
	st.insert((pr){n+1, n+1, -1});
	st.insert((pr){1, n, 1});
	for(; m--; ) {
		scanf(" %s%lld", in+1, &x);
		if(in[1] == 'A') {
			scanf("%lld", &y);
			cl[x] += y;
		} ef(in[1] == 'C') {
			scanf("%lld%lld", &y, &c);
			split(x);
			split(y+1);
//			printf("in st:\n");
//			for(pr i : st) printf("range from %lld to %lld has color %lld\n", i.x, i.y, i.c);
			for(set<pr>::iterator it = st.lower_bound((pr){x, -1, -1}); it -> y <= y; it = st.lower_bound((pr){x, -1, -1})) {
				update(it-> x, it -> y, 1, n, cl[it -> c], 1);
				st.erase(it);
			}
			update(x, y, 1, n, -cl[c], 1);
			st.insert((pr){x, y, c});
//			printf("in st:\n");
//			for(pr i : st) printf("range from %lld to %lld has color %lld\n", i.x, i.y, i.c);
		} else {
			set<pr>::iterator it = st.upper_bound((pr){x, -1, -1});
			--it;
			_ r = it -> c;
//			printf("the color of %lld is %lld\n", x, r);
			printf("%lld\n", cl[r]+query(1, n, x, 1));
		}
	}

	return 0;
}

void pushDown(_ pos) {
	t[pos<<1] += t[pos];
	t[pos<<1|1] += t[pos];
	t[pos] = 0;
	return;
}

void update(_ L, _ R, _ l, _ r, _ c, _ pos) {
	if(L <= l && r <= R) {
		t[pos] += c;
		return;
	}
	_ md = (l+r)>>1;
	if(L <= md) update(L, R, l, md, c, pos<<1);
	if(R > md) update(L, R, md+1, r, c, pos<<1|1);
	return;
}

_ query(_ l, _ r, _ c, _ pos) {
	if(l == r) return t[pos];
	_ md = (l+r)>>1;
	pushDown(pos);
	if(c <= md) return query(l, md, c, pos<<1);
	else return query(md+1, r, c, pos<<1|1);
}

void split(_ x) {
	set<pr>::iterator it = st.upper_bound((pr){x, -1, -1});
	--it;
	if(it -> x == x) return;
	pr sv = *it;
	st.erase(it);
	st.insert((pr){sv.x, x-1, sv.c});
	st.insert((pr){x, sv.y, sv.c});
	return;
}
/*
1000000 6
Color 268945 569540 878605
Color 285855 776838 458049
Add 458049 -18986837
Color 22991 787001 401204
Add 401204 474128753
Query 435006
*/