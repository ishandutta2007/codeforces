#include <bits/stdc++.h>
#define ef else if

using namespace std;

typedef long long _;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 4E5+8;

_ n, m, k, o[maxn], f[maxn], ac[maxn], p[maxn], s, c[maxn], r[maxn], l[maxn];
_p a[maxn], b[maxn];
struct rg {
	_ vl, dx;
	bool operator < (const rg &b) const {
		return vl > b.vl;
	}
};
priority_queue<rg> q;

_ find(_ x);
int main() {
	
	scanf("%lld%lld%lld", &n, &m, &k);
	for(_ i = 1; i <= n+m; ++i) {
		scanf("%lld", &a[i].first);
		if(i <= n) a[i].second = 1;
	}
	n += m;
	sort(a+1, a+1+n);
	for(_ i = 1; i <= k; ++i) {
		scanf("%lld", &b[i].first);
		b[i].second = i;
	}
	sort(b+1, b+1+k);
	for(_ i = 1; i <= n; ++i) {
		f[i] = r[i] = l[i] = i;
		ac[i] = a[i].second;
		p[i] = p[i-1]+a[i].first;
		if(i != 1) q.push((rg){a[i].first-a[i-1].first, i});
		if(a[i].second) {
			s += a[i].first;
			c[i] = a[i].first;
		}
	}
	for(_ i = 1; i <= k; ++i) {
		for(; !q.empty() && q.top().vl <= b[i].first; q.pop()) {
			_ x = find(q.top().dx-1), y = find(q.top().dx);
			s -= c[x];
			s -= c[y];
			f[x] = y;
			r[y] = max(r[y], r[x]);
			l[y] = min(l[y], l[x]);
			ac[y] += ac[x];
			s += c[y] = p[r[y]]-p[r[y]-ac[y]];
		}
		o[b[i].second] = s;
	}
	for(_ i = 1; i <= k; ++i) printf("%lld\n", o[i]);
	
	return 0;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}