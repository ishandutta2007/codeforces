#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef vector<_> v_;
typedef pair<_, _> _p;
typedef string str;
typedef const long long constant;

constant maxn = 6E6+8;
constant maxlg = 30;

_ tc, l, r, n, a[maxn], bt[maxn], nd[maxn], cnt, s, t[maxn][2], o;
v_ g;

_ getMx(_ x);
_ getMn(_ x);
void dfs(_ x, _ c);
int main() {

	memset(t, ~0, sizeof t);

	scanf("%lld", &tc);
	for(; tc--; ) {
		g.clear();
		for(_ i = 1; i <= cnt; ++i) t[i][0] = t[i][1] = -1;
		cnt = 1;
		scanf("%lld%lld", &l, &r);
		n = r-l+1;
		for(_ i = 1; i <= n; ++i) {
			scanf("%lld", &a[i]);
			_ p = 1;
			for(_ j = 1<<16, k = 17; k >= 1; --k, j >>= 1) {
				_ c = !!(a[i]&j);
				if(!~t[p][c]) t[p][c] = ++cnt;
				p = t[p][c];
			}
		}
//		s = 0;
//		for(_ i = 1<<16, j = 17; j >= 1; --j, i >>= 1) {
//			printf("j = %lld, bt[j] = %lld, nd[j] = %lld\n", j, bt[j], nd[j]);
//				bool ok = true;
//				for(_ k = 1; k <= n; ++k) if((a[k]^s^i) < l|| (a[k]^s^i) > r) ok = false;
//				if(ok) s ^= i;
//				g.push_back(i);
//		}
//		dfs(0, s);
		for(_ i = 1; i <= n; ++i) {
			_ tr = a[i]^l;
			if(getMn(tr) == l && getMx(tr) == r) {
				o = tr;
//				printf("%lld is ok\n", o);
			}
		}
		printf("%lld\n", o);
	}

	return 0;
}

//void dfs(_ x, _ c) {
//	if(x == (_)g.size()) {
//		printf("trying c = %lld, mn = %lld, mx = %lld\n", c, getMn(c), getMx(c));
//		if(getMn(c) == l && getMx(c) == r) o = c;
//		return;
//	}
//	dfs(x+1, c);
//	dfs(x+1, c^g[x]);
//	return;
//}

_ getMn(_ x) {
//	printf("getting min of %lld\n", x);
	_ p = 1, s = 0;
	for(_ i = 1<<16, j = 17; j >= 1; --j, i >>= 1) {
//		printf("j = %lld, p = %lld\n", j, p);
		_ c = !!(x&i);
		if(!~t[p][c]) {
			s ^= i;
			p = t[p][c^1];
		} else p = t[p][c];
	}
	return s;
}

_ getMx(_ x) {
//	printf("getting mx = %lld\n", x);
	_ p = 1, s = 0;
	for(_ i = 1<<16, j = 17; j >= 1; --j, i >>= 1) {
//		printf("j = %lld, p = %lld, t[p][0] = %lld, t[p][1] = %lld\n", j, p, t[p][0], t[p][1]);
		_ c = !(x&i);
		if(!~t[p][c]) p = t[p][c^1];
		else {
			s ^= i;
			p = t[p][c];
		}
	}
	return s;
}