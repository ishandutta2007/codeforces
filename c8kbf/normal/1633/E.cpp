

#include <bits/stdc++.h>
#define ef else if
#define mp(x, y) make_pair(x, y)

using namespace std;

typedef long long _;
typedef string str;
typedef pair<_, _> _p;
typedef const long long constant;

constant maxn = 3E5+8;

_ n, m, a[maxn], b[maxn], c[maxn], vl, f[maxn], x, p, k, ma, mb, mc, s;
struct ed {
	_ x, y, z;
	bool operator < (const ed &b) const {
		return abs(z-vl) < abs(b.z-vl);
	}
} e[maxn];
vector<_> g;

_ find(_ x);
int main() {

//	freopen("in.txt", "r", stdin);

	scanf("%lld%lld", &n, &m);
	for(_ i = 1; i <= m; ++i) scanf("%lld%lld%lld", &e[i].x, &e[i].y, &e[i].z);
	sort(e+1, e+1+m);
	g.push_back(0);
	for(_ i = 1; i <= m; ++i) g.push_back(e[i].z);
	for(_ i = 1; i <= m; ++i) for(_ j = i+1; j <= m; ++j) {
//		g.push_back((e[i].z+e[j].z+1)>>1);
		g.push_back((e[i].z+e[j].z+2)>>1);
//		g.push_back((e[i].z+e[j].z)>>1);
	}
	sort(g.begin(), g.end());
	g.erase(unique(g.begin(), g.end()), g.end());
	for(_ j = 0; j < (_)g.size(); ++j) {
		vl = g[j];
		sort(e+1, e+1+m);
		for(_ i = 1; i <= n; ++i) f[i] = i;
		for(_ i = 1; i <= m; ++i) if(find(e[i].x) != find(e[i].y)) {
			f[find(e[i].x)] = find(e[i].y);
			if(e[i].z <= vl) ++b[j];
			else ++c[j];
			a[j] += abs(e[i].z-vl);
		}
	}

	scanf("%lld%lld%lld%lld%lld", &p, &k, &ma, &mb, &mc);
	for(_ i = 1; i <= k; ++i) {
		if(i <= p) scanf("%lld", &x);
		else x = (x*ma+mb)%mc;
//		if(i <= 3) printf("%lld\n", x);
		_ dx = upper_bound(g.begin(), g.end(), x)-g.begin()-1;
//		printf("dx = %lld, g[dx] = %lld\n", dx, g[dx]);
		_ df = x-g[dx];
		s ^= a[dx]+df*(b[dx]-c[dx]);
	}
	printf("%lld\n", s);

	return 0;
}

_ find(_ x) {
	return f[x] == x ? x : f[x] = find(f[x]);
}